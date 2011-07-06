<?php
	//dd($node);
	if(!$node->field_trainer_photo[0]['filepath']){
		$path = drupal_get_path('module','custom');
		$image_path = $path.'/no-photo.jpg';
	} else {
		$image_path = $node->field_trainer_photo[0]['filepath'];
	}
?>
<div class="trainer-page">
	<div class="left-part">
		<div class="trainer-box-info">
			<h2><?php print $node->title; ?></h2>
			<div class="box-content">
				<div class="photo"><?php print theme('image',$image_path); ?></div>
			<?php if($node->field_trainer_role[0]['value']) { ?>
				<div class="position"><span class="label">Позиция:</span> <?php print $node->field_trainer_role[0]['value']; ?></div>
			<?php } ?>
			
			<?php if($node->field_trainer_birth_date[0]['view']) { ?>
				<div class="birtday"><span class="label">Родился:</span> <?php print $node->field_trainer_birth_date[0]['view']; ?></div>
			<?php } ?>
			<?php if($node->field_trainer_birth_place[0]['value']) { ?>
				<div class="birth-place"><?php print $node->field_trainer_birth_place[0]['value']; ?></div>
			<?php } ?>
			
			<?php if($node->field_trainer_previous_clubs[0]['value']) { ?>
				<div class="clubs"><span class="label">Предыдущие клубы:</span> <?php print $node->field_trainer_previous_clubs[0]['value']; ?></div>
			<?php } ?>
			
			<?php if($node->field_trainer_ethnicity[0]['value']) { ?>
				<div class="nath"><span class="label">Национальность:</span> <?php print $node->field_trainer_ethnicity[0]['value']; ?></div>
			<?php } ?>
			
			<?php if($node->field_trainer_in_arsenal_since[0]['view']) { ?>
				<div class="arsenal"><span class="label">В Арсенале с:</span> <?php print $node->field_trainer_in_arsenal_since[0]['view']; ?></div>
			<?php } ?>
			
			<?php if($node->field_trainer_gallery_id[0]['value']) { ?>
				<div class="gallery"><?php print l('Галерея','gallery/'.$node->field_trainer_gallery_id[0]['value']); ?></div>
			<?php } ?>
			</div>
		</div>
	</div>
	<div class="right-part">
		<h2>Биография</h2>
		<?php print $node->field_trainer_biography[0]['view']; ?>
	</div>
	<div class="cf">&nbsp;</div>
</div>