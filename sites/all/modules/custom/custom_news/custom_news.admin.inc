<?php
  
function custom_news_news_settings_form($form, &$form_state){
         //  dpm($form_state);
   $form['custom_news_important_news_nid'] = array(
      '#type' => 'textfield', 
      '#autocomplete_path' => 'news_settings/autocomplete', 
      '#default_value' => variable_get('custom_news_important_news_nid',''), 
      '#value_callback' => 'node_reference_autocomplete_value',
      '#element_validate' => array('custom_news_news_settings_nid_validate'),
      '#title' => t('Important News'), 
      '#description' => t('Select news item to be shown on top of all other news.'), 
    ); 
    
    
    $form['news_teaser_count'] = array(
      '#type' => 'textfield', 
      '#size' => 5, 
      '#default_value' => variable_get('news_teaser_count',5), 
      '#element_validate' => array('_element_validate_integer_positive'),
      '#title' => t('Number of news teasers to be shown in news list on front page.'), 
    ); 
   // $form['#submit'] = array('custom_news_news_settings_form_submit');
    //array_unshift($form['#submit'],'prepape_news_nid');
    return system_settings_form($form);

}

function custom_news_news_settings_nid_validate($element, &$form_state, $form){
  if(isset($form_state['values']['custom_news_important_news_nid'])){
    $val = $form_state['values']['custom_news_important_news_nid'];
    $nid = substr($val, strpos($val,'nid:')+4,strrpos($val,']'));
    $form_state['values']['custom_news_important_news_nid'] = $nid;
  }
}

?>
