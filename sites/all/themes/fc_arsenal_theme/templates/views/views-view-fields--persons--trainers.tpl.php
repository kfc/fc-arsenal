<?php
//dpm($row);
?>

<div class="trainer">
	<div class="trainer-photo">
		<?php echo $fields['field_person_photo'] -> content;?>
	</div>
	<a href="/<?php print drupal_get_path_alias('node/' . $row -> nid);?>">
    <span class="trainer-name-holder">
  	  <?
      $name_parts = explode(' ', $row -> node_title);
      $first_name = array_shift($name_parts);
      ?>
    	<span class="trainer-first-name"><?php echo $first_name;?></span><br />
    	<span class="trainer-last-name"><?php echo implode(' ', $name_parts);?></span>
  	</span>
  	<?if(!empty($fields['field_person_role_description'])):?>
    <span class="trainer-description"><?php echo $fields['field_person_role_description'] -> content;?></span>
  	<?endif;?>
	</a>
</div>
