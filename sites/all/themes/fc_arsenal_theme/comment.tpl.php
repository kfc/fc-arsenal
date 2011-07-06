<?php //ed($comment);?>
<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ($comment->status == COMMENT_NOT_PUBLISHED) ? ' comment-unpublished' : ''; ?> clear-block comment-<?php print $zebra; ?>">
	<div class="left-part">
		<div class="comment-author"><?php print ($user = user_load(array('uid' => $comment->uid))) ? theme_username($user) : $comment->name ?></div>
	</div>
	<div class="right-part">
		<?php print $comment->comment ?>
	</div>
	<div class="cf">&nbsp;</div>
	<div class="comment-footer">
		<div class="comment-link"><?php print $links ?></div>
		<div class="comment-date">Дата:	<span class="info-value"><?php print date('d/m/Y H:i', $comment->timestamp); ?></span></div>
	</div>
	<div class="cf">&nbsp;</div>
</div>