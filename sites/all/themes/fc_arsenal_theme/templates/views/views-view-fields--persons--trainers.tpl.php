<?php
  //dpm($row);  
?>

<div class="squad-player-wrapper">
 <div style="float: left;">
<?php echo $fields['field_person_photo']->content;?>
</div>


<a href="/<?php print drupal_get_path_alias('node/'.$row->nid);?>">
<span class="squad-player-name-holder" style="padding-top: 13px">  
<?
  $name_parts = explode(' ',$row->node_title);
  $first_name = array_shift($name_parts);
?>
<span class="squad-player-first-name squad-trainer-first-name"><?php echo $first_name;?></span>
<span class="squad-player-last-name squad-trainer-last-name"><?php echo implode(' ',$name_parts);?></span>
<?if(!empty($fields['field_person_role_description'])): ?>
  <div class="squad-player-first-name squad-trainer-first-name"><?php echo $fields['field_person_role_description']->content;?></div>
<?endif;?>
</a>

</span>
</div>
