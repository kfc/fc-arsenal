<?php
 //dd($node);
 if ($teaser) { //if teaser
?>
	<?php print theme('teaser_news_view2', $node)?>

<?php } else { ?>
	<?php print theme('read_news_block', $node); ?>
	<br>
	<h2>Комментарии:</h2>
	<?php print $links; ?>
<?php } ?>