<div id="node-<?php print $node->nid; ?>" class="node-audio node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">
<div class="node-audio-title"><b><?php echo $title;?></b></div>
  <div class="content">
    <?php hide($content['links']);?>
    <?php print render($content) ?>
  </div>
</div>