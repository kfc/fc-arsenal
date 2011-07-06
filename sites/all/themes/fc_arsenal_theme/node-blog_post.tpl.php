<?php
 //dd($node);
 if ($teaser) { //if teaser
?>
	<?php include('node.tpl.php'); ?>

<?php } else { ?>
<div class="blog-post-page">
	<div class="post-info">
		<span class="date">дата: <?php print date('d/m/Y H:i',$node->created); ?>,&nbsp;</span>
		<span class="reads">читали (<?php print get_node_reads($node->nid); ?>),</span>
		<span class="comments-number">коментариев (<?php print $node->comment_count; ?>)&nbsp;</span>
	</div>
	<div class="left-part">
		<?php print $content; ?>
		<div class="comments-title">Комментарии: </div>
		<br>
		<?php print $links;?>
	</div>
	<div class="right-part">
		<?php print theme('user_blog_block', user_load(array('uid' => $node->uid))); ?>
	</div>
	<div class="cf">&nbsp;</div>
</div>
<?php } ?>