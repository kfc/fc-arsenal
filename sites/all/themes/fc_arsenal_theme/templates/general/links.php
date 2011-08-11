<?php
//new!
	function get_links() {

//		global $LFM;
	$LFM['code'] = "yXJ43gB4t"; // Произвольный набор символов, НЕ МЕНЯТЬ!
	$LFM['hash'] = "d0b88fae133f14b23b841374c0a46c9e"; // Выполняет роль пароля. НЕ МЕНЯТЬ!
	$LFM['cl'] = "add"; // класс ссылок, который будет вставлен. В данном случае будет <a href=some_url class=add>text</a>
	$LFM['delimiter'] = " | "; // Символ, которым будут разделяться разные ссылки. В данном случае будет <a href=some_url class=add>text</a> | <a href=some_url class=add>text</a> | <a href=some_url class=add>text</a> и т.д.
  $LFM['temp_dir'] = "/tmp"; // Каталог для хранения временных файлов.
  $LFM['encoding'] = "u"; // Кодировка сайта. w - windows-1251; u - UTF-8; k - KOI-8

		$url_file = "urls";

		if (is_readable($LFM['temp_dir']."/".$url_file) && (time()-filemtime($LFM['temp_dir']."/".$url_file))<5400) {
			$urls = unserialize(file_get_contents($LFM['temp_dir']."/".$url_file));
		} else {
			$urls_str = file_get_contents("http://i-reklama.net/pages.php?code=".$LFM['code']."&hash=".$LFM['hash']);

			if ($urls_str) {
				
				if ($fp = @fopen($LFM['temp_dir']."/".$url_file, "wb")) {
					fputs($fp, $urls_str);
					fclose($fp);
				}

				$urls = unserialize($urls_str);
			} else {
				$urls = unserialize(@file_get_contents($LFM['temp_dir']."/".$url_file));
			}
		}
		
		$this_url = $_SERVER['REQUEST_URI'];

		if (in_array($this_url, $urls, 1)) {

			$code_file = "code_".md5($this_url);

			if (is_readable($LFM['temp_dir']."/".$code_file) && (time()-filemtime($LFM['temp_dir']."/".$code_file))<5400) {
				$codes = file_get_contents($LFM['temp_dir']."/".$code_file);
			} else {
				$codes = base64_decode(file_get_contents("http://i-reklama.net/links.php?code=".$LFM['code']."&hash=".$LFM['hash']."&link=". rawurlencode($this_url)."&class=".$LFM['cl']."&delimiter=".rawurlencode($LFM['delimiter'])."&encoding=".rawurlencode($LFM['encoding'])));

				if ($codes) {
					if ($fp = @fopen($LFM['temp_dir']."/".$code_file, "wb")) {
						fputs($fp, $codes);
						fclose($fp);
					}
				} else {
					$codes = @file_get_contents($LFM['temp_dir']."/".$code_file);
				}
			}
		} elseif ($urls[':throughs:']) {

			$code_file = "codes_".md5($LFM['code']);

			if (is_readable($LFM['temp_dir']."/".$code_file) && (time()-filemtime($LFM['temp_dir']."/".$code_file))<5400) {
				$codes = file_get_contents($LFM['temp_dir']."/".$code_file);
			} else {
				$codes = base64_decode(file_get_contents("http://i-reklama.net/throught_links.php?code=".$LFM['code']."&hash=".$LFM['hash']."&class=".$LFM['cl']."&delimiter=".rawurlencode($LFM['delimiter'])."&encoding=".rawurlencode($LFM['encoding'])));

				if ($codes) {
					if ($fp = @fopen($LFM['temp_dir']."/".$code_file, "wb")) {
						fputs($fp, $codes);
						fclose($fp);
					}
				} else {
					$codes = @file_get_contents($LFM['temp_dir']."/".$code_file);
				}
			}
		}

		if ($urls[':default_code:']) {
			$codes .= $urls[':default_code:'];
		}
		
		return $codes;
	}
?>