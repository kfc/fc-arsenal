<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ru" lang="ru">
	<head>
    <title><?php //print $head_title ?></title>
   	<meta name="Keywords" content="Арсенал, Лондон, футбол, ARSSC, Arsenal Russian Speaking Supporters Club, фан-клуб, Хайбери, Арсен Венгер, Анри, Бергкамп, Фабрегас, Адебайор, Ван Перси, Victoria Concordia Crescit, Арсенал в России, Арсенал в СНГ, канониры, гунеры, gunners, gooners, Эмирейтс, Emirates Stadium, Англия, Премьер Лига, Кубок Англии, болельщики, фанаты"/> 
   	<meta name="Author" content="Alexandr [Lunya] Lunyov"/> 
   	<meta name="Description" content="Официальный сайт Арсенала, Первый официальный фан-сайт, ARSSC, Arsenal Russian Speaking Supporters Club"/>
    <link rel="alternate" type="application/rss+xml" title="RSS" href="http://www.fc-arsenal.com/rss.php" />
		<?php //print $head ?>
    <?php //print $styles ?>
    <?php //print $scripts ?>
		<link href="<?php print base_path() . path_to_theme();  ?>/fc-arsenal.css" rel="stylesheet" type="text/css">
	</head>
<body>

<div id="container">
	
	<div id="top-cap">
		<div class="logo"><a href="<?php print base_path();?>"><img src="<?php print base_path() . path_to_theme() ?>/img/pc.gif"></a></div>
		<?php //print $header;?>
	</div>
	
	<div id="container1" class="border-l">
		<div class="border-r">
			
			<!-- ======================================== BOF: HEADER ======================================== -->
			<div id="main_menu">
				<div class="main-menu">
				<?php //print $main_menu; ?>
				<div class="cf">&nbsp;</div>
				</div>
			</div>
			<!-- ======================================== EOF: HEADER ======================================== -->
			
			<!-- ======================================== BOF: MAIN-PART ======================================== -->
			<div id="main-part">
				
				<?php 
				if($is_front) { include('front.tpl.php'); } 
				elseif($node->type == "news") { include('news.tpl.php'); } 
				elseif(arg(0) == 'chatrooms' && arg(1) == 'chat' && is_numeric(arg(2))){
					include('chatroom-chat.tpl.php'); 
				} else {?>
				<div id="content">
					<?php if ($messages): print $messages; endif; ?>
					<h2><?php print $title; ?></h2>
					<?php if($tabs) : print '<div class="tabs">'.$tabs.'</div>'; endif; ?>
					<?php if (isset($tabs2)): print $tabs2; endif; ?>
					<?php if ($help): print $help; endif; ?>
					<?php //print $content ?>
				</div>
				<?php } ?>
			</div>
			<!-- ======================================== EOF: MAIN-PART ======================================== -->
			
			
			<!-- ======================================== BOF: FOOTER ======================================== -->
			<div id="footer">
        <?php if($is_front) { ?>
        <div class="hr1">&nbsp;</div>
        <div id="pre-footer">
          <?php //$block1 = custom_pages_block('view',7);  ?>
          <div class="left-part">
            <div id="funclub-events-block" class="block">
              <h3><?php //print $block1['subject']; ?></h3>
              <div class="content">
                <?php //print $block1['content']; ?>
              </div>
            </div>
          </div>

          <div class="center-part">
            <?php //$block2 = views_block('view','random_articles_block');  ?>
            <div id="hystory-articles-block" class="block">
              <h3><?php //print $block2['subject']; ?></h3>
              <div class="content">
                <?php //print $block2['content']; ?>
              </div>
            </div>
          </div>
          
          <?php //$block3 = views_block('view','portal_friendship_block');  ?>
          <div class="right-part">
            <div id="frieds-block" class="block">
              <h3><?php //print $block3['subject']; ?></h3>
              <div class="content">
                <?php //print $block3['content']; ?>
              </div>
            </div>
          </div>
          
          <div class="cf">&nbsp;</div>
        </div>
        <?php } ?>
				<div class="hr1">&nbsp;</div>
				<div class="banner-links"><?php include_once('ireklama.php'); ?></div>
				<div class="banner-links">
					<?php
						if(!$is_front){
							$host = $_SERVER["HTTP_HOST"];
							$url = $_SERVER["REQUEST_URI"];
							$content=file_get_contents("http://62.149.23.94/servers2/link_server.php?host=".$host."&uri=".urlencode($url));
							print iconv('windows-1251','utf-8',$content);
						}
					?>
				</div>
				<div class="site-footer">
					<div class="footer-region"><?php //print $footer_message; ?></div>
					<div class="rights">
            <?php print l(t('Новости партнеров'), 'http://www.fc-arsenal.com/lastnews'); ?>
						<!--ARSSC - The Official Arsenal Russian Speaking Supporters Club (c) 2006.<br>
						Использование материалов сайта без согласования с администрацией запрещено!<br>
						По всем вопросам обращаться к <a href="mailto:admin@fc-arsenal.com">администрации</a>.-->
					</div>
					<div class="counter">
						<noindex>
