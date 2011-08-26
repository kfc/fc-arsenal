
  <table class="tournament-table-short">
<tbody>
<tr class="tournament-table-short-head">
  <td style=""></td>
    <td style="text-align: left; padding-left:5px;"><?php echo t('Team')?></td>
    <td style=""><?php echo t('Played_short')?></td>
    <td style=""><?php echo t('Points_short')?></td>
</tr>
<?php $i=0;
  foreach($data as $entry):
  $i++;
  if($i >= $indexes['start'] && $i <= $indexes['end']){
  ?>
  <tr class="<?php print ($i%2 == 0? 'odd' :'even');?><?php echo ($entry->team_id == variable_get('arsenal_team_id',0) ?' tournament-table-arsenal-row' : ''); ?>">
    <td style="width: 10px;"><?php echo $i;?></td>
    <td style="width:100px; text-align: left; padding-left:5px;">
    <?php echo $entry->team_name;?>
    </td>
    <td style="width: 20px;"><?php echo $entry->total_games;?></td>
    <td style="width: 20px;"><?php echo $entry->total_points;?></td>
  </tr>
<?php 
}
endforeach;?>
</tbody>
</table>
<div class="tournament-table-short-link-wrapper">
<?php echo l(t('Show full table').'...','tournament-table');?>
</div>
