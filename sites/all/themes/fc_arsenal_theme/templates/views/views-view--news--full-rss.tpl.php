<?php print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>"; ?>
<rss version="2.0" xml:base="http://fc-arsenal.com/news/all" xmlns:dc="http://purl.org/dc/elements/1.1/">  
<channel>
    <title><?php print $view->get_title(); ?></title>
    <link>http://fc-arsenal.com/news/all</link>
    <description><?php print $view->get_title(); ?></description>
    <language>ru</language>
    <?php echo $rows;?>
    </channel>
</rss>
