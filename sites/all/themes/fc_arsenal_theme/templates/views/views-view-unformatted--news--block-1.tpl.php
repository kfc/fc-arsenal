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
    <div class="item-list">                                           
      <ul>
     <?endif;?> 
     <li>
     <span class="time-created"><span class="field-content"><?php echo  date('d/m/Y', $view->result[$index]->node_created);?></span></span>
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
<div style="text-align: right; margin-top: 5px;">
  <a href="/news-all/date"><?php echo t('All news')?></a>
</div>