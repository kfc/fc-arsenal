<?
$cover =  str_replace('rel="lightbox"','rel="lightbox[gallery]" class="lightbox_hide_image"', $fields['field_gallery_images']->content);
$cover = preg_replace('/rel="lightbox\[gallery\]" class="lightbox_hide_image"/','rel="lightbox[gallery]"', $cover, 1);
preg_match('/<a(.*?)>/', $cover, $matches);
if(isset($matches[0]))
  $title = $matches[0].$fields['title']->content.'</a>';
else
  $title = $fields['created']->content;  
?>               
<div class="Content01">
    <div class="Photo">
      <?php echo $cover;?>
    </div>
    <h5>
        <?php echo $title;?>
    </h5>
    <p class="Date"><?php echo $fields['created']->content?></p>
    <br>
</div>

<div class="BottomContent">
    <div class="InsideBottom"><a href="/gallery" class="Green"><?php echo t('All photo');?></a></div>
</div>
<script>
  jQuery(document).ready(function(){
    jQuery("div.Content01 h5 a").html(jQuery("div.Content01 h5 a").html()+' ('+jQuery('div.Content01 div.Photo a.lightbox-processed').length+')');
  
  //  alert(jQuery('#block-views-image-gallery-latest-gallery a.lightbox-processed').length);  
  
  });
</script>