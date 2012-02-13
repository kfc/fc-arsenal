<?php //front page latest news ?>
<div class="teaser-node-news">
  <? /*<div class="news-image">
    <?php echo $fields['field_news_image']->content;?>
  </div> */ ?>
  <div class="news-body">
    <h3><?php echo $fields['title']->content;?></h3>
    <div class="news-content">
      <?php echo $fields['body']->content;?>
    </div>
  </div>
  <div class="news-footer">
    <span class="time-created"><?php echo $fields['created']->content;?></span><?php if(user_access('view news stats')):?>, 
    <span class="reads"><?php echo t('Reads count').' ('.(int)$fields['totalcount']->raw.')'?></span>,
    <span class="comments"><?php echo t('Comments count').' ('.$fields['comment_count']->content.')'?></span><?php endif;?>
  </div>
</div>