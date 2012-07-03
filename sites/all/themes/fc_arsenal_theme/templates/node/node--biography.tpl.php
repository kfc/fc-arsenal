<div class="player-page">

	<div class="player-box-info">
		<!--h2><?php print $title;?></h2-->
		<div class="photo"><?php print theme('image_style', array('style_name' => 'player_photo', 'path' => $field_biography_image[$language][0]['uri'])); ?></div>
		<div class="box-content">
			<?php if(!empty($field_biography_position)) {?>
			<div class="position">
				<span class="label">Позиция:</span><?php print $field_biography_position[$language][0]['safe_value'];?>
			</div>
			<?php }?>
			<?php if(!empty($field_biography_years)) {?>
			<div class="arsenal">
				<span class="label">Годы в Арсенале:</span><?php print $field_biography_years[$language][0]['safe_value'];?>
			</div>
			<?php }?>
			<?php if(!empty($field_biography_additional_info))  {?>
			<div class="additional-info">
				<span class="label">Дополнительная информация:</span><?php print $field_biography_additional_info[$language][0]['value'];?>
			</div>
			<?php }?>
		</div>
	</div>
	<!--h2>Биография</h2-->
	<?php print render($content);?>

	<div class="post-info">
		<?php if(!empty($field_biography_source)) {?>
		<div class="source">
			<span class="label">Источник:</span><?php print $field_biography_source[$language][0]['safe_value'];?>
		</div>
		<?php }?>
		<div class="author">
			<span class="label">Автор:</span><?php print $name;?>
		</div>
		<div class="date">
			<?php print date('d/m/Y', $created);?>
		</div>
	</div>
	<div class="cf">&nbsp;</div>

</div>
<?php print render($content);?>