<?php    
	if(empty($node->field_person_photo)){
		$path = drupal_get_path('theme',variable_get('theme_default','fc_arsenal_theme'));
		$image_path = $path.'/img/no-photo.jpg';  
    $image = theme_image(array('path'=>$image_path));
	} else {
		$image = theme_image_style(array('style_name'=>'player_photo','path'=>$node->field_person_photo[$node->language][0]['uri']));
	}
?>
<div class="player-page">

		<div class="player-box-info">
			<!--h2>
      <?php if(!empty($node->field_person_number)): ?>
        <?php print $node->field_person_number[$node->language][0]['value'].'.&nbsp;';?>
      <?php endif;?>
      <?php echo $node->title; ?>
      </h2-->
      <div class="photo"><?php print $image; ?></div>
			<div class="box-content">
			<?php if(!empty($node->field_person_role)) { ?>
				<div class="position"><span class="label"><?php echo t('Player position')?>:</span> <?php print $node->field_person_role[$node->language][0]['taxonomy_term']->name; ?>
        <?php if(!empty($node->field_person_role_description)) { ?>
        <br />
        <?php echo $node->field_person_role_description[$node->language][0]['safe_value']?>
        <?php } ?>
        </div>
			<?php } ?>
			
			<?php if(!empty($node->field_person_birthday)) { ?>
				<div class="birtday"><span class="label"><?php echo t('Date of birth')?>:</span> <?php print date('d.m.Y', strtotime($node->field_person_birthday[$node->language][0]['value'])); ?></div>
			<?php } ?>
			<?php if(!empty($node->field_person_birthplace)) { ?>
				<div class="birth-place"><?php print $node->field_person_birthplace[$node->language][0]['value']; ?></div>
			<?php } ?>
			
			<?php if(!empty($node->field_person_previous_clubs)) { ?>
				<div class="clubs"><span class="label"><?php echo t('Previous clubs')?>:</span> <?php print $node->field_person_previous_clubs[$node->language][0]['value']; ?></div>
			<?php } ?>
			
			<?php if(!empty($node->field_person_nationality)) { ?>
				<div class="nath"><span class="label"><?php echo t('Nationality')?>:</span> <?php print $node->field_person_nationality[$node->language][0]['value']; ?></div>
			<?php } ?>
			
			<?php if(!empty($node->field_person_join_date)) { ?>
				<div class="arsenal"><span class="label"><?php echo t('Join Arsenal since')?>:</span> <?php print date('d.m.Y', strtotime($node->field_person_join_date[$node->language][0]['value'])); ?></div>
			<?php } ?>
			
			<?php if(!empty($node->field_person_gallery)) { ?>
				<div class="gallery"><?php print l(t('Gallery'),'node/'.$node->field_person_gallery[$node->language][0]['nid']); ?></div>
			<?php } ?>
			</div>
		</div>

    <?php if(!empty($node->field_person_biography)):?>
		  <!--h2><?php echo t('Biography')?></h2-->
		  <div class="player-info"><?php print $node->field_person_biography[$node->language][0]['safe_value']; ?></div>
    <?php endif;?>
    
    <?php if(!empty($stat_html)):?>
      <div class="season-stats">
      <h3><?php echo t('Season stats')?></h3>
      <?php print $stat_html; ?>
      </div>
    <?php endif;?>

	<div class="cf">&nbsp;</div>
</div>