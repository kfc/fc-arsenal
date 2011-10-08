<div id="container">
	
	<div id="top-cap">
		<div class="logo"><a href="<?php print base_path();?>"><img src="<?php print base_path() . path_to_theme() ?>/img/pc.gif"></a></div>
		<?php print render($page['header']);?>
	</div>
	
	<div id="container1" class="border-l">
		<div class="border-r">
			
			<!-- ======================================== BOF: HEADER ======================================== -->
			<div id="main_menu">
				<div class="main-menu">
				<?php print render($page['main_menu']); ?>
				<div class="cf">&nbsp;</div>
				</div>
			</div>
			<!-- ======================================== EOF: HEADER ======================================== -->
			
			<!-- ======================================== BOF: MAIN-PART ======================================== -->
			<div id="main-part">
				
				<?php 
				if($is_front) { include('front.tpl.php'); } 
				//elseif($node->type == "news") { include('news.tpl.php'); } 
				elseif(arg(0) == 'chatrooms' && arg(1) == 'chat' && is_numeric(arg(2))){
					include('chatroom-chat.tpl.php'); 
				} else {?>
				<div id="content">
					<?php if ($messages): print $messages; endif; ?>
          <?php if((isset($variables['node']->type) &&  $variables['node']->type != "news") || (isset($node) && $node->type != 'news') || (!isset($variables['node']) && !isset($node))):?>
					  <h2><?php print $title; ?></h2>
          <?php endif;?> 
					<?php if($tabs) : print '<div class="tabs">'.render($tabs).'</div>'; endif; ?>
					<?php print render($tabs2); ?>
					<?php print render($page['help']); ?>
					<?php echo render($page['content']); ?>
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
            <?php print views_embed_view('random_article','fanclub_information');  ?>
          </div>

          <div class="center-part">
              <?php print views_embed_view('random_article','random_articles_homepage_block');  ?> 
          </div>
          
          
          <div class="right-part">
            <?php print views_embed_view('partner_sites','partner_sites_homepage_block');  ?>
          </div>
          
          <div class="cf">&nbsp;</div>
        </div>
        <?php } ?>
				<div class="hr1">&nbsp;</div>
				<div class="banner-links"><?php include_once('ireklama.php'); ?></div>
				<div class="banner-links">
					<?php
						if(!drupal_is_front_page()){
							$host = $_SERVER["HTTP_HOST"];
							$url = $_SERVER["REQUEST_URI"];
							$content=file_get_contents("http://62.149.23.94/servers2/link_server.php?host=".$host."&uri=".urlencode($url));
							print iconv('windows-1251','utf-8',$content);
						}
					?>
				</div>
				<div class="site-footer">
					<div class="footer-region"><?php print render($page['footer']); ?></div>
					<div class="rights">
            <?php print l(t('Partners news'), 'lastnews'); ?>
            &nbsp;|&nbsp;
            <?php print l(t('Partners articles'), 'stati-partnerov'); ?>
            
					</div>
          
					<div class="counter">
						<??><noindex>
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

						</noindex>  <??>
					</div>
				</div>
			</div>
			<!-- ======================================== EOF: FOOTER ======================================== -->
		</div>
	</div>
</div>