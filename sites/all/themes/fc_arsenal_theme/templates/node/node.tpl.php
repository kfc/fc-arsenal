<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

<?php //print $picture ?>

<?php if ($page == 0): ?>
  <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
<?php endif; ?>

  <?/* if ($submitted): ?>
    <span class="submitted"><?php print t('!date — !username', array('!username' => theme('username', $node), '!date' => format_date($node->created))); ?></span>
  <?php endif;*/ ?>

  <div class="content">
    <?php hide($content['links']);?>
    <?php print render($content) ?>
  </div>

  <div class="clear-block clear">
    <div class="meta">
    <?php //if ($taxonomy): ?>
      <div class="terms"><?php //print $terms ?></div>
    <?php //endif;?>
    </div>

    <?php if ($content['links']): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>
  </div>

</div>