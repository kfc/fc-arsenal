<div class="dimageflow-wrapper">
	<?php if($galleries): ?>
	<div class="dimageflow-galleries"><h2><?php print t("Galleries"); ?></h2><?php print $galleries; ?></div>
	<?php endif; ?>
	<div id="<?php print $imageflow_id; ?>"  class="imageflow"><?php print $images; ?></div>
</div>