<?php
 echo render($content); 
?>
<?php if(!empty($season_matches)):?>
  <div>
    <div class="archive-matches-wrapper">
      <?php echo $season_matches;?>
    </div>
  </div>
<?php endif;?>

