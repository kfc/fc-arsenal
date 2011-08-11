<div id="front-page-top-news">
    <div class="news-image"><?php echo $fields['field_news_image']->content;?></div>
    <div class="news-content">
      <h2><?php echo $fields['title']->content;?></h2>
      <div class="news-footer"><?php echo $fields['created']->content;?>
      <br><?php echo t('Comments count').' ('.$fields['comment_count']->content.')'?>,
      &nbsp;<?php echo t('Reads count').' ('.(int)$fields['totalcount']->raw.')'?></div>
    </div>
  </div>