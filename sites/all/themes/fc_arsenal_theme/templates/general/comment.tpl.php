<div class="comment <?php print ($new) ? ' comment-new' : ''; print ($status); ?> clear-block comment-<?php print $zebra; ?> ">
	<div class="left-part">
		<div class="comment-author"><?php print $author;?></div>
	</div>
	<div class="right-part">
    <?php hide($content['links']) ?>
		<?php print render($content); ?>
	</div>
	<div class="cf">&nbsp;</div>
	<div class="comment-footer">
		<div class="comment-link"><?php print render($content['links']); ?></div>
		<div class="comment-date"><?php echo t('Date')?>:	<span class="info-value"><?php print render($content['posted_date']);?></span></div>
	</div>
	<div class="cf">&nbsp;</div>
</div>