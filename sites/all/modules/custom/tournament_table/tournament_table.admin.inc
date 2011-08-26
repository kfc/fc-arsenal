<?php

function tournament_table_item_add_form($form, &$form_state){

  drupal_add_css(drupal_get_path('module', 'tournament_table').'/css/styles.css');
  
  $tournaments = array();
  $tournaments_terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('tournament')->vid);
  foreach($tournaments_terms as $tournament_term)
    $tournaments[$tournament_term->tid] = $tournament_term->name; 
  
  $default_tournament = variable_get('tournament_table_default_tournament','');  
    
  $form['tournament'] = array(
      '#type' => 'select', 
      '#options' => $tournaments, 
      '#default_value'=>$default_tournament,
      '#title' => t('Tournament'), 
      '#required' => true,
    );
  
  if(!empty($default_tournament))
    $form['tournament']['#disabled'] = true;
    
  $seasons = array();  
  $season_terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('season')->vid);
  foreach($season_terms as $season_term)
    $seasons[$season_term->tid] = $season_term->name;
 
  $default_season = variable_get('tournament_table_default_season','');   
    
  $form['season'] = array(
      '#type' => 'select', 
      '#options' => $seasons,
      '#default_value'=>$default_season,
      '#title' => t('Season'), 
      '#required' => true,
    );  
  
   if(!empty($default_season))
    $form['season']['#disabled'] = true;
  
  $form['delimiter'] = array(
      '#markup' => '<div><strong>'.t('Select teams and fill match results in. Home team is the first. Also set match date').'</strong></div>', 
    );
  
 /* $teams_res =  db_select('node','n')
            ->fields('n',array('nid','title'))
            ->condition('type','team')
            ->orderBy('title')
            ->execute()
            ->fetchAllKeyed();
  $teams = array('0'=>t('Select'));
  foreach($teams_res as $_id=>$_val)
    $teams[$_id] = $_val;
  */
  $tournament_teams = variable_get('tournament_table_season_teams',array());
  $teams_res =  db_select('node','n')
            ->fields('n',array('nid','title'))
            ->condition(db_and()->condition('nid',array($tournament_teams),'IN')->condition('type','team'))
            ->orderBy('title')
            ->execute()
            ->fetchAllKeyed();
  $teams = array('0'=>t('Select team...'));
  foreach($teams_res as $_id=>$_val)
    $teams[$_id] = $_val;
    
      
    for($i=0; $i<floor(count($teams)/2); $i++){
  
    $form['home_team_'.$i] = array(
      '#type' => 'select', 
      '#required' => false,
      '#options' => $teams, 
      '#prefix' => '<div class="tournament-table-add-field">',
      '#suffix' => '</div>'
    );
    
    $form['home_score_'.$i] = array(
      '#type' => 'textfield', 
      '#required' => false,
      '#size' => 3,
      '#prefix' => '<div class="tournament-table-add-field">',
      '#suffix' => '</div><div class="tournament-table-add-separator">&nbsp;-&nbsp;</div>'
    );
    
    $form['away_score_'.$i] = array(
      '#type' => 'textfield', 
      '#required' => false,
      '#size' => 3,
      '#prefix' => '<div class="tournament-table-add-field">',
      '#suffix' => '</div>'
    );
    
    
    
    $form['away_team_'.$i] = array(
      '#type' => 'select', 
      '#required' => false,
      '#options' => $teams, 
      '#prefix' => '<div class="tournament-table-add-field">',
      '#suffix' => '</div><div class="tournament-table-add-separator" style="margin-right: 0px;margin-left: 30px;">'.t('Match date').':</div>'
    );
    
    $form['match_date_'.$i] = array(
      '#type' => 'date', 
      '#required' => true,
      //'#date_format' => 'm-d-Y',date
      '#default_value' => array('month'=>format_date(time(),'custom','n'), 'day'=>format_date(time(),'custom','j'), 'year'=>format_date(time(),'custom','Y')),
      '#prefix' => '<div class="tournament-table-add-field" style="margin-left:15px;">',
      '#suffix' => '</div><div style="clear:both"></div>'
    );
    
  }
  $form['submit'] = array(
      '#type' => 'submit', 
      '#value' => t('Save'), 
      '#prefix' => '<div style="height:15px;">&nbsp;</div>',
    );
  
  $form['#submit'][] = 'tournament_table_item_add_form_submit';
  return $form;                
  
}

