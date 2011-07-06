<?php
	//dd($node);
	if(!$node->field_field_stadium_photo[0]['filepath']){
		$path = drupal_get_path('module','custom');
		$image_path = $path.'/no-photo.jpg';
	} else {
		$image_path = $node->field_field_stadium_photo[0]['filepath'];
	}
?>
<div class="stadium-page">
	<div class="left-part">
		<div class="stadium-box-info">
			<h2><?php print $node->title; ?></h2>
			<div class="box-content">
				<div class="photo"><?php print theme('image', $image_path); ?></div>
				<div class="built-in"><span class="label">Построен:</span> <?php print $node->field_field_build_in[0]['view']; ?></div>
				<?php if($node->field_field_closed_in[0]['view']){ ?>
					<div class="closed-in"><span class="label">Закрыт:</span> <?php print $node->field_field_closed_in[0]['view']; ?></div>
				<?php } ?>
				<div class="placement"><span class="label">Расположение:</span> <?php print $node->field_field_placement[0]['view']; ?></div>
				<?php if($node->field_field_roominess[0]['view']){ ?>
					<div class="roominess"><span class="label">Вместительность:</span> <?php print $node->field_field_roominess[0]['view']; ?></div>
				<?php } ?>
				<?php if($node->field_field_record_of_attendanc[0]['view']){ ?>
					<div class="record-of-attendance"><span class="label">Рекордная посещаемость:</span> <?php print $node->field_field_record_of_attendanc[0]['view']; ?></div>
				<?php } ?>
				<?php if($node->field_field_gallery_id[0]['value']){ ?>
					<div class="gallery"><?php print l('Галерея','gallery/'.$node->field_field_gallery_id[0]['value']); ?></div>
				<?php } ?>
			</div>
		</div>
	</div>
	<div class="right-part">
		<h2>История</h2>
		<?php print $node->content['body']['#value']; ?>
	</div>
	<div class="cf">&nbsp;</div>
</div>