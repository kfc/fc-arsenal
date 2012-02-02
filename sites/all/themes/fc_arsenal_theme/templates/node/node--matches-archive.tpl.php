<?php
 echo render($content); 
?>
<?php if(!empty($season_matches)):?>
  <div>
    <h3><?php echo t('Season matches')?></h3>
    <div class="archive-matches-wrapper">
      <?php echo $season_matches;?>
    </div>
  </div>
<?php endif;?>

