<div class="node-news-item">
	<div class="left-part">
		<div id="read-news-item">
			<h1><?php print $title?></h1>
			<div class="news-image">
				<?php print render($content['field_news_image'])?>
			</div>
			<div class="news-content">
				<div class="news-body">
					<?php print render($content['body'])?>
				</div>
				<div class="news-footer">
					<?php if($content['field_news_source']):?>
					<div class="news-source"><b><?php echo t('Source')?>:</b> <span class="info-value"><?php print render($content['field_news_source'])?></span></div> 
					<?php endif;?>
					<!--div class="reads"><?php echo t('Reads count')?>: <?php echo $read_count;?></div-->
					<!--div class="comments"><?php echo t('Comments count')?>(<?php echo $comment_count;?>)</div-->
					<div class="news-author"><b><?php echo t('Author')?>:</b> <span class="info-value"><?php echo $author;?></span></div>
          <?php if(isset($content['field_news_tags'])):?>
          <div class="news-tags"><img src="/<?php echo drupal_get_path('theme', 'fc_arsenal_theme');?>/img/icons/tag16.png"><?php echo render($content['field_news_tags']);?></div>
          <?php endif;?>
					<div class="news-date">
					  <span class="date"><?php echo $posted_date;?></span> <?php print render($content['custom_social_share'])?>
					</div>
				</div>
			</div>
		</div>
		<?php print render($content['comments']);?>
	</div>
	<div class="right-part">
		<?php  print render($content['news_block']);?>
	</div>
	<div class="cf">&nbsp;</div>
</div>
