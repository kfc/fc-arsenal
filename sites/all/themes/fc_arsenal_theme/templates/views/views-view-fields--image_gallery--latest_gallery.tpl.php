<?
$cover = str_replace('rel="lightbox"', 'rel="lightbox[gallery]" class="lightbox_hide_image"', $fields['field_gallery_images'] -> content);
$cover = preg_replace('/rel="lightbox\[gallery\]" class="lightbox_hide_image"/', 'rel="lightbox[gallery]"', $cover, 1);
preg_match('/<a(.*?)>/', $cover, $matches);
if (isset($matches[0]))
  $title = $matches[0] . $fields['title'] -> content . '</a>';
else
  $title = $fields['created'] -> content;
?>
<div class="content">
	<div class="photo">
		<?php echo $cover;?>
	</div>
	<h5><?php echo $title;?></h5>
	<div class="date"><?php echo $fields['created']->content ?></div>
</div>
<div class="more-link">
	<a href="/gallery" class="button"><?php echo t('All photo');?></a>
</div>
<script>
	jQuery(document).ready(function() {
		//jQuery("div.Content01 h5 a").html(jQuery("div.Content01 h5 a").html() + ' (' + jQuery('div.Content01 div.Photo a.lightbox-processed').length + ')');
		//  alert(jQuery('#block-views-image-gallery-latest-gallery a.lightbox-processed').length);
	});
</script>