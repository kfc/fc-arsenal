<?php if ($block->subject): ?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
  <div <?php print $content_attributes; ?>>
    <?php print $content ?>
  </div>
</div>
<?php endif;?>