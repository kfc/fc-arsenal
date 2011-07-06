<?php
if($teaser){
	?>
	<div class="node-archive-teaser">
		<h2><?php print $node->title?></h2>
		<div class="archive-teaser"><?php print $node->field_archive_teaser[0]['view'];?></div>
		<div class="links"><?php print l('читать дальше', 'node/'.$node->nid); ?></div>
	</div>
	<?php }else { ?>
	<div class="node-archive">
		<div class="date">создано: <?php print date('d/m/Y H:i', $node->created); ?></div>
		<div class="archive-body"><?php print $node->content['body']['#value'];?></div>
	</div>
<?php } ?>