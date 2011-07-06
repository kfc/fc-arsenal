<div id="content">
	<?php if ($messages): print $messages; endif; ?>
	<?php if($tabs) : print '<div class="tabs">'.$tabs.'</div>'; endif; ?>
	<?php if (isset($tabs2)): print $tabs2; endif; ?>
	<?php if ($help): print $help; endif; ?>
	<div class="node-news-item">
		<div class="left-part">
			<?php print $content ?>
		</div>
		<div class="right-part">
			<?php	print $news_block; ?>&nbsp;
		</div>
		<div class="cf">&nbsp;</div>
	</div>
</div>