<?php 
/**
 * Implementation of hook_regions().
 */
function fc_arsenal_theme_regions() {
  $regions = phptemplate_regions();
  $regions['main_menu'] = t('main menu links');
  $regions['news_block'] = t('news block');
  //$regions['footer_block'] = t('footer block');
  return $regions;
}

function fc_arsenal_theme_nice_menus($variables){
  $id = $variables['id'];
  $menu_name = $variables['menu_name'];
  $mlid = $variables['mlid'];
  $direction = $variables['direction'];
  $depth = $variables['depth'];
  $menu = $variables['menu'];
  $output = array();
  if ($menu_tree = theme('nice_menus_tree', array('menu_name' => $menu_name, 'mlid' => $mlid, 'depth' => $depth, 'menu' => $menu))) {
    if ($menu_tree['content']) {
      $output['content'] = '<ul class="nice-menu nice-menu-' . $direction . '" id="nice-menu-' . $id . '">
        <li class="Home"><a href="/">&nbsp;</a></li>
        ' . $menu_tree['content'] . '
        <li>
          '.theme('custom_social_share_vk_link',$variables).'
          '.theme('custom_social_share_twitter_link',$variables).'
        </li>
          <li class="Mail"><a href="mailto:admin@fc-arsenal.com">&nbsp;</a></li>
        </ul>' . "\n";
      $output['subject'] = $menu_tree['subject'];
    }
  }
  return $output;
}


/**@file
 * Theme function for 'embedded' audio.
 */
function fc_arsenal_theme_audiofield_formatter_audiofield_embedded($variables) {
  global $user;
  $file = $variables['file'];
  $node = $variables['node'];
  if (!$file) {
    return '';
  }
  $audiofile=file_create_url($file->uri);
  $info = pathinfo($audiofile);
  $op = $info['extension'];
  $output = audiofield_get_player($audiofile, $op);
  
  $output .= '<div class="audio-download">'.l(theme('image',array('path'=>drupal_get_path('theme','fc_arsenal_theme').'/img/download-icon-small.png','width'=>'16px')).' '.t('Download file').' "'.$node->title.'"' , 'file_download/'.$file->fid,array('html'=>TRUE, 'attributes'=>array('title'=>t('Download file').' "'.$node->title.'"'))) . '</div>';

  return $output;
}