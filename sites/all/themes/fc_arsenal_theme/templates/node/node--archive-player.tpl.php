<?php    
  if(empty($node->field_ap_photo)){
    $path = drupal_get_path('theme',variable_get('theme_default','fc_arsenal_theme'));
    $image_path = $path.'/img/no-photo.jpg';  
    $image = theme_image(array('path'=>$image_path));
  } else {
    $image = theme_image_style(array('style_name'=>'player_photo','path'=>$node->field_ap_photo[$node->language][0]['uri']));
  }
  $position_field = field_info_field('field_ap_position');
  $positions = $position_field['settings']['allowed_values'];
  dpm($position_field);
?>
<div class="player-page">

    <div class="player-box-info">
      <!--h2>
      <?php echo $node->title; ?>
      </h2-->
      <div class="photo"><?php print $image; ?></div>
      <div class="box-content">
      
      <?php if(!empty($node->field_ap_original_name)) { ?>
        <div class="position"><span class="label"><?php echo t('Original name')?>:</span> <?php print $node->field_ap_original_name[$node->language][0]['safe_value']; ?>
        </div>
      <?php } ?>

      <?php if(!empty($node->field_ap_bithdate)) { ?>
        <div class="birtday"><span class="label"><?php echo t('Date of birth')?>:</span> <?php print date('d.m.Y', strtotime($node->field_ap_bithdate[$node->language][0]['value'])); ?></div>
      <?php } ?>
      
       <?php if(!empty($node->field_ap_years)) { ?>
        <div class="birtday"><span class="label"><?php echo t('Years in Arsenal')?>:</span> <?php print $node->field_ap_years[$node->language][0]['safe_value']; ?></div>
      <?php } ?>
      
       <?php if(!empty($node->field_ap_position)) { ?>
        <div class="position"><span class="label"><?php echo t('Player position')?>:</span> <?php print $positions[$node->field_ap_position[$node->language][0]['value']]; ?>
        </div>
      <?php } ?>
      
       <?php if(!empty($node->field_ap_games)) { ?>
        <div class="birtday"><span class="label"><?php echo t('Games')?>:</span> <?php print $node->field_ap_games[$node->language][0]['safe_value']; ?></div>
      <?php } ?>
      
       <?php if(!empty($node->field_ap_goals)) { ?>
        <div class="birtday"><span class="label"><?php echo t('Goals')?>:</span> <?php print $node->field_ap_goals[$node->language][0]['safe_value']; ?></div>
      <?php } ?>
      
       <?php if(!empty($node->field_ap_trophies)) { ?>
        <div class="birtday"><span class="label"><?php echo t('Trophies')?>:</span><br /><?php print nl2br($node->field_ap_trophies[$node->language][0]['safe_value']); ?></div>
      <?php } ?>
      

      </div>
    </div>

    <?php if(!empty($node->field_ap_biography)):?>
      <!--h2><?php echo t('Biography')?></h2-->
      <div class="player-info"><?php print $node->field_ap_biography[$node->language][0]['safe_value']; ?></div>
    <?php endif;?>
  <div class="cf">&nbsp;</div>
</div>
<?php print render($content);?>