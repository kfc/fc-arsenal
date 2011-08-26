<?php
  //dpm($row);  
?>

<div class="squad-player-wrapper">
  <a href="/<?php print drupal_get_path_alias('node/'.$row->nid);?>">
    <div class="squad-player-number">
      <span><?php echo $fields['field_person_number']->content?></span>
    </div>                          
  </a>
  <div style="float: left;">
    <?php echo $fields['field_person_photo']->content;?>
  </div>
  <a href="/<?php print drupal_get_path_alias('node/'.$row->nid);?>">
    <div class="squad-player-name-holder"> 
    <?
      $name_parts = explode(' ',$row->node_title);
      $first_name = array_shift($name_parts);
    ?>
    <span class="squad-player-first-name"><?php echo $first_name;?></span>
    <span class="squad-player-last-name"><?php echo implode(' ',$name_parts);?></span> 
    </div>
  </a>
</div>
