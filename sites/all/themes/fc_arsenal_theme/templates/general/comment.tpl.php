
<div class="comment <?php print ($new) ? ' comment-new' : ''; print ($status); ?> clear-block comment-<?php print $zebra; ?> ">
  <div class="comment_user_picture">
<?php print $picture;?>
</div>
	<div class="right-part">
    <div class="comment-author"><?php print $author;?> <span class="comment-date">(<?php print render($content['posted_date']);?>)</span></div>
    <?php hide($content['links']) ?>
		<?php print render($content); ?>
	</div>
	<div class="cf">&nbsp;</div>
	<div class="comment-footer">
		<div class="comment-link"><?php print render($content['links']); ?></div>
	</div>
	<div class="cf">&nbsp;</div>
</div>
<div class="cf">&nbsp;</div> 