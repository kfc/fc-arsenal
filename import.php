<?php
set_time_limit(60000);
echo '<pre>';
   define('DRUPAL_ROOT', getcwd());     
  if(!isset($_GET['import']))
    echo '<a href="import.php?import=all">Start Import</a>';
  else{
  //$import_data = array('players','teams','files','matches','news','tags','galleries');
 
  //$import_order = array('tags','files','news_galleries','news','stadium','referee','teams','match','node_url_aliases');
  $import_order = array('analytics','legends','bio', 'audio', 'books');
  //$import_order = array('books');
  $selected = (isset($_GET['import']) ? $_GET['import'] : ''); 
  if($selected == 'all'){
    foreach($import_order as $_item){
      import_data($_item);
      echo $_item.' imported<br />';
    }
  }
  else
    import_data($selected);
  }
  die();
   
  //if($selected =='') die('No data to import was selected');
  
  
    
  echo '<pre>';
 function import_data($selected){
 

  require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  module_load_include('inc','node_export','node_export.node_code');
  switch($selected){
  
    
    case 'analytics':
      db_set_active('old');
       $articles = db_query('SELECT aa.field_author_and_source_1_value, n.*,nr.*
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN  content_type_analytics_article aa on n.vid = aa.vid
              WHERE n.type = \'analytics_article\'
               ')
      ->fetchAllAssoc('nid');
      if(count($articles) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $articles_str = 'array(';
      foreach($articles as $article){
        $old_nids[] = $article->nid;
      
        $articles_str.= "array(
    'vid' => '3910',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($article->title).",
    'log' => '',
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => 0,
    'vuuid' => '',
    'nid' => '3910',
    'type' => 'article',
    'language' => 'ru',
    'created' => '1321905216',
    'changed' => '1321905216',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '56ddaa1e-d535-4fb3-94ed-bcff657b9c32',
    'revision_timestamp' => '1321905216',
    'revision_uid' => '1',
    'body' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($article->body).",
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($article->body).",
          'safe_summary' => '',
        ),
      ),
    ),
    'field_tags' => array(),
    'field_image' => array(),
    'field_article_type' => array(
      'ru' => array(
        '0' => array(
          'tid' => '73',
        ),                                      
      ),
    ),
    'field_article_source' => array(
      ".((!empty($article->field_author_and_source_1_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($article->field_author_and_source_1_value).",
          'format' => NULL,
          'safe_value' => ".node_export_node_code_encode($article->field_author_and_source_1_value).",
        ),
      ),
        " : '')."
    ),
    'rdf_mapping' => array(
      'field_image' => array(
        'predicates' => array(
          '0' => 'og:image',
          '1' => 'rdfs:seeAlso',
        ),
        'type' => 'rel',
      ),
      'field_tags' => array(
        'predicates' => array(
          '0' => 'dc:subject',
        ),
        'type' => 'rel',
      ),
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1321905216',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'node_weight' => 0,
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      $articles_str .= ')';
      
      $result = node_export_import($articles_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
    
      break;
      
      
    case 'legends':
    
      db_set_active('default');
      db_query('update file_managed set uri = REPLACE(uri,\'public://old/files/\',\'public://old/\')')->execute(); 
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1); 
    
      db_set_active('old');
       $legends = db_query('SELECT b.*, n.*,nr.*,SUBSTRING(n.title,9) as real_title
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN  content_type_biography b on n.vid = b.vid
              WHERE n.type = \'biography\'
              AND n.nid <= 1079
               ')
      ->fetchAllAssoc('nid');
      //print_r($legends);
      //die('2');
      if(count($legends) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $legends_str = 'array(';
      foreach($legends as $legend){
        $old_nids[] = $legend->nid;
        $file = file_load($files_map[$legend->field_photo_fid]);
        
        $legends_str.= "array(
    'vid' => '107',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($legend->real_title).",
    'log' => '',
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '107',
    'type' => 'biography',
    'language' => 'ru',
    'created' => '1318886407',
    'changed' => '1321907234',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '33ed7ff2-db57-4594-aa55-ca239fd35d5a',
    'revision_timestamp' => '1321907234',
    'revision_uid' => '1',
    'body' => array(
      'ru' => array(
        '0' => array(
          'value' =>  ".node_export_node_code_encode($legend->field_biography_0_value).",
          'summary' => '',
          'format' => 'full_html',
          'safe_value' =>  ".node_export_node_code_encode($legend->field_biography_0_value).",
          'safe_summary' => '',
        ),
      ),
    ),
    'field_biography_image' => array(
     ".((!empty($file->uri)) ? "
              'ru' => array(
                '0' => array(
                  'fid' => '$file->fid',
                  'alt' => NULL,
                  'title' => NULL,
                  'uid' => '$legend->uid',
                  'filename' => '$file->filename',
                  'uri' => '$file->uri',
                  'filemime' => '$file->filemime',
                  'filesize' => '$file->filesize',
                  'status' => '$file->status',
                  'timestamp' => '$file->timestamp',
                  'type' => '$file->type',
                  'uuid' => '',
                  'rdf_mapping' => array(),
                ),
              ),
              " : '')."
    ),
    'field_biography_position' => array(
      ".((!empty($legend->field_role_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => '".$legend->field_role_value."',
          'format' => NULL,
          'safe_value' => '".$legend->field_role_value."',
        ),
      ),
       " : '')." 
    ),
    'field_biography_years' => array(
    
    ".((!empty($legend->field_years_in_arsenal_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($legend->field_years_in_arsenal_value).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($legend->field_years_in_arsenal_value).",
        ),
      ),
      " : '')."
    ),
    'field_biography_additional_info' => array(
    
    ".((!empty($legend->field_additional_information_1_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($legend->field_additional_information_1_value).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($legend->field_additional_information_1_value).",
        ),
      ),
      " : '')." 
    ),
    'field_biography_category' => array(
      'ru' => array(
        '0' => array(
          'tid' => '71',
        ),
      ),
    ),
    'field_biography_source' => array(
     ".((!empty($legend->field_author_and_source_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($legend->field_author_and_source_value).",
          'format' => NULL,
          'safe_value' => ".node_export_node_code_encode($legend->field_author_and_source_value).",
        ),
      ),
       " : '')." 
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1318886407',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      $legends_str .= ')';
      
      $result = node_export_import($legends_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
    
      break;
    
    
    case 'bio':
    
      db_set_active('default');
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1); 
    
      db_set_active('old');
       $legends = db_query('SELECT b.*, n.*,nr.*
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN  content_type_biography b on n.vid = b.vid
              WHERE n.type = \'biography\'
              AND n.nid > 1079
               ')
      ->fetchAllAssoc('nid');
      //print_r($legends);
      //die('2');
      if(count($legends) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $legends_str = 'array(';
      foreach($legends as $legend){
        $old_nids[] = $legend->nid;
        $file = file_load($files_map[$legend->field_photo_fid]);
        
        $legends_str.= "array(
    'vid' => '107',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($legend->title).",
    'log' => '',
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '107',
    'type' => 'biography',
    'language' => 'ru',
    'created' => '1318886407',
    'changed' => '1321907234',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '33ed7ff2-db57-4594-aa55-ca239fd35d5a',
    'revision_timestamp' => '1321907234',
    'revision_uid' => '1',
    'body' => array(
      'ru' => array(
        '0' => array(
          'value' =>  ".node_export_node_code_encode($legend->field_biography_0_value).",
          'summary' => '',
          'format' => 'full_html',
          'safe_value' =>  ".node_export_node_code_encode($legend->field_biography_0_value).",
          'safe_summary' => '',
        ),
      ),
    ),
    'field_biography_image' => array(
     ".((!empty($file->uri)) ? "
              'ru' => array(
                '0' => array(
                  'fid' => '$file->fid',
                  'alt' => NULL,
                  'title' => NULL,
                  'uid' => '$legend->uid',
                  'filename' => '$file->filename',
                  'uri' => '$file->uri',
                  'filemime' => '$file->filemime',
                  'filesize' => '$file->filesize',
                  'status' => '$file->status',
                  'timestamp' => '$file->timestamp',
                  'type' => '$file->type',
                  'uuid' => '',
                  'rdf_mapping' => array(),
                ),
              ),
              " : '')."
    ),
    'field_biography_position' => array(
      ".((!empty($legend->field_role_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => '".$legend->field_role_value."',
          'format' => NULL,
          'safe_value' => '".$legend->field_role_value."',
        ),
      ),
       " : '')." 
    ),
    'field_biography_years' => array(
    
    ".((!empty($legend->field_years_in_arsenal_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($legend->field_years_in_arsenal_value).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($legend->field_years_in_arsenal_value).",
        ),
      ),
      " : '')."
    ),
    'field_biography_additional_info' => array(
    
    ".((!empty($legend->field_additional_information_1_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($legend->field_additional_information_1_value).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($legend->field_additional_information_1_value).",
        ),
      ),
      " : '')." 
    ),
    'field_biography_category' => array(),
    'field_biography_source' => array(
     ".((!empty($legend->field_author_and_source_value)) ? "
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($legend->field_author_and_source_value).",
          'format' => NULL,
          'safe_value' => ".node_export_node_code_encode($legend->field_author_and_source_value).",
        ),
      ),
       " : '')." 
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1318886407',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      $legends_str .= ')';
      
      $result = node_export_import($legends_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
    
      break;
      
    case 'audio':
    
      db_set_active('default');
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1); 
    
      db_set_active('old');
       $audios = db_query('SELECT s.*, n.*,nr.*
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN  content_type_song s on n.vid = s.vid
              WHERE n.type = \'song\'
               ')
      ->fetchAllAssoc('nid');
      //print_r($audios);
      //die('2');
      if(count($audios) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $audios_str = 'array(';
      foreach($audios as $audio){
        $old_nids[] = $audio->nid;
        $file = file_load($files_map[$audio->field_song_audio_file_fid]);
        
        $audios_str.= "array(
    'vid' => '4010',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($audio->title).",
    'log' => '',
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '4010',
    'type' => 'audio',
    'language' => 'ru',
    'created' => '1321913396',
    'changed' => '1321913396',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => 'ca67bb35-9bca-478a-a073-14885972912a',
    'revision_timestamp' => '1321913396',
    'revision_uid' => '1',
    'body' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($audio->field_song_text_value).",
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($audio->field_song_text_value).",
          'safe_summary' => '',
        ),
      ),
    ),
    'field_audio_file' => array(
      ".((!empty($file->uri)) ? "
              'ru' => array(
                '0' => array(
                  'fid' => '$file->fid',
                  'display' => '1',
                  'description' => '',
                  'uid' => '$audio->uid',
                  'filename' => '$file->filename',
                  'uri' => '$file->uri',
                  'filemime' => '$file->filemime',
                  'filesize' => '$file->filesize',
                  'status' => '$file->status',
                  'timestamp' => '$file->timestamp',
                  'type' => '$file->type',
                  'uuid' => '',
                  'rdf_mapping' => array(),
                ),
              ),
              " : '')."
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1321913396',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      $audios_str .= ')';
      
      $result = node_export_import($audios_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
    
      break;
      
      
    case 'books':
    
      db_set_active('default');
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1); 
    
      db_set_active('old');
       $books = db_query('SELECT b.*, n.*,nr.*, RTRIM(SUBSTRING_INDEX(n.title,\'. "\',1)) as author, SUBSTRING_INDEX( SUBSTRING_INDEX(n.title,\'"\',-2),\'"\',1) as real_title 
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN  content_type_book b on n.vid = b.vid
              WHERE n.type = \'book\'
               ')
      ->fetchAllAssoc('nid');
      //print_r($books);
      //die('2');
      if(count($books) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $books_str = 'array(';
      foreach($books as $book){
        $old_nids[] = $book->nid;
        $file = file_load($files_map[$book->field_file_fid]);
        
        $books_str.= "array(
    'vid' => '4018',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($book->real_title).",
    'log' => '',
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '4018',
    'type' => 'book',
    'language' => 'ru',
    'created' => '1321914214',
    'changed' => '1321914214',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => 'cb7f8ed9-6cd9-4dc1-a013-fa9013af75ec',
    'revision_timestamp' => '1321914214',
    'revision_uid' => '1',
    'body' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($book->body).",
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($book->body).",
          'safe_summary' => '',
        ),
      ),
    ),
    'field_book_cover' => array(),
    'field_book_file' => array(
     ".((!empty($file->uri)) ? "
              'ru' => array(
                '0' => array(
                  'fid' => '$file->fid',
                  'display' => '1',
                  'description' => '',
                  'uid' => '$book->uid',
                  'filename' => '$file->filename',
                  'uri' => '$file->uri',
                  'filemime' => '$file->filemime',
                  'filesize' => '$file->filesize',
                  'status' => '$file->status',
                  'timestamp' => '$file->timestamp',
                  'type' => '$file->type',
                  'uuid' => '',
                  'rdf_mapping' => array(),
                ),
              ),
              " : '')."
    ),
    'field_book_author' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($book->author).",
          'format' => NULL,
          'safe_value' => ".node_export_node_code_encode($book->author).",
        ),
      ),
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1321914214',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      $books_str .= ')';
      
      $result = node_export_import($books_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
    
      break;    
      
  
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
    
    case 'teams':
      db_set_active('default');
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1); 
        db_set_active('old');
       $teams = db_query('SELECT n.*,ct.*,nr.*,f.*
              FROM node n
              INNER JOIN content_type_team ct on ct.vid = n.vid
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN files f on f.fid = ct.field_team_emblem_fid
              WHERE n.type = \'team\'
               ')
      ->fetchAllAssoc('nid');
      if(count($teams) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $team_str = 'array(';
      foreach($teams as $team){
        $old_nids[] = $team->nid;
        $file = file_load($files_map[$team->field_team_emblem_fid]);
      
        $team_str.= "
          array(
            'vid' => '79',
            'uid' => '1',
            'title' => ".node_export_node_code_encode($team->title).",
            'status' => '1',
            'comment' => '1',
            'promote' => '0',
            'sticky' => '0',
            'vuuid' => '',
            'nid' => '79',
            'type' => 'team',
            'language' => 'ru',
            'created' => '1314390904',
            'changed' => 1320262691,
            'tnid' => '0',
            'translate' => '0',
            'uuid' => '542397a8-4456-496f-bfbe-70a2585ba0ab',
            'revision_timestamp' => '1314390904',
            'revision_uid' => '1',
            'field_team_logo' => array(
            ".((!empty($file->uri)) ? "
              'ru' => array(
                '0' => array(
                  'fid' => '$file->fid',
                  'alt' => NULL,
                  'title' => NULL,
                  'uid' => '$team->uid',
                  'filename' => '$file->filename',
                  'uri' => '$file->uri',
                  'filemime' => '$file->filemime',
                  'filesize' => '$file->filesize',
                  'status' => '$file->status',
                  'timestamp' => '$file->timestamp',
                  'type' => '$file->type',
                  'uuid' => '',
                  'rdf_mapping' => array(),
                ),
              ),
              " : '')."
            ),
            'field_team_description' => array(),
            'rdf_mapping' => array(
              'rdftype' => array(
                '0' => 'sioc:Item',
                '1' => 'foaf:Document',
              ),
              'title' => array(
                'predicates' => array(
                  '0' => 'dc:title',
                ),
              ),
              'created' => array(
                'predicates' => array(
                  '0' => 'dc:date',
                  '1' => 'dc:created',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
              ),
              'changed' => array(
                'predicates' => array(
                  '0' => 'dc:modified',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
              ),
              'body' => array(
                'predicates' => array(
                  '0' => 'content:encoded',
                ),
              ),
              'uid' => array(
                'predicates' => array(
                  '0' => 'sioc:has_creator',
                ),
                'type' => 'rel',
              ),
              'name' => array(
                'predicates' => array(
                  '0' => 'foaf:name',
                ),
              ),
              'comment_count' => array(
                'predicates' => array(
                  '0' => 'sioc:num_replies',
                ),
                'datatype' => 'xsd:integer',
              ),
              'last_activity' => array(
                'predicates' => array(
                  '0' => 'sioc:last_activity_date',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
              ),
            ),
            'cid' => '0',
            'last_comment_timestamp' => '',
            'last_comment_name' => NULL,
            'last_comment_uid' => '1',
            'comment_count' => '0',
            'name' => 'admin',
            'picture' => '107',
            'data' => 'b:0;',
            'timestamp' => 1320262691,
            'path' => FALSE,
            'menu' => array(
              'link_title' => '',
              'mlid' => 0,
              'plid' => 0,
              'menu_name' => 'main-menu',
              'weight' => 0,
              'options' => array(),
              'module' => 'menu',
              'expanded' => 0,
              'hidden' => 0,
              'has_children' => 0,
              'customized' => 0,
              'parent_depth_limit' => 8,
              'description' => '',
              'enabled' => 1,
            ),
            'node_export_drupal_version' => '7',
            '#_export_node_encode_object' => '1',
          ),
        ";
      
      }
      $team_str .= ')';
      
      $result = node_export_import($team_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
     
     //die($team_str); 
     // print_r($result);
    
      break;
    
    case 'stadium':
        db_set_active('old');
       $stadiums = db_query('SELECT n.*,nr.*
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              WHERE n.type = \'stadium\'
               ')
      ->fetchAllAssoc('nid');
      if(count($stadiums) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $stadiums_str = 'array(';
      foreach($stadiums as $stadium){
        $old_nids[] = $stadium->nid;
      
        $stadiums_str.= "
          array(
            'vid' => '',
            'uid' => '1',
            'title' => ".node_export_node_code_encode($stadium->title).",
            'status' => '1',
            'comment' => '1',
            'promote' => '0',
            'sticky' => '0',
            'vuuid' => '',
            'nid' => '80',
            'type' => 'stadium',
            'language' => 'ru',
            'created' => '1314390920',
            'changed' => 1320434054,
            'tnid' => '0',
            'translate' => '0',
            'uuid' => 'e25c1033-6d86-488f-bab7-28c456a05c9d',
            'revision_timestamp' => '1314390920',
            'revision_uid' => '1',
            'field_stadium_photo' => array(),
            'field_stadium_history' => array(),
            'field_stadium_team' => array(),
            'field_stadium_location' => array(),
            'field_stadium_capacity' => array(),
            'field_stadium_max_attendance' => array(),
            'field_stadium_build_year' => array(),
            'field_banner_image' => array(),
            'field_banner_show_in_random_node' => array(
              'ru' => array(
                '0' => array(
                  'value' => '0',
                ),
              ),
            ),
            'rdf_mapping' => array(
              'rdftype' => array(
                '0' => 'sioc:Item',
                '1' => 'foaf:Document',
              ),
              'title' => array(
                'predicates' => array(
                  '0' => 'dc:title',
                ),
              ),
              'created' => array(
                'predicates' => array(
                  '0' => 'dc:date',
                  '1' => 'dc:created',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
              ),
              'changed' => array(
                'predicates' => array(
                  '0' => 'dc:modified',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
              ),
              'body' => array(
                'predicates' => array(
                  '0' => 'content:encoded',
                ),
              ),
              'uid' => array(
                'predicates' => array(
                  '0' => 'sioc:has_creator',
                ),
                'type' => 'rel',
              ),
              'name' => array(
                'predicates' => array(
                  '0' => 'foaf:name',
                ),
              ),
              'comment_count' => array(
                'predicates' => array(
                  '0' => 'sioc:num_replies',
                ),
                'datatype' => 'xsd:integer',
              ),
              'last_activity' => array(
                'predicates' => array(
                  '0' => 'sioc:last_activity_date',
                ),
                'datatype' => 'xsd:dateTime',
                'callback' => 'date_iso8601',
              ),
            ),
            'cid' => '0',
            'last_comment_timestamp' => '1314390920',
            'last_comment_name' => NULL,
            'last_comment_uid' => '1',
            'comment_count' => '0',
            'name' => 'admin',
            'picture' => '107',
            'data' => 'b:0;',
            'timestamp' => 1320434054,
            'path' => FALSE,
            'menu' => array(
              'link_title' => '',
              'mlid' => 0,
              'plid' => 0,
              'menu_name' => 'main-menu',
              'weight' => 0,
              'options' => array(),
              'module' => 'menu',
              'expanded' => 0,
              'hidden' => 0,
              'has_children' => 0,
              'customized' => 0,
              'parent_depth_limit' => 8,
              'description' => '',
              'enabled' => 1,
            ),
            'node_export_drupal_version' => '7',
            '#_export_node_encode_object' => '1',
          ),
        ";
      
      }
      $stadiums_str .= ')';
      
      $result = node_export_import($stadiums_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
     
     //die($team_str); 
     // print_r($result);
    
      break;
    
    case 'referee':
        db_set_active('old');
       $referees = db_query('SELECT n.*,nr.*
              FROM node n
              INNER JOIN node_revisions nr on n.vid = nr.vid
              WHERE n.type = \'judge\'
               ')
      ->fetchAllAssoc('nid');
      if(count($referees) == 0) return;
      db_set_active('default'); 
      $old_nids = array();
      $referees_str = 'array(';
      foreach($referees as $referee){
        $old_nids[] = $referee->nid;
      
        $referees_str.= "
          array(
    'vid' => '5',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($referee->title).",
    'log' => '',
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '5',
    'type' => 'referee',
    'language' => 'en',
    'created' => '1311944653',
    'changed' => '1320435209',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '8afd68a1-85f6-4d94-8905-e1e11025575a',
    'revision_timestamp' => '1320435209',
    'revision_uid' => '1',
    'body' => array(
      'en' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($referee->body).",
          'summary' => ".node_export_node_code_encode($referee->body).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($referee->body).",
          'safe_summary' => ".node_export_node_code_encode($referee->body).",
        ),
      ),
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1311944653',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),
        ";
      
      }
      $referees_str .= ')';
      
      $result = node_export_import($referees_str);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids'])){
        foreach($result['nids'] as $_index=>$_nid){
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
      
      break;
    
      
    case 'files':
    
      db_query('DELETE FROM node_mapping where type=\'file\'');
    
      db_set_active('old');
      $files = db_select('files','f')->fields('f')->execute()->fetchAllAssoc('fid');
      foreach($files as $_file){
        $insert[$_file->fid] = array(
          //'fid'=>$_file->fid,
          'uid'=>1,
          'filename'=>$_file->filename,
          'uri'=>"public://old/".str_replace('files/images/','images/',$_file->filepath),
          'filemime'=>$_file->filemime,
          'filesize'=>$_file->filesize,
          'status'=>1,
          'timestamp'=>time(),
          'type'=>'image',
        );
      }
      
      db_set_active('default'); 
      
        foreach($insert as $_fid=>$_insert){
        try{
            $new_id = db_insert('file_managed')
            ->fields($_insert)
            ->execute();
          if($new_id){
            $data = array('old_nid'=>$_fid,'new_nid'=>$new_id,'type'=>'file');
            drupal_write_record('node_mapping', $data);  
          }
        }
        catch(PDOException $exc){ print_r($_insert->filename); }
      }
      
      //print_r($insert);
      break; 
      
    case 'tags':
      db_set_active('old');
      $terms = db_select('term_data','td')->fields('td')->condition('vid',4)->execute()->fetchAllAssoc('tid');
      foreach($terms as $_term){
        $insert[] = array(
          'tid'=>$_term->tid,
          'vid'=>1,
          'name'=>$_term->name,
          'format'=>'filtered_html',
        );
      }
      
      db_set_active('default'); 
      try{
        foreach($insert as $_insert){
          db_merge('taxonomy_term_data')
          ->key(array('tid'=>$_insert['tid']))
          ->fields($_insert)
          ->execute();
        }  
      }
      catch(PDOException $exc){ print_r($_insert); }
      //print_r($insert);
      break;  
      
    case 'news_galleries':
    
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1);
      /*$nids = db_query('SELECT distinct(entity_id) 
              FROM field_data_field_gallery_type
              WHERE field_gallery_type_tid = 57 
              ')->fetchAllAssoc('entity_id');
      node_delete_multiple(array_keys($nids)); */
     
     
      db_set_active('old');
      $terms = db_select('term_data','td')->fields('td')->condition('vid',1)->condition('name','%news_%','like')->execute()->fetchAllAssoc('tid');
      $i=0;
      foreach($terms as $_term){
        db_set_active('old'); 
        $images = db_query('SELECT distinct(fid)  
              FROM node n
              INNER JOIN content_type_news cn on cn.nid = n.nid
              INNER JOIN files f on f.nid = cn.field_news_image_nid
              WHERE cn.field_news_image_nid in (SELECT tn.nid from term_node tn where tid='.$_term->tid.' ) and f.filename!=\'thumbnail\'
              GROUP BY n.nid
              ')->fetchAllAssoc('fid');
              $index=0;
              $files_str = '';
              db_set_active('default'); 
              foreach($images as $image){
               if(isset($files_map[$image->fid])){ 
               $file = file_load($files_map[$image->fid]);
                $files_str .= "
                  '$index' => array(
                  'fid' => '$file->fid',
                  'alt' => NULL,
                  'title' => NULL,
                  'uid' => '$file->uid',
                  'filename' => '$file->filename',
                  'uri' => '$file->uri',
                  'filemime' => '$file->filemime',
                  'filesize' => '$file->filesize',
                  'status' => '$file->status',
                  'timestamp' => '$file->timestamp',
                  'type' => '$file->type',
                  'uuid' => '',
                  'rdf_mapping' => array(),
                  ),";
              
                $index++;
               }
               
              }
              
              $gallery_string = "
                array(
  array(
    'vid' => '83',
    'uid' => '1',
    'title' => ".node_export_node_code_encode(str_replace(array('news_','-- ','--'),array('','',''),$_term->name)).",
    'status' => '1',
    'comment' => '1',
    'promote' => '1',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '83',
    'type' => 'gallery',
    'language' => 'ru',
    'created' => '',
    'changed' => '',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '24989c1f-a542-4464-9cdc-9ac02782a131',
    'revision_timestamp' => '1314657314',
    'revision_uid' => '1',
    'body' => array(),
    'field_gallery_images' => array(
      'ru' => array(
        $files_str 
      ),
    ),
    'field_gallery_type' => array(
      'ru' => array(
        '0' => array(
          'tid' => '57',
        ),
      ),
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1314657314',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'timestamp' => 1319746482,
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),
)
              
              ";
             
//              die($gallery_string);
              $result = node_export_import($gallery_string); 
              //die($gallery_string);
              //print_r($mapped_images);
              
               
              /*$nids = db_query('SELECT distinct(entity_id) 
              FROM field_data_field_gallery_type
              WHERE field_gallery_type_tid = 57 
              ')->fetchAllAssoc('entity_id');
              node_delete_multiple(array_keys($nids));
                 */
             /*    
              $gallery = new stdClass();
              $gallery->type = 'gallery';
              $gallery->uid = 1;
              $gallery->language = 'ru';
              $gallery->field_gallery_images = $mapped_images;
              $gallery->field_gallery_type = 57;
              $gallery->title = str_replace('news_','',$_term->name);
                print_r($gallery);
              node_save($gallery);
              
              if($i++ == 10) die();   */
         //$nids = db_select('term_node','tn')->fields('tn')->condition('tid',$_term->tid)->execute()->fetchAllAssoc('tid'); 
          } 
       /* $insert[] = array(
          'tid'=>$_term->tid,
          'vid'=>1,
          'name'=>str_replace('news_','',$_term->name),
          'format'=>'filtered_html',
        );
      }
      
      db_set_active('default'); 
      try{
        foreach($insert as $_insert){
          db_merge('taxonomy_term_data')
          ->key(array('tid'=>$_insert['tid']))
          ->fields($_insert)
          ->execute();
        }  
      }
      catch(PDOException $exc){ print_r($_insert); }*/
      //print_r($insert);
      break;   
       
      
    case 'news':
      module_load_include('inc','node_export','node_export.node_code');
    
      $nids_to_delete = db_query('SELECT nid 
                from node
                where nid in (SELECT new_nid from node_mapping where type=\'node\')
                and type=\'news\'
                ')->fetchCol();
      if(count($nids_to_delete) > 0){
        db_query('DELETE FROM node_mapping where new_nid in ('.implode(',',$nids_to_delete).') and type=\'node\'');
        //node_delete_multiple($nids_to_delete);
      }
      
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1);
     
      for($news_counter=0; $news_counter<50; $news_counter++){         
      db_set_active('old');
      
      $news = db_query_range('SELECT n.*,cn.*,nr.*,f.fid,nc.*
              FROM node n
              INNER JOIN content_type_news cn on cn.vid = n.vid
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN files f on f.nid = cn.field_news_image_nid
              INNER JOIN node_counter nc on nc.nid = n.nid
              WHERE n.type = \'news\' AND f.filename!=\'thumbnail\'
              GROUP BY n.nid
               ',$news_counter*100,100)
      ->fetchAllAssoc('nid');
      if(count($news) == 0) return; 
      
      $old_nids = array();
      $tags = db_select('term_node','tn')->fields('tn')->execute();
      $node_tags = array();
      foreach($tags as $tag){
        $node_tags[$tag->nid][] = $tag->tid;
      }
      
      $categories = array(
        '40'=>'12',
        '41'=>'11',
        '42'=>'10',
        '43'=>'9',
        '44'=>'8',
        '45'=>'7',
        '46'=>'6',
        '47'=>'5',
        '48'=>'4',
        '49'=>'3',
        '31722'=>'2',
        '36388'=>'1',
      );
      
      //for($i=0; $i< count($news)/500; $i++)
      //print_r($node_tags);
      //die();
      //print_r($news); 
      //$file = fopen($_SERVER['DOCUMENT_ROOT'].'/sites/default/files/import.txt','w+');       
      //print_r($_SERVER);
      $news_items = "array(";
      //echo $news_items;
      foreach($news as $_news){
      
        $_node_tags =  'array(';
        $i=0;
        
        if(isset($node_tags[$_news->nid])){
        
          foreach($node_tags[$_news->nid] as $tag){
            $_node_tags .= "'".$i++."' => array('tid'=>'".$tag."'),";  
          }
        }
        $_node_tags .= '),';
        /**
        * array(
        '0' => array(
          'tid' => '315',
        ),
        '1' => array(
          'tid' => '222',
        ),
      ),
        */
       
         
        db_set_active('default');
        
        if(isset($files_map[$_news->fid]))
          $file = file_load($files_map[$_news->fid]);
        else
          $file = new stdClass();  
       
       $old_nids[] = $_news->nid;
       $info[$_news->nid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);   
      $news_items .= "
  array(
    'vid' => '$_news->vid',
    'uid' => '$_news->uid',
    'title' => ".node_export_node_code_encode($_news->title).",
    'log' => '',
    'status' => '$_news->status',
    'comment' => '$_news->comment',
    'promote' => '$_news->promote',
    'sticky' => '$_news->sticky',
    'vuuid' => '',
    'nid' => '$_news->nid',
    'type' => 'news',
    'language' => 'ru',
    'created' => '$_news->created',
    'changed' => '$_news->changed',
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '0bf24492-12fa-4f18-bbc9-61d2cb22ec16',
    'revision_timestamp' =>'$_news->changed',
    'revision_uid' => '$_news->uid',
    'body' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($_news->body).",
          'summary' =>".node_export_node_code_encode($_news->field_teaser_value).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($_news->body).",
          'safe_summary' => ".node_export_node_code_encode($_news->field_teaser_value).",
        ),
      ),
    ),
    'field_news_source' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($_news->field_sourse_value).",
          'format' => NULL,
          'safe_value' => ".node_export_node_code_encode($_news->field_sourse_value).",
        ),
      ),
    ),
    
    'field_news_category' => array(
      'ru' => array(
        '0' => array(
          'tid' => ".$categories[$_news->field_news_type_nid].",
        ),
      ),
    ),
    'field_news_tags' => array(
      'ru' => $_node_tags
    ),
    'field_news_image' => array(
    ".((!empty($file->uri)) ? "
      'ru' => array(
        '0' => array(
          'fid' => '$file->fid',
          'alt' => NULL,
          'title' => NULL,
          'uid' => '$_news->uid',
          'filename' => '$file->filename',
          'uri' => '$file->uri',
          'filemime' => '$file->filemime',
          'filesize' => '$file->filesize',
          'status' => '$file->status',
          'timestamp' => '$file->timestamp',
          'type' => '$file->type',
          'uuid' => '',
          'rdf_mapping' => array(),
        ),
      ),
      " : '')."
    ),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '',
    'last_comment_timestamp' => '',
    'last_comment_name' => '',
    'last_comment_uid' => '',
    'comment_count' => '0',
    'read_count' => '$_news->totalcount',
    'name' => 'admin',
    'picture' => '',
    'data' => 'b:0;',
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      
      $news_items .= ')';
      //echo ')';
     // die();
 
      //die();
      
      $result = node_export_import($news_items);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
      db_set_active('old');                                                                                            
      $counts = db_query('select * from node_counter where nid in ('.implode(',',$old_nids).')')->fetchAllAssoc('nid');
       db_set_active('default'); 
      if(isset($result['nids']))
        foreach($result['nids'] as $_index=>$_nid){
        
          $node = node_load($_nid);
          $node->created = $info[$old_nids[$_index]]['created']; 
          $node->changed = $info[$old_nids[$_index]]['changed']; 
          node_save($node);
          
            db_merge('node_counter')->key(array('nid'=>$_nid))->fields(
              array(
                  'nid'=>$_nid,
                  'totalcount'=>$counts[$old_nids[$_index]]->totalcount,
                  'daycount'=>$counts[$old_nids[$_index]]->daycount,
                  'timestamp'=>$counts[$old_nids[$_index]]->timestamp,
              ))->execute();
                   
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
        
        /*
          db_set_active('old');
      $counts = db_query('select * from node_counter where nid in ('.implode(',',$old_nids).')')->fetchAllAssoc('nid');
       db_set_active('default'); 
      if(isset($result['nids']))
        foreach($result['nids'] as $_index=>$_nid){
        
          $node = node_load($_nid);
          $node->created = $info[$old_nids[$_index]]['created']; 
          $node->changed = $info[$old_nids[$_index]]['changed']; 
          node_save($node);
          
            db_merge('node_counter')->key(array('nid'=>$_nid))->fields(
              array(
                  'nid'=>$_nid,
                  'totalcount'=>$counts[$old_nids[$_index]]->totalcount,
                  'daycount'=>$counts[$old_nids[$_index]]->daycount,
                  'timestamp'=>$counts[$old_nids[$_index]]->timestamp,
              ))->execute();
                   
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        */
        
      //rint_r($news_item);
        
        /*$insert[] = array(
          'fid'=>$_file->fid,
          'uid'=>1,
          'filename'=>$_file->filename,
          'uri'=>"public://old/".$_file->filepath,
          'filemime'=>$_file->filemime,
          'filesize'=>$_file->filesize,
          'status'=>1,
          'timestamp'=>time(),
          'type'=>'image',
        ); */
        //print_r($_news);
        
      
      /*db_set_active('default'); 
      try{
        foreach($news_items as $news_item){
          foreach($news_item as $table=>$fields){
            $key = $fields['key'];
            unset($fields['key']);
            db_merge($table)
          ->key(array($key=>$fields[$key]))
          ->fields($fields)
          ->execute();
          }
          
        }  
      }
      catch(PDOException $exc){ print_r($exc->getMessage()); }
      //print_r($insert);      */
    
      break; 
      
      
      
      
     case 'match':
     db_set_active('default'); 
      module_load_include('inc','node_export','node_export.node_code');
    
      $files_map = db_query('SELECT * FROM node_mapping where type=\'file\'')->fetchAllKeyed(0,1);
      $nodes_map = db_query('SELECT * FROM node_mapping where type=\'node\'')->fetchAllKeyed(0,1);
        
      for($match_counter=0; $match_counter<20; $match_counter++){         
      db_set_active('old');
      
      $matches = db_query_range('SELECT n.*,cn.*,nr.*,tn.tid
              FROM node n
              INNER JOIN content_type_match cn on cn.vid = n.vid
              INNER JOIN node_revisions nr on n.vid = nr.vid
              INNER JOIN term_node tn on tn.nid = n.nid
              WHERE n.type = \'match\'
               ',$match_counter*50,50)
      ->fetchAllAssoc('nid');
      if(count($matches) == 0) return; 
      
      $old_nids = array();
     //print_r($matches);
     //die(); 
     
      
      $seasons = array(
        '7'=>'90',
        '8'=>'91',
        '104'=>'47',
        '339'=>'40',
      );
      
      $tournaments = array(
        '63'=>'38',
        '64'=>'34',
        '148'=>'37',
        '149'=>'35',
        '150'=>'36',
      );
      
      //for($i=0; $i< count($news)/500; $i++)
      //print_r($node_tags);
      //die();
      //print_r($news); 
      //$file = fopen($_SERVER['DOCUMENT_ROOT'].'/sites/default/files/import.txt','w+');       
      //print_r($_SERVER);
      $matches_items = "array(";
      //echo $news_items;
      foreach($matches as $_match){
      
        /*$_node_tags =  'array(';
        $i=0;
        
        if(isset($node_tags[$_match->nid])){
        
          foreach($node_tags[$_news->nid] as $tag){
            $_node_tags .= "'".$i++."' => array('tid'=>'".$tag."'),";  
          }
        }
        $_node_tags .= '),';
        /**
        * array(
        '0' => array(
          'tid' => '315',
        ),
        '1' => array(
          'tid' => '222',
        ),
      ),
        */
       
         
        db_set_active('default');
        
        /*if(isset($files_map[$_match->fid]))
          $file = file_load($files_map[$_news->fid]);
        else
          $file = new stdClass();  
          */
       $old_nids[] = $_match->nid;
       
       $additional_info = (!empty($_match->field_team_membership_value) ? '<b>'.t('Arsenal squad').':</b><br />'.$_match->field_team_membership_value.'<br /><br />' : '').'
       '.(!empty($_match->field_rival_membership_value) ? '<b>'.t('Opponent squad').':</b><br />'.$_match->field_rival_membership_value.'<br /><br /><br />' : '').'
       '.(!empty($_match->field_goal_authors_value) ? '<br /><br /><br /><b>'.t('Goal scorers').':</b> '.$_match->field_goal_authors_value : '').'
       '.(!empty($_match->field_penalty_cards_value) ? '<br /><br /><b>'.t('Yellow cards').':</b> '.$_match->field_penalty_cards_value : '').'
       '.(!empty($_match->field_field_red_cards_value) ? '<br /><br /><b>'.t('Red cards').':</b> '.$_match->field_field_red_cards_value : '').'
       '.(!empty($_match->field_match_video_value) ? '<br /><br /><br /><b>'.t('Match video').':</b><br />'.$_match->field_match_video_value : '').'
       ';
      $matches_items .= "
  array(
    'vid' => '54',
    'uid' => '1',
    'title' => ".node_export_node_code_encode($_match->title).",
    'status' => '1',
    'comment' => '1',
    'promote' => '0',
    'sticky' => '0',
    'vuuid' => '',
    'nid' => '54',
    'type' => 'match',
    'language' => 'ru',
    'created' => '1312837630',
    'changed' => 1321476967,
    'tnid' => '0',
    'translate' => '0',
    'uuid' => '3ef62734-90bd-44ea-be20-146c68b3510f',
    'revision_timestamp' => '1314825215',
    'revision_uid' => '1',
    'field_match_opponent' => array(
      ".(!empty($nodes_map[$_match->field_rival_nid]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_rival_nid]."',
        ),
      ),
      " : '')."
    ),
    'field_match_season' => array(
      'ru' => array(
        '0' => array(
          'tid' => '".$seasons[$_match->tid]."',
        ),
      ),
    ),
    'field_match_tournament' => array(
      'ru' => array(
        '0' => array(
          'tid' => '".$tournaments[$_match->field_tournament_nid]."', 
        ),
      ),
    ),
    'field_match_round' => array(
      'ru' => array(
        '0' => array(
          'value' =>  ".node_export_node_code_encode($_match->field_stage_round_value).",
          'format' => NULL,
          'safe_value' =>  ".node_export_node_code_encode($_match->field_stage_round_value).",
        ),
      ),
    ),
    'field_match_place' => array(
      'ru' => array(
        '0' => array(
          'value' => '".($_match->field_game_placement_value == 'departure' ? 'away' : 'home')."',
        ),
      ),
    ),
    'field_match_start_date' => array(
      'ru' => array(
        '0' => array(
          'value' => '".date('Y-m-d H:i:s',strtotime($_match->field_date_value))."',
          'timezone' => 'Europe/Helsinki',
          'timezone_db' => 'UTC',
          'date_type' => 'datetime',
        ),
      ),
    ),
    'field_match_stadium' => array(
      ".(!empty($nodes_map[$_match->field_stadium_nid]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_stadium_nid]."',
        ),
      ),
      " : '')."
    ),
    'field_match_result' => array(
      'ru' => array(
        '0' => array(
          'value' => '".$_match->field_score_value."',
          'format' => NULL,
          'safe_value' => '".$_match->field_score_value."',
        ),
      ),
    ),
    'field_match_referee' => array(
    ".(!empty($nodes_map[$_match->field_judge_nid]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_judge_nid]."',
        ),
      ),
      " : '')."
    ),
    'field_match_attendance' => array(
    ".(!empty($nodes_map[$_match->field_audience_value]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_audience_value]."',
        ),
      ),
      " : '')."
    ),
    'field_match_report' => array(
      ".(!empty($nodes_map[$_match->field_resume_the_match_nid]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_resume_the_match_nid]."',
        ),
      ),
      " : '')."
    ),
    'field_match_comments' => array(
    ".(!empty($nodes_map[$_match->field_post_after_the_match_nid]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_post_after_the_match_nid]."',
        ),
      ),
      " : '')."
    ),
    'field_match_review' => array(),
    'field_match_before_match' => array(
    ".(!empty($nodes_map[$_match->field_post_before_the_match_nid]) ? "
        'ru' => array(
        '0' => array(
          'nid' => '".$nodes_map[$_match->field_post_before_the_match_nid]."',
        ),
      ),
      " : '')."
    ),
    'field_match_gallery' => array(),
    'field_match_arsenal_squad' => array(),
    'field_match_opponent_squad' => array(),
    'field_match_additional_info' => array(
      'ru' => array(
        '0' => array(
          'value' => ".node_export_node_code_encode($additional_info).",
          'format' => 'full_html',
          'safe_value' => ".node_export_node_code_encode($additional_info).",
        ),
      ),
    ),
    'field_match_events_opponent' => array(),
    'field_match_events' => array(),
    'rdf_mapping' => array(
      'rdftype' => array(
        '0' => 'sioc:Item',
        '1' => 'foaf:Document',
      ),
      'title' => array(
        'predicates' => array(
          '0' => 'dc:title',
        ),
      ),
      'created' => array(
        'predicates' => array(
          '0' => 'dc:date',
          '1' => 'dc:created',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'changed' => array(
        'predicates' => array(
          '0' => 'dc:modified',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
      'body' => array(
        'predicates' => array(
          '0' => 'content:encoded',
        ),
      ),
      'uid' => array(
        'predicates' => array(
          '0' => 'sioc:has_creator',
        ),
        'type' => 'rel',
      ),
      'name' => array(
        'predicates' => array(
          '0' => 'foaf:name',
        ),
      ),
      'comment_count' => array(
        'predicates' => array(
          '0' => 'sioc:num_replies',
        ),
        'datatype' => 'xsd:integer',
      ),
      'last_activity' => array(
        'predicates' => array(
          '0' => 'sioc:last_activity_date',
        ),
        'datatype' => 'xsd:dateTime',
        'callback' => 'date_iso8601',
      ),
    ),
    'cid' => '0',
    'last_comment_timestamp' => '1312837630',
    'last_comment_name' => NULL,
    'last_comment_uid' => '1',
    'comment_count' => '0',
    'name' => 'admin',
    'picture' => '107',
    'data' => 'b:0;',
    'timestamp' => 1321476967,
    'path' => FALSE,
    'menu' => array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => 'main-menu',
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
      'parent_depth_limit' => 8,
      'description' => '',
      'enabled' => 1,
    ),
    'node_export_drupal_version' => '7',
    '#_export_node_encode_object' => '1',
  ),";
      }
      
      $matches_items .= ')';
      //echo ')';
      //die($matches_items);
 
      //die();
      
      $result = node_export_import($matches_items);
      
      //print_r($result);
     //$info[$_news->uid] = array('created' => $_news->created, 'changed' => $_news->changed, 'read_count' => $_news->totalcount);    
       db_set_active('default'); 
      if(isset($result['nids']))
        foreach($result['nids'] as $_index=>$_nid){       
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        
      }
        
        /*
          db_set_active('old');
      $counts = db_query('select * from node_counter where nid in ('.implode(',',$old_nids).')')->fetchAllAssoc('nid');
       db_set_active('default'); 
      if(isset($result['nids']))
        foreach($result['nids'] as $_index=>$_nid){
        
          $node = node_load($_nid);
          $node->created = $info[$old_nids[$_index]]['created']; 
          $node->changed = $info[$old_nids[$_index]]['changed']; 
          node_save($node);
          
            db_merge('node_counter')->key(array('nid'=>$_nid))->fields(
              array(
                  'nid'=>$_nid,
                  'totalcount'=>$counts[$old_nids[$_index]]->totalcount,
                  'daycount'=>$counts[$old_nids[$_index]]->daycount,
                  'timestamp'=>$counts[$old_nids[$_index]]->timestamp,
              ))->execute();
                   
          $data = array('old_nid'=>$old_nids[$_index], 'new_nid'=>$_nid, 'type'=>'node');
          drupal_write_record('node_mapping',$data);
        }
        */
        
      //rint_r($news_item);
        
        /*$insert[] = array(
          'fid'=>$_file->fid,
          'uid'=>1,
          'filename'=>$_file->filename,
          'uri'=>"public://old/".$_file->filepath,
          'filemime'=>$_file->filemime,
          'filesize'=>$_file->filesize,
          'status'=>1,
          'timestamp'=>time(),
          'type'=>'image',
        ); */
        //print_r($_news);
        
      
      /*db_set_active('default'); 
      try{
        foreach($news_items as $news_item){
          foreach($news_item as $table=>$fields){
            $key = $fields['key'];
            unset($fields['key']);
            db_merge($table)
          ->key(array($key=>$fields[$key]))
          ->fields($fields)
          ->execute();
          }
          
        }  
      }
      catch(PDOException $exc){ print_r($exc->getMessage()); }
      //print_r($insert);      */
    
      break; 
      
      case 'node_url_aliases':
        db_set_active('default'); 
        $nodes_map = db_query('SELECT * FROM node_mapping where type=\'node\'')->fetchAllKeyed(0,1);
        
        db_set_active('old');
        $aliases = db_query('SELECT src,dst FROM url_alias where src like \'node/%\'')->fetchAllKeyed();
        db_set_active('default');
        $old_nids = array_keys($nodes_map);
        foreach($aliases as $src => $alias){
          $nid = (int)substr($src,5);
          if($nid > 0 && in_array($nid, $old_nids))
            db_query("INSERT INTO url_alias(source,alias,language) VALUES ('node/".$nodes_map[$nid]."','".$alias."','ru')");
          //echo $nid.'<br>';
          
        }
          //db_query("INSERT INTO url_alias(source,alias,language) VALUES ('".$src."','".$alias."','ru')");
          
        //print_r($aliases);
        die();
        
        
      break;
    
   
       
      
      default:
      break;
  }
  db_set_active('default');
 }
  
  
?>