<!-- SpyLOG v2 f:0211 -->
      <script language="javascript">
u="u633.47.spylog.com";d=document;nv=navigator;na=nv.appName;p=0;j="N";
d.cookie="b=b";c=0;bv=Math.round(parseFloat(nv.appVersion)*100);
if (d.cookie) c=1;n=(na.substring(0,2)=="Mi")?0:1;rn=Math.random();
z="p="+p+"&rn="+rn+"&c="+c;if (self!=top) {fr=1;} else {fr=0;}
sl="1.0";</script><script language="javascript1.1">
pl="";sl="1.1";j = (navigator.javaEnabled()?"Y":"N");</script>
      <script language=javascript1.2>
sl="1.2";s=screen;px=(n==0)?s.colorDepth:s.pixelDepth;
z+="&wh="+s.width+'x'+s.height+"&px="+px;
    </script><script language=javascript1.3>
sl="1.3"</script><script language="javascript">
y="";y+="<a href='http://"+u+"/cnt?f=3&p="+p+"&rn="+rn+"' target=_blank>";
y+="<img src='http://"+u+"/cnt?"+z+"&j="+j+"&sl="+sl+
"&r="+escape(d.referrer)+"&fr="+fr+"&pg="+escape(window.location.href);
y+="' border=0 width=88 height=31 alt='SpyLOG'>";
y+="</a>"; d.write(y);if(!n) { d.write("<"+"!--"); }//--></script><noscript>
    <a href="http://u633.47.spylog.com/cnt?f=3&p=0" target=_blank>
<img src="http://u633.47.spylog.com/cnt?p=0" alt='SpyLOG' border='0' >
</a></noscript><script language="javascript1.2"><!--
if(!n) { d.write("--"+">"); }//--></script>
<!-- SpyLOG -->

<!--Rating@Mail.ru COUNTEr--><script language="JavaScript" type="text/javascript"><!--
d=document;var a='';a+=';r='+escape(d.referrer)
js=10//--></script><script language="JavaScript1.1" type="text/javascript"><!--
a+=';j='+navigator.javaEnabled()
js=11//--></script><script language="JavaScript1.2" type="text/javascript"><!--
s=screen;a+=';s='+s.width+'*'+s.height
a+=';d='+(s.colorDepth?s.colorDepth:s.pixelDepth)
js=12//--></script><script language="JavaScript1.3" type="text/javascript"><!--
js=13//--></script><script language="JavaScript" type="text/javascript"><!--
d.write('<a href="http://top.mail.ru/jump?from=1174814"'+
' target=_top><img src="http://dd.ce.b1.a1.top.list.ru/counter'+
'?id=1174814;t=59;js='+js+a+';rand='+Math.random()+
'" alt="Рейтинг@Mail.ru"'+' border=0 height=31 width=88/><\/a>')
if(11<js)d.write('<'+'!-- ')//--></script><noscript><a
target=_top href="http://top.mail.ru/jump?from=1174814"><img
src="http://dd.ce.b1.a1.top.list.ru/counter?js=na;id=1174814;t=59"
border=0 height=31 width=88
alt="Рейтинг@Mail.ru"/></a></noscript><script language="JavaScript" type="text/javascript"><!--
if(11<js)d.write('--'+'>')//--></script><!--/COUNTER-->

						</noindex>
					</div>
				</div>
				<div class="author-info">powered by Alexandr [Lunya] Lunyov</div>
			</div>
			<!-- ======================================== EOF: FOOTER ======================================== -->
		</div>
	</div>
	
	<div id="bottom-cap">
		<div class="border-l">&nbsp;</div>
		<div class="border-r">&nbsp;</div>
	</div>
</div>
<?php //print $closure ?>
</body>
</html>