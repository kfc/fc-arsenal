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


function phptemplate_views_view_news_by_type($view, $type, $nodes){
	
	if(is_numeric($view->args[0])){
		$news_type_node = node_load($view->args[0]);
		$title = $news_type_node->title;
	} else {
		$title = 'новости';
	}
	
	$content = theme_views_view($view, $type, $nodes);
	
	return theme('fc_content_view', $title, $content);
}

function phptemplate_views_view_articles($view, $type, $nodes){
	$content = theme_views_view($view, $type, $nodes);
	return theme('fc_content_view', 'Статьи', $content);
}

function phptemplate_views_view_match_prev($view, $type, $nodes){
	if($type == 'block'){
		$nid = $nodes[0]->nid;
		if($nid){
			$node = node_load($nid); //getting match
			return theme('match_block', $node);
		}
	}
	
	return theme_views_view($view, $type, $nodes);
}

function phptemplate_views_view_match_next($view, $type, $nodes){
	if($type == 'block'){
		$nid = $nodes[0]->nid;
		if($nid){
			$node = node_load($nid); //getting match
			return theme('match_block', $node, true);
		}
	}
	
	return theme_views_view($view, $type, $nodes);
}

function phptemplate_views_view_gallery_view($view, $type, $nodes){
	$output = '';
  
  $tid = (int)$view->args[0];
  $subterms = _get_gallery_children_terms($tid);
  //ed($terms);
  
	$output .= $subterms.
  '<div class="gallery-view-area">';
	foreach($nodes as $node){
		$node_image = node_load($node->nid);
		$output .= '<div class="gallery-image">'.
		'<div class="image">'.theme('display_image_thickbox', $node_image, IMAGE_THUMBNAIL).'</div>'.
		'</div>';
	}
	if(!count($nodes)){
		//$output .= 'Тут картинок нет';
	};
	$output .= '<div class="cf">&nbsp;</div>';
	$output .= '</div>';
	return $output;
}

function phptemplate_views_view_blog_post_list($view, $type, $nodes){
	$output = '';
	
	$list = array();
	//dd($nodes);
	foreach($nodes as $node){
		$node_blog_post = node_load($node->nid);
		//dd($node_blog_post);
		$list[] = l($node_blog_post->title, 'node/'.$node_blog_post->nid).',&nbsp;&nbsp;'.
		date('d/m/Y H:i',$node_blog_post->created).',&nbsp;&nbsp;'.
		'читали ('.get_node_reads($node_blog_post->nid).'),&nbsp;&nbsp;'.
		'комментариев ('.$node_blog_post->comment_count.')';
	}
	
	if(!count($list)) {
		return 'Тут нет пока статей';
	} else {
		$output .= '
		<ul>
			<li>'.implode('</li><li>', $list).'</li>
		</ul>';
	}
	
	return $output;
}

function phptemplate_views_view_user_blog($view, $type, $nodes){
	$output = '';
	$output .= '<div class="view-user-blog">';
	$output .= '<h2>Статьи блога:</h2>';
	$list = array();
	foreach($nodes as $node){
		$node_blog_post = node_load($node->nid);
		$list[] = l($node_blog_post->title, 'node/'.$node_blog_post->nid).',&nbsp;&nbsp;'.
		date('d/m/Y H:i',$node_blog_post->created).',&nbsp;&nbsp;'.
		'читали ('.get_node_reads($node_blog_post->nid).'),&nbsp;&nbsp;'.
		'комментариев ('.$node_blog_post->comment_count.')';
	}
	
	if(!count($list)) {
		return 'Тут нет пока статей';
	} else {
		$output .= '
		<ul>
			<li>'.implode('</li><li>', $list).'</li>
		</ul>';
	}
	
	$output .= '</div>';
	return $output;
}

function phptemplate_views_view_players_season($view, $type, $nodes){
	//dd($view);
	$term = taxonomy_get_term($view->args[0]);
	//dd($term);
	//dd($nodes);
	/*foreach($nodes as $key => $node){
		$nodes[$key]->node_data_field_gallery_id_0_field_gallery_id_0_value = l('Фотогалерея','gallery/'.$nodes[$key]->node_data_field_gallery_id_0_field_gallery_id_0_value);
	}*/
	$content = theme_views_view($view, $type, $nodes);
	return theme('fc_content_view', 'состав команды образца сезона '.$term->name, $content);
}
/*
function phptemplate_views_view_matches_list($view, $type, $nodes){
	$content = theme_views_view($view, $type, $nodes);
	return theme('fc_content_view', 'матчи', $content);
}*/

function phptemplate_menu_item_link($item, $link_item) {
  if ($item['path'] == '<none>') {
    $attributes['title'] = $link['description'];
    return '<a class="menu-item-none">'. $item['title'] .'</a>';
  }
  else {
    return l($item['title'], $link_item['path'], !empty($item['description']) ? array('title' => $item['description']) : array(), isset($item['query']) ? $item['query'] : NULL);
  }
}

