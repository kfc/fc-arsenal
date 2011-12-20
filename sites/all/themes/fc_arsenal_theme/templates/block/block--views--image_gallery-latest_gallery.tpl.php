<?php if ($block->subject): ?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
  <div <?php print $content_attributes; ?>>
    <?php print $content ?>
  </div>
</div>
<?php endif;?>
<script>
  jQuery(document).ready(function(){
    jQuery("#block-views-image-gallery-latest-gallery h2").html(jQuery("#block-views-image-gallery-latest-gallery h2").html()+' ('+jQuery('#block-views-image-gallery-latest-gallery div.Photo a.lightbox-processed').length+')');
  
  //  alert(jQuery('#block-views-image-gallery-latest-gallery a.lightbox-processed').length);  
  
  });
</script>