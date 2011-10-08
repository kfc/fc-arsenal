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



