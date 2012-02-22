<div class="fc-content">
	<table class="tournament-table">
    <caption><?php echo $tournament->name.' '.$season->name?></caption>
	  <tr>
			<th><?php echo t('Position');?></th>
			<th class="team_name"><?php echo t('Team');?></th>
			<th><?php echo t('Games played');?></th>
			<th><?php echo t('Won');?></th>
			<th><?php echo t('Drawn');?></th>
			<th><?php echo t('Lost');?></th>
			<th><?php echo t('Goals for');?></th>
			<th><?php echo t('Goals against');?></th>
			<th><?php echo t('Goal difference');?></th>
			<th><?php echo t('Points');?></th>
		</tr>
		<?php
  		$i=0;
  		foreach($data as $entry):
		?>
		<tr class="<?php print($i++ % 2 == 0 ? 'odd' : 'even');?><?php echo($entry -> team_id == variable_get('arsenal_team_id', 0) ? ' tournament-table-arsenal-row' : '');?>">
			<td><?php echo $i;?></td>
			<td class="team_name"><?php
        echo $entry -> team_name;
			?></td>
			<td><?php echo $entry -> total_games;?></td>
			<td><?php echo $entry -> total_wins;?></td>
			<td><?php echo $entry -> total_draws;?></td>
			<td><?php echo $entry -> total_loses;?></td>
			<td><?php echo $entry -> total_scored;?></td>
			<td><?php echo $entry -> total_missed;?></td>
			<td><?php echo $entry -> goal_difference;?></td>
			<td><?php echo $entry -> total_points;?></td>
		</tr>
		<?php endforeach;?>
	</table>
</div>