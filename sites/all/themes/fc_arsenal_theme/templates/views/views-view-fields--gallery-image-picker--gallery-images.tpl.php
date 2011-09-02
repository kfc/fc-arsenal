<?php   
  echo theme_image_style(array('style_name'=>'thumbnail','path'=>$fields['uri']->raw,'attributes'=>array('id'=>'fid_'.$fields['fid']->raw,'rel'=>'image_item_gallerypicker')));
?>