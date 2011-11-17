  <div class="node-news-item">
    <div class="left-part">
        <div id="read-news-item">
          <div class="news-image"><?php print render($content['field_news_image'])?></div>
          <div class="news-content">
            <h2><?php print $title?></h2>
            <div class="news-body"><?php print render($content['body'])?></div>
            <div class="news-tags"><?php print render($content['custom_social_share'])?> &nbsp; 
            <?php if(isset($content['field_news_tags'])):?>
              <img src="/<?php echo drupal_get_path('theme','fc_arsenal_theme');?>/img/icons/tag16.png">
              <?php echo render($content['field_news_tags']);?>
            <?php endif;?>
            </div>
            <div class="news-footer">
              <span class="news-date"><?php echo $posted_date;?></span><br>
              <?php if($content['field_news_source']):?>
                <span class="news-source"><?php echo t('Source')?>: <span class="info-value"><?php print render($content['field_news_source'])?></span></span>,
              <?php endif;?>
              <span class="reads"><?php echo t('Reads count')?> (<?php echo $read_count;?>)</span><br>
              <span class="comments"><?php echo t('Comments count')?> (<?php echo $comment_count;?>)</span><br>
              <span class="news-author"><?php echo t('Author')?>: <span class="info-value"><?php echo $author;?></span></span>
            </div>
          </div>
        </div>
      <br>
      <?php print render($content['comments']); ?>
    </div>
  <div class="right-part">
    <?php  print render($content['news_block']); ?>&nbsp;
  </div>
  <div class="cf">&nbsp;</div>
  </div>