function tournament_table_item_add_form_submit($form, &$form_state){

  foreach($form_state['values'] as $_key=>$_value){
    if(strpos($_key,'home_team_') === 0){
      $row_id = substr($_key,10);
      if((int)$form_state['values'][$_key]!=0 && (int)$form_state['values']['away_team_'.$row_id]!=0
        && (int)$form_state['values'][$_key] != (int)$form_state['values']['away_team_'.$row_id]
        && strlen($form_state['values']['home_score_'.$row_id])>0 && strlen($form_state['values']['away_score_'.$row_id])>0
        && (int)($form_state['values']['home_score_'.$row_id])>=0 && (int)($form_state['values']['away_score_'.$row_id])>=0){
        
        
        $winner = ((int)($form_state['values']['home_score_'.$row_id]) > (int)($form_state['values']['away_score_'.$row_id]) ? (int)$form_state['values'][$_key] : ((int)($form_state['values']['home_score_'.$row_id]) < (int)($form_state['values']['away_score_'.$row_id]) ? (int)$form_state['values']['away_team_'.$row_id] : 0 ));
        
        db_insert('tournament_table_results')
                  ->fields(array('tournament','season', 'home_team','away_team','home_score','away_score','winner','home_points','away_points', 'match_date'))
                  ->values(array(
                      'tournament'=>$form_state['values']['tournament'],
                      'season'=>$form_state['values']['season'],
                      'home_team'=>(int)$form_state['values'][$_key],
                      'away_team'=>(int)$form_state['values']['away_team_'.$row_id],
                      'home_score'=>(int)($form_state['values']['home_score_'.$row_id]),
                      'away_score'=>(int)($form_state['values']['away_score_'.$row_id]),
                      'winner'=>$winner,
                      'home_points'=>($winner == 0 ? 1 : ($winner == (int)$form_state['values'][$_key] ? 3 : 0)),
                      'away_points'=>($winner == 0 ? 1 : ($winner == (int)$form_state['values']['away_team_'.$row_id] ? 3 : 0)),
                      'match_date'=>strtotime($form_state['values']['match_date_'.$row_id]['month'].'/'.$form_state['values']['match_date_'.$row_id]['day'].'/'.$form_state['values']['match_date_'.$row_id]['year']),
                  ))
                  ->execute();
      
      
      }
    }
  }
  drupal_goto('tournament-table');
}


function tournament_table_settings_form($form, &$form_state){

  $tournaments = array();
  $tournaments_terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('tournament')->vid);
  foreach($tournaments_terms as $tournament_term)
    $tournaments[$tournament_term->tid] = $tournament_term->name; 
  $form['tournament_table_default_tournament'] = array(
      '#type' => 'select', 
      '#options' => $tournaments, 
      '#default_value' =>  variable_get('tournament_table_default_tournament',''), 
      '#title' => t('Default tournament'), 
      '#required' => true,
    );
    
  $seasons = array();  
  $season_terms = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('season')->vid);
  foreach($season_terms as $season_term)
    $seasons[$season_term->tid] = $season_term->name;
  $form['tournament_table_default_season'] = array(
      '#type' => 'select', 
      '#options' => $seasons, 
      '#default_value' =>  variable_get('tournament_table_default_season',''), 
      '#title' => t('Default season'), 
      '#required' => true,
    );  
    
  $teams =  db_select('node','n')
            ->fields('n',array('nid','title'))
            ->condition('type','team')
            ->orderBy('title')
            ->execute()
            ->fetchAllKeyed();
  
   $form['tournament_table_season_teams'] = array(
      '#type' => 'checkboxes', 
      '#options' => $teams, 
      '#default_value' => variable_get('tournament_table_season_teams',array()), 
      '#title' => t('Tournament teams'), 
      '#required' => true,
    ); 
    
    return system_settings_form($form);

}

?>
