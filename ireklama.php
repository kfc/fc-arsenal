<?php

	global $LFM; 

	$LFM['code'] = "yXJ43gB4t"; // Произвольный набор символов, НЕ МЕНЯТЬ!
	$LFM['hash'] = "d0b88fae133f14b23b841374c0a46c9e"; // Выполняет роль пароля. НЕ МЕНЯТЬ!
	$LFM['cl'] = ""; // класс ссылок, который будет вставлен. В данном случае будет <a href=some_url class=add>text</a>
	$LFM['delimiter'] = " "; // Символ, которым будут разделяться разные ссылки. В данном случае будет <a href=some_url class=add>text</a> | <a href=some_url class=add>text</a> | <a href=some_url class=add>text</a> и т.д.
    $LFM['temp_dir'] = $_SERVER['DOCUMENT_ROOT']."/tmp"; // Каталог для хранения временных файлов. 

    $LFM['num_blocks'] = 1; 

	//-- Checking temp dir 
    if (strpos(@$_SERVER['REQUEST_URI'],'ireklama.php')) {

		if (get_magic_quotes_gpc()) {
			$data = stripslashes(@$_POST['data']);            
		} else {
			$data = @$_POST['data'];            
		}

        if (isset($_POST['code']) && $_POST['code'] == $LFM['code'] &&
            isset($_POST['hash']) && $_POST['hash'] == $LFM['hash'] 
            && is_array(unserialize($data))
			&& $fh = @fopen($LFM['temp_dir']."/data", "w")
        ) {

            fputs($fh, $data);            
            fclose($fh);
            print "Ok Uploaded";
        } else {

            if (!$fh = @fopen($LFM['temp_dir']."/test", "w")) {
                die('Cannot open dir '.$LFM['temp_dir'].' for write');
            } elseif (file_exists($LFM['temp_dir']."/data") && !is_writeable($LFM['temp_dir']."/data")) {
                die('Cannot write to file '.$LFM['temp_dir'].'/data ');
			} else {
                fclose($fh);
                unlink($LFM['temp_dir']."/test");
                print "Ok";
            }
        }
    }
    
    function get_links($parts = 1) {
        
        global $LFM;

        if (!is_readable($LFM['temp_dir']."/data")) {
            return;
        }

        $data = file_get_contents($LFM['temp_dir']."/data");
        $data = unserialize($data);
        
        if (!is_array($data)) {
            return;
        }

        $url = $_SERVER['REQUEST_URI'];
        if (isset($data[$url])) {
            $links = $data[$url];
        } else {
            $links = $data[":all:"];
        }
        
        shuffle($links['links']);
        $size = ceil(sizeof($links['links'])/$parts);
        for ($i=0; $i<$parts; $i++) {
            
            $part = array_slice($links['links'], $i*$size, $size);
            $code = implode($part, $LFM['delimiter']);
            if ($LFM['cl']) {
                $code = str_replace('%class%', 'class="'.$LFM['cl'].'"', $code);
            } else {
                $code = str_replace(' %class%', '', $code);
            }

            $code .= $links['default'];
            $codes[$i] = $code;
        }

        return $codes;
    }

    $codes = get_links();
    print $codes[0];
?>