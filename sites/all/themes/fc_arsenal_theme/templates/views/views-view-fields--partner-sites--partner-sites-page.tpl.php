<div class="partner-title-wrapper" style="float:left;"><?php echo $fields['title']->content?>.</div>
<div class="partner-banner-wrapper">
  <?php if(!empty($fields['field_partner_link_text'])):?>
    &nbsp;<?php echo $fields['field_partner_link_text']->content;?>
  <?php endif;?>
</div>
<div class="partner-banner-image">   
  <?php if(isset($fields['field_partner_banner_image'])):?>
    <?php echo $fields['field_partner_banner_image']->content;?>
  <?php endif;?>
</div>
<div class="clearfix"></div>
<hr class="partner-split-line">