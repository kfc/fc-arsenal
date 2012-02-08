<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
  <?php if (!empty($rows)) : ?>
    <caption><?php print t('Season').' '.$rows[0]['field_match_season']; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label):
        if(in_array($field, array('field_match_place','field_match_result','field_match_opponent','field_match_season')))
            continue;
       ?>
        <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row):?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
        <?php foreach ($row as $field => $content):
          if(in_array($field, array('field_match_place','field_match_result','field_match_opponent','field_match_season')))
            continue;
          if($field == 'nid'){
            $home_team = ($row['field_match_place'] == 'away' ? $row['field_match_opponent'] : t('Arsenal'));  
            $away_team = ($row['field_match_place'] == 'away' ? t('Arsenal') : $row['field_match_opponent']);  
            $goal_diff = intval(trim(substr($row['field_match_result'],0,strpos($row['field_match_result'],':'))) - trim(substr($row['field_match_result'],strpos($row['field_match_result'],':')+1)));
            $result_class = ($goal_diff == 0 ? 'result_draw' : ($goal_diff > 0 && $home_team == t('Arsenal') || $goal_diff < 0 && $away_team == t('Arsenal') ? 'result_win' : 'result_lost'));
            
            $content = str_replace(array('{HOME_TEAM}','{AWAY_TEAM}','{RESULT}','{RESULT_CLASS}'),array($home_team, $away_team, $row['field_match_result'], $result_class), $content);
          }
         ?>
          <td <?php if ($field_classes[$field][$count]) { print 'class="'. $field_classes[$field][$count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$count]); ?>>
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
