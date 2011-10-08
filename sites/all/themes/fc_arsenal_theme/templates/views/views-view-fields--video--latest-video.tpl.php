
<div class="Content01">
    <div class="Video">
      <?php 
        $videofile = new stdClass();
        $videofile->uri = $fields['uri']->raw;
        $videofile->override['width'] = 201;
        $videofile->override['height'] = 150;
        $videofile->override['autoplay'] = false;
        $videofile->override['controls'] = 0;
      echo render(media_youtube_file_formatter_video_view($videofile,array('settings'=>array()),'ru'));?>
    </div>
    <h5><?php echo $fields['title']->content?></h5>
    <p class="Date"><?php echo $fields['created']->content?></p>
    <br>
</div>

<div class="BottomContent">
    <div class="InsideBottom"><a href="/video" class="Green"><?php echo t('All video');?></a></div>
</div>
