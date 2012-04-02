<div id="latest-news-block" class="block">
<h2><?php echo t('Latest News');?></h2>
<div class="news-block-content">
  <?php
   $index = 0;
   foreach ($rows as $id => $row):
    if($index < $variables['news_teaser_count']):  
   ?>
    <div class="<?php print $classes_array[$id]; ?>">
      <?php print $row; ?>
    </div>
    <?php else:
      if($index == $variables['news_teaser_count']):
    ?>
    <!-- Hardcoded in view template views-view-unformatted--news--block-1.tpl.php  -->
    <div id="flashContent" style="margin-top: 10px; text-align: center;"><object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" id="500x100" width="500" align="middle" height="100"><param name="movie" value="500x100.swf"><param name="quality" value="high"><param name="bgcolor" value="#ffffff"><param name="play" value="true"><param name="loop" value="true"><param name="wmode" value="window"><param name="scale" value="showall"><param name="menu" value="true"><param name="devicefont" value="false"><param name="salign" value=""><param name="allowScriptAccess" value="sameDomain"><!--[if !IE]>--><object data="http://www.soccermart.ru/promo/arsenal/500x100.swf" type="application/x-shockwave-flash" width="500" height="100"><param name="movie" value="500x100.swf"><param name="quality" value="high"><param name="bgcolor" value="#ffffff"><param name="play" value="true"><param name="loop" value="true"><param name="wmode" value="window"><param name="scale" value="showall"><param name="menu" value="true"><param name="devicefont" value="false"><param name="salign" value=""><param name="allowScriptAccess" value="sameDomain"><!--<![endif]--><a href="http://www.adobe.com/go/getflash"> <img alt="Get Adobe Flash player" src="http://www.adobe.com/images/shared/download_buttons/get_flash_player.gif"> </a> <!--[if !IE]>--></object><!--<![endif]--></object></div>
    <!-- End of hardcoded banner -->
    <div class="item-list">                                           
      <ul>
     <?endif;?> 
     <li>
     <span class="time-created"><span class="field-content"><?php echo  date('d.m.Y', $view->result[$index]->node_created);?></span></span>
     <?php echo l($view->result[$index]->node_title, drupal_get_path_alias('node/'.$view->result[$index]->nid));?></li> 
     
     <?php if($index == $variables['total_rows']-1):?>
    </ul>
    </div>
  <?endif;?>
   
    <?php endif;?>
 <?php $index++;?>   
<?php endforeach; ?>
</div>
</div>

<?php if(!empty($variables['rss_items_html'])):?>
  <div class="block block-views" id="block-views-qrss_view_inoprosport_ru">
    <div class="content">
      <div class="view view-qrss-view-inoprosport-ru">
        <div class="view-content view-content-qrss-view-inoprosport-ru">
          <div class="item-list">
            <ul>
              <li>
                <div class="view-item view-item-qrss-view-inoprosport-ru">
                  <div class="view-field view-data-node-data-field-qrssreader-parsed-field-qrssreader-parsed-value">
                    <div class="item-list">
                      <?php echo $variables['rss_items_html'];?>
                    </div>
                  </div>
                </div>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  </div>
<?php endif;?>
<div class="all-news">
  <a href="/news-all/date" class="button"><?php echo t('All news')?></a>
</div>