<div id="node-<?php print $node -> nid;?>" class="node-audio node<?php if ($sticky) { print ' sticky';} ?><?php if (!$status) { print ' node-unpublished';} ?>">
	<div class="node-audio-title">
		<?php echo $title;?>
	</div>
	<div class="node-audio-content">
		<?php hide($content['links']);?>
		<?php print render($content)?>
	</div>
</div>