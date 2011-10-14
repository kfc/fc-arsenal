<div class="Content01">
    <div class="Video">
      <?/*<a rel="lightvideo[|width:640px; height:480px;][<?php echo htmlspecialchars($fields['body']->raw);?>]" href="youtube.com/<?php echo str_replace('youtube://','',$fields['uri']->raw);?>"><?php echo $fields['field_video_file']->content;?></a>*/?>
      <a rel="lightmodal[|width:660px;height:550px;scrolling: auto;]" href="play_video/<?php echo $fields['nid']->raw;?>"><?php echo $fields['field_video_file']->content;?></a>
    </div>
    <h5>
      <a rel="lightmodal[|width:660px;height:550px;scrolling: auto;]" href="play_video/<?php echo $fields['nid']->raw;?>">
        <?php echo $fields['title']->content?>
      </a>
    </h5>
    <p class="Date"><?php echo $fields['created']->content?></p>
    <br>
</div>

<div class="BottomContent">
    <div class="InsideBottom"><a href="/video" class="Green"><?php echo t('All video');?></a></div>
</div>
