<div class="comment <?php print ($new) ? ' comment-new' : ''; print ($status); ?> clear-block comment-<?php print $zebra;?> ">
	<!--div class="comment_user_picture"><?php print $picture;?></div-->
	<div class="comment-date date"><?php print render($content['posted_date']);?></div>
	<div class="comment-author"><?php print $author;?></div>
	<div class="cf">&nbsp;</div>
	<?php hide($content['links'])?>
	<div class="comment-body"><?php print render($content);?></div>
	<div class="comment-footer">
		<div class="comment-link">
			<?php print render($content['links']);?>
		</div>
	</div>
</div>