<?php
  
  $import_data = array('players','teams','matches','news');
  
  $selected = (isset($_GET['import']) && in_array($_GET['import'], $import_data) ? $_GET['import'] : '');
  
  if($selected =='') die('No data to import was selected');
  
  define('DRUPAL_ROOT', getcwd());

  require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);
  
  echo '<pre>';
  switch($selected){
  
    case 'players':
    
      $num = db_query("SELECT count(*) as num from {node} where type='team'")->fetchAssoc();
      print_r($num);               
      $query = db_select('node','n');
      $query->condition(db_and()->condition('type','team')->condition('title', iconv('CP1251', "UTF-8", "Арсенал")))
              ->fields('n',array('nid'))
              ->range(0,1);
      $team_id = $query->execute()->fetchAssoc();
        
                  
      
      db_set_active('old');
     
     $res = db_query("SELECT * from {content_type_player} pl"); 
     
     $data_to_import = array();
     while($player_info = $res->fetchAssoc())
     {
      $data_to_import[] = $player_info;/* array(
        'name' => $player_node->title
      );                                 */
     }
     print_r($data_to_import);
    
      
      break;
      
      default:
      break;
  }
  
  
?>
