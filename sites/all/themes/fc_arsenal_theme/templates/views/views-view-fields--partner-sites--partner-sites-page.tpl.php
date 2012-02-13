<?php if(isset($fields['field_partner_banner_image'])){?>
<div class="partner-image">
	<?php echo $fields['field_partner_banner_image'] -> content;?>
</div>
<?php } else { ?>
<div class="partner-title">
	<?php echo $fields['title']->content?>
</div>
<?php } ?>
<div class="partner-info">
	<?php if(!empty($fields['field_partner_link_text'])):?>
	&nbsp;<?php echo $fields['field_partner_link_text'] -> content;?>
	<?php endif;?>
</div>