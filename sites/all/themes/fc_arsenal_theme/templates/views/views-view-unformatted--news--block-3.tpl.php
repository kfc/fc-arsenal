<div id="latest-news-block" class="block">
<h2><?php echo t('Other News');?></h2>
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