<?php
  
function custom_news_news_settings_form($form, &$form_state){
         //  dpm($form_state);
   $form['custom_news_important_news_nid'] = array(
      '#type' => 'textfield', 
      '#autocomplete_path' => 'node_reference/autocomplete/node/match/field_match_before_match', 
      '#default_value' => variable_get('custom_news_important_news_nid',''), 
      '#element_validate' => array('node_reference_autocomplete_validate'),
      '#value_callback' => 'node_reference_autocomplete_value',
      '#title' => t('Important News'), 
      '#description' => t('Select news item to be shown on top of all other news.'), 
      '#language'=>'',
      '#field_parents'=>null,
      '#field_name'=>null,
    ); 
    
    
    $form['news_teaser_count'] = array(
      '#type' => 'textfield', 
      '#size' => 5, 
      '#default_value' => variable_get('news_teaser_count',5), 
      '#element_validate' => array('_element_validate_integer_positive'),
      '#title' => t('Number of news teasers to be shown in news list on front page.'), 
    ); 
    
    return system_settings_form($form);

}

?>
