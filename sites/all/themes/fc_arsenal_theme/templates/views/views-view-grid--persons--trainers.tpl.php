<?php
/**
 * @file views-view-grid.tpl.php
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
 
 foreach($view->result as $res){
    $tids[]  = $res->field_data_field_person_role_field_person_role_tid;
  }
  $terms = taxonomy_term_load_multiple($tids);  
  $code=  array_shift(array_shift($terms[$title]->field_role_code));
  $code = $code['safe_value'];
  if(is_integer($title) && in_array($title, $tids)){
    if(!empty($terms[$title]->field_role_plural_name)){
      $plural = array_shift(array_shift($terms[$title]->field_role_plural_name));
      $title = $plural['safe_value'];
    }
    else 
      $title = $terms[$title]->name;
  }
  else
    $title = '';
 
?>
<div class="trainers <?php echo 'trainers-'.$code;?>">
<?php if (!empty($title)) : ?>
  <h3><?php print mb_strtoupper(substr($title,0,2), 'UTF-8').mb_strtolower(substr($title,2), 'UTF-8'); ?></h3>
<?php endif; ?>
<?php foreach ($rows as $row_number => $columns): ?>
  <?php foreach ($columns as $column_number => $item):?>
    <?php print $item; ?>
  <?php endforeach; ?>
<?php endforeach; ?>
</div>
