<div rel="block-match" id="match-<?php echo $fields['nid']->raw?>">
	<div class="team-block">
		<div class="team">
			<div class="team-emblem"><?php echo $variables['match']['teams']['first']['img'];?></div>
			<div class="team-name"><?php echo $variables['match']['teams']['first']['name'];?></div>
		</div>
		<div class="vs">VS</div>
		<div class="team">
			<div class="team-emblem"><?php echo $variables['match']['teams']['second']['img'];?></div>
			<div class="team-name"><?php echo mb_wordwrap($variables['match']['teams']['second']['name'], 10, '<br />', 1);?></div>
		</div>
	</div>
	<div class="score"><?php echo $variables['match']['score'];?></div>
	<div class="tournament-type"><?php echo render($fields['field_match_tournament'] -> content);?></div>
	<div class="match-date"><?php echo $variables['match']['start_date'];?></div>
	<div class="match-links">
  	<?php echo render($fields['nid'] -> content);?><?php if($variables['additional_link']):?><?php echo $variables['additional_link'];?><?endif;?>
  </div>
</div>