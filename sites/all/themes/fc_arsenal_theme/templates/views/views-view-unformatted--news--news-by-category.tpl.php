<?php if($variables['page_title']):?>
  <h2><?php echo $variables['page_title'];?></h2>
<?endif;?>
<div class="news-block-content">
  <div>
    <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
</div>
