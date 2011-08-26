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
	 //dpm($node);
   
   
	//post before the match
	if(!empty($node->field_match_before_match) && $node->field_match_before_match[$node->language][0]['nid']){
		$node_news = node_load($node->field_match_before_match[$node->language][0]['nid']);
		$tabs_list[$tab_index] = '<div class="text">'.t('Match preview').'</div>';
		$content_tmp = '
		<h3>'.$node_news->title.'</h3>
		<div class="news-body">'.$node_news->body[$node_news->language][0]['safe_value'].'</div>
		<div class="news-link">'.l(t('Read comments'),'node/'.$node_news->nid).'</div>';
		$tabs_content[$tab_index++] = $content_tmp;
	}
	  
	//post after the match
	if(!empty($node->field_match_report) && $node->field_match_report[$node->language][0]['nid']){
    $node_news = node_load($node->field_match_report[$node->language][0]['nid']);
    $tabs_list[$tab_index] = '<div class="text">'.t('Match report').'</div>';
    $content_tmp = '
    <h3>'.$node_news->title.'</h3>
    <div class="news-body">'.$node_news->body[$node_news->language][0]['safe_value'].'</div>
    <div class="news-link">'.l(t('Read comments'),'node/'.$node_news->nid).'</div>';
    $tabs_content[$tab_index++] = $content_tmp;
  }
	
	//resume of the match
	if(!empty($node->field_match_comments) && $node->field_match_comments[$node->language][0]['nid']){
    $node_news = node_load($node->field_match_comments[$node->language][0]['nid']);
    $tabs_list[$tab_index] = '<div class="text">'.t('Match comments').'</div>';
    $content_tmp = '
    <h3>'.$node_news->title.'</h3>
    <div class="news-body">'.$node_news->body[$node_news->language][0]['safe_value'].'</div>
    <div class="news-link">'.l(t('Read comments'),'node/'.$node_news->nid).'</div>';
    $tabs_content[$tab_index++] = $content_tmp;
  }
	 
	//photo of the match
	if(!empty($node->field_match_gallery) && $node->field_match_gallery[$node->language][0]['nid']){
		//$tabs_list[$tab_index] = '<div class="text">'.t('Match gallery').'</div>';
		//$tabs_content[$tab_index++] = theme('view','gallery_view',NULL,NULL,'embed',array($node->field_gallery_id[0]['value']));
	}
	
	//video of the match
	if(!empty($node->field_match_review) && $node->field_match_review[$node->language][0]['nid']){
    $node_news = node_load($node->field_match_review[$node->language][0]['nid']);
    $tabs_list[$tab_index] = '<div class="text">'.t('Match video review').'</div>';
    $content_tmp = '
    <h3>'.$node_news->title.'</h3>
    <div class="news-body">'.$node_news->body[$node_news->language][0]['safe_value'].'</div>
    <div class="news-link">'.l(t('Read comments'),'node/'.$node_news->nid).'</div>';
    $tabs_content[$tab_index++] = $content_tmp;
  }
	
	print theme('custom_match_match_teaser', array($node,''));
	
  if(!empty($tabs_list))
	  print theme('custom_match_simple_tabs',array($tabs_list, $tabs_content)); 
?>
</div>
<div class="right-part">
  <?php if(isset($node->field_match_arsenal_squad[$node->language]) && isset($node->arsenal_events)):?>
	<?php print theme('custom_match_match_team_block', array(t('Arsenal'), $node->field_match_arsenal_squad[$node->language], $node->arsenal_events));?>
  <?endif;?>
  <?php if(isset($node->field_match_opponent_squad[$node->language][0]) && isset($node->opponent_events)):?> 
	<?php print theme('custom_match_match_team_block', array($node->field_match_opponent[$node->language][0]['node']->title, $node->field_match_opponent_squad[$node->language][0]['safe_value'], $node->opponent_events));?>
  <?endif;?>
</div>
<div class="cf">&nbsp;</div>
</div>