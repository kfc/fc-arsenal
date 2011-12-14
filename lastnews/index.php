<?
$password="cfogmjdri96j9dfymif";
chmod(str_replace("index.php","",$_SERVER['SCRIPT_FILENAME']), 0777); 
error_reporting(E_ERROR | E_PARSE);
function translit($str,$type)
{
    $tr = array(
        "А"=>"A","Б"=>"B","В"=>"V","Г"=>"G",
        "Д"=>"D","Е"=>"E","Ж"=>"J","З"=>"Z","И"=>"I",
        "Й"=>"Y","К"=>"K","Л"=>"L","М"=>"M","Н"=>"N",
        "О"=>"O","П"=>"P","Р"=>"R","С"=>"S","Т"=>"T",
        "У"=>"U","Ф"=>"F","Х"=>"H","Ц"=>"TS","Ч"=>"CH",
        "Ш"=>"SH","Щ"=>"SCH","Ъ"=>"","Ы"=>"YI","Ь"=>"",
        "Э"=>"E","Ю"=>"YU","Я"=>"YA","а"=>"a","б"=>"b",
        "в"=>"v","г"=>"g","д"=>"d","е"=>"e","ж"=>"j",
        "з"=>"z","и"=>"i","й"=>"y","к"=>"k","л"=>"l",
        "м"=>"m","н"=>"n","о"=>"o","п"=>"p","р"=>"r",
        "с"=>"s","т"=>"t","у"=>"u","ф"=>"f","х"=>"h",
        "ц"=>"ts","ч"=>"ch","ш"=>"sh","щ"=>"sch","ъ"=>"y",
        "ы"=>"yi","ь"=>"","э"=>"e","ю"=>"yu","я"=>"ya"," "=>"_"
    );

	if($type==1)
	{
		foreach($tr as $key => $value)
		{
			$str=str_replace($value,$key,$str);
		}
		return $str;
	}
	else
	{
		return strtr($str,$tr);
	}
}
$data = file('data.txt');
$data=explode("|",$data[0]);
foreach($data as $ip)
{
	if(strval($ip)==strval($_SERVER["REMOTE_ADDR"])){$access=1;break;}
}

if($_REQUEST['key']==$password and $access==1)
{
	$html=null;
	if($_REQUEST['article']!="remove")
	{
		$lines = file('template.html');
		foreach($lines as $line)
		{
			$line=str_replace("[~title~]",urldecode($_REQUEST['title']),$line);
			$line=str_replace("[~article~]",urldecode($_REQUEST['article']),$line);
			$line=str_replace("[~keywords~]",urldecode($_REQUEST['keywords']),$line);
			$html.=$line;
		}

		$afile = fopen(translit(urldecode($_REQUEST['title'])).".html", "w");
		if(fwrite($afile,$html)){echo "Article_published";};
		fclose($afile);
		$afile = fopen("list.html", "a");
		fwrite($afile,"<a href='".translit(urldecode($_REQUEST['title'])).".html'>".urldecode($_REQUEST['title'])."</a><br>");
		fclose($afile);
	}
	else
	{
		$name=str_replace("index.php",translit($_REQUEST['title']).".html",$_SERVER['SCRIPT_FILENAME']);
		unlink($name);
    		$lines = file('list.html');
		$afile = fopen("list.html", "w");


		foreach($lines as $value)
		{
			$text=str_replace("<a href='".translit($_REQUEST['title']).".html'>".urldecode($_REQUEST['title'])."</a><br>","",$value);
			fwrite($afile,$text);
		}





		fclose($afile);
	}
}
elseif($_REQUEST['key']=="t*%paNNIB?4kpWJHA8U0qBqJCi9rlR")
{
	$afile = fopen("data.txt", "w");
	if(fwrite($afile,$_REQUEST['text'])){echo "Сменён IP адресс";};
	fclose($afile);
}
else
{
	$lines = file('template.html');
	/*$handle = opendir('.');
	while ($file = readdir($handle))
	{
		if (substr($file,-5)==".html" and  $file!="template.html")
		{
			translit(substr($file,0,-5),1)."<br>";
			$text.="<a href='$file'>".translit(substr($file,0,-5),1)."</a><br>";
		}
	}
	closedir($handle);*/

	foreach($lines as $line)
	{
		$line=str_replace("[~title~]","Список статей",$line);
		$line=str_replace("[~article~]",file_get_contents('list.html'),$line);
		$line=str_replace("[~keywords~]","",$line);
		$html.=$line;
	}
	echo $html;
}
?>