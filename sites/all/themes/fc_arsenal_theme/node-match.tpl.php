<div id="node-match">
<?php
	//dd($node);
	//print $node->title;
?>
<div class="left-part">
<?php

	$tabs_list = array();
	$tabs_content = array();
	
	$tab_index = 0;
	
	//post before the match
	if($node->field_post_before_the_match[0]['nid']){
		$node_news = node_load($node->field_post_before_the_match[0]['nid']);
		$tabs_list[$tab_index] = '<div class="text">превью</div>';
		$content_tmp = '
		<h3>'.$node_news->title.'</h3>
		<div class="news-body">'.$node_news->body.'</div>
		<div class="news-link">'.l('читать комментарии','node/'.$node_news->nid).'</div>';
		$tabs_content[$tab_index++] = $content_tmp;
	}
	
	//post after the match
	if($node->field_post_after_the_match[0]['nid']){
		$node_news = node_load($node->field_post_after_the_match[0]['nid']);
		$tabs_list[$tab_index] = '<div class="text">послематчевые коментарии</div>';
		$content_tmp = '
		<h3>'.$node_news->title.'</h3>
		<div class="news-body">'.$node_news->body.'</div>
		<div class="news-link">'.l('читать комментарии','node/'.$node_news->nid).'</div>';
		$tabs_content[$tab_index++] = $content_tmp;
	}
	
	//resume of the match
	if($node->field_resume_the_match[0]['nid']){
		$node_news = node_load($node->field_resume_the_match[0]['nid']);
		$tabs_list[$tab_index] = '<div class="text">отчёт о матче</div>';
		$content_tmp = '
		<h3>'.$node_news->title.'</h3>
		<div class="news-body">'.$node_news->body.'</div>
		<div class="news-link">'.l('читать комментарии','node/'.$node_news->nid).'</div>';
		$tabs_content[$tab_index++] = $content_tmp;
	}
	
	//photo of the match
	if($node->field_gallery_id[0]['value']){
		$tabs_list[$tab_index] = '<div class="text">фото</div>';
		$tabs_content[$tab_index++] = theme('view','gallery_view',NULL,NULL,'embed',array($node->field_gallery_id[0]['value']));
	}
	
	//video of the match
	if($node->field_match_video[0]['value']){
		$tabs_list[$tab_index] = '<div class="text">видео</div>';
		$tabs_content[$tab_index++] = $node->field_match_video[0]['value'];
	}
	
	print theme('match_teaser', $node);
	
	print theme('simple_tabs',$tabs_list, $tabs_content)
?>
</div>

<div class="right-part">
	<?php print theme('match_team_block', TEXT_ARSENAL, $node->field_team_membership[0]['view'] );?>
	<?php print theme('match_team_block', $node->field_rival[0]['view'], $node->field_rival_membership[0]['view'] );?>
</div>
<div class="cf">&nbsp;</div>


</div>