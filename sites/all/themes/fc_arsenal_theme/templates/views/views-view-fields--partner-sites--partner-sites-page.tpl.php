<div class="partner-title-wrapper"><?php echo $fields['title']->content?></div>
<div class="clearfix"></div>
<div class="partner-banner-wrapper">
  <?php if(isset($fields['field_partner_banner_image'])):?>
    <?php echo $fields['field_partner_banner_image']->content;?>
  <?php endif;?>
  <?php if(!empty($fields['field_partner_link_text'])):?>
    <?php echo $fields['field_partner_link_text']->content;?>
  <?php endif;?>
</div>
<?php if(!empty($fields['field_partner_description'])):?>
  <div class="partner-site-description"> 
    <?php echo $fields['field_partner_description']->content;?>
  </div>
<?php endif;?>
<div class="clearfix"></div>
<hr class="partner-split-line">