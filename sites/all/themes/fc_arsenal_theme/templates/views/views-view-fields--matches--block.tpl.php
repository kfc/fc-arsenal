<div class="match-block" rel="block-<?php echo $view->display[$view->current_display]->id;?>" id="match-<?php echo $fields['nid']->raw?>">
  <div class="players">
    <div class="team-block">
      <div class="emblems-line">
        <?php echo $variables['match']['teams']['first']['img'];?>
      </div>
      <div class="team-names-line"><?php echo $variables['match']['teams']['first']['name'];?></div>
    </div>
    <div class="vs">VS</div>
    <div class="team-block">
      <div class="emblems-line">
        <?php echo $variables['match']['teams']['second']['img'];?>
      </div>
      <div class="team-names-line"><?php echo $variables['match']['teams']['second']['name'];?></div>
    </div>
    <div class="cf">&nbsp;</div>
  </div>            
  <div class="score"><?php echo $variables['match']['score'];?></div>
  <div class="tournament-type"><?php echo render($fields['field_match_tournament']->content);?></div>
  <div class="date"> <?php echo $variables['match']['start_date'];?></div>
  <div class="footer">
    <?php echo render($fields['nid']->content);?>
    <?php if($variables['additional_link']):?>
    <span class="online-link">
      | <?php echo $variables['additional_link'];?>
      </span>
    <?endif;?>               
  </div>
</div>