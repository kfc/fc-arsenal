<?php       
  $display = $variables['view']->display[$variables['view']->current_display];
?>
<div id="hystory-articles-block" class="block">
  <h3><?php print $display->display_options['title'] ?></h3>
    <div class="content">
      <div class="item-list">
        <ul>
          <?php foreach ($rows as $id => $row): ?>
            <li><?php print $row; ?></li>
          <?php endforeach; ?>
        </ul>
      </div>
  </div>
</div>
