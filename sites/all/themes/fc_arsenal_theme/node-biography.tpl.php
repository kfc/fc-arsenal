<?php
	//dd($node);
	if(!$node->field_photo[0]['filepath']){
		$path = drupal_get_path('module','custom');
		$image_path = $path.'/no-photo.jpg';
	} else {
		$image_path = $node->field_photo[0]['filepath'];
	}
?>
<div class="player-page">
	<div class="left-part">
		<div class="player-box-info">
			<h2><?php print $node->title; ?></h2>
			<div class="box-content">
				<div class="photo"><?php print theme('image',$image_path); ?></div>
			<?php if($node->field_role[0]['value']) { ?>
				<div class="position"><span class="label">Позиция:</span> <?php print $node->field_role[0]['value']; ?></div>
			<?php } ?>
			
			<?php if($node->field_years_in_arsenal[0]['value']) { ?>
				<div class="arsenal"><span class="label">Годы в Арсенале:</span> <?php print $node->field_years_in_arsenal[0]['value']; ?></div>
			<?php } ?>
			
			<?php if($node->field_additional_information_1[0]['value']) { ?>
				<div class="additional-info"><span class="label">Дополнительная информация:</span> <?php print $node->field_additional_information_1[0]['value']; ?></div>
			<?php } ?>
			
			</div>
		</div>
	</div>
	<div class="right-part">
		<h2>Биография</h2>
		<?php print $node->field_biography_0[0]['view']; ?>
		<?php if($node->field_author_and_source[0]['value']) { ?>
			<div class="post-info">
				<div class="date"><span class="label">Дата:</span> <?php print date('d/m/Y',$node->created); ?></div>
				<div class="author"><span class="label">Автор:</span> <?php print $node->name; ?></div>
				<div class="source"><span class="label">Источник:</span> <?php print $node->field_author_and_source[0]['value']; ?></div>
			</div>
		<?php } ?>
	</div>
	<div class="cf">&nbsp;</div>
</div>