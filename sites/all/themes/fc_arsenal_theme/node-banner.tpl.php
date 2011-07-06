<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

<?php //dd($node); ?>

<?php print l(theme('image', $node->field_banner_image[0]['filepath']), $node->field_banner_link[0]['url'], array('target' => '_blank'), NULL, NULL, FALSE, TRUE); ?>

</div>