<?php
//dpm($row);
?>

<div class="person squad-player">
	<div class="squad-player-number">
		<span><?php echo $fields['field_person_number']->content?></span>
	</div>
	<div class="person-photo">
		<?php echo $fields['field_person_photo'] -> content;?>
	</div>
	<a href="/<?php print drupal_get_path_alias('node/' . $row -> nid);?>">
	  <span class="person-name-holder">
		<?
      $name_parts = explode(' ', $row -> node_title);
      $first_name = array_shift($name_parts);
		?>
		<span class="person-first-name"><?php echo $first_name;?></span><br />
		<span class="person-last-name"><?php echo implode(' ', $name_parts);?></span>
		</span>
	</a>
</div>