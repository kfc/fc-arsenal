<div class="front-page">
<?php if ($messages): print $messages; endif; ?>
<!-- BOF: LEFT MENU -->
	<aside id="left" class="side-menu">
	<?php print render($page['left']); ?>
	</aside>
<!-- EOF: LEFT MENU -->

<!-- BOF: FRONT-CONTENT -->
	<section id="content">
	<?php print render($page['content']); ?>
	</section>
<!-- EOF: FRONT-CONTENT -->

<!-- BOF: RIGHT MENU -->
	<aside id="right" class="side-menu">
	<?php print render($page['right']); ?>
	</aside>
<!-- EOF: RIGHT MENU -->
<div class="cf">&nbsp;</div>
</div>