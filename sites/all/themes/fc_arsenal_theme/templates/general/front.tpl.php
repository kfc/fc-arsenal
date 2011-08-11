<div class="front-page">
<?php if ($messages): print $messages; endif; ?>
<!-- BOF: LEFT MENU -->
	<div id="left" class="side-menu">
	<?php print render($page['left']); ?>
	</div>
<!-- EOF: LEFT MENU -->

<!-- BOF: FRONT-CONTENT -->
	<div id="content">
	<?php print render($page['content']); ?>
	</div>
<!-- EOF: FRONT-CONTENT -->

<!-- BOF: RIGHT MENU -->
	<div id="right" class="side-menu">
	<?php print render($page['right']); ?>
	</div>
<!-- EOF: RIGHT MENU -->
<div class="cf">&nbsp;</div>
</div>