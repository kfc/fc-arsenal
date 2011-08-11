<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">
<?php 
  $attributes = array();
  if($content['field_banner_new_window']['#items'][0]['value'] == 1)
    $attributes['target']='_blank';
?>
<?php print l(render($content['field_banner_image']), $content['field_banner_link']['#items'][0]['value'],array('html'=>TRUE, 'attributes'=>$attributes));?>

</div>