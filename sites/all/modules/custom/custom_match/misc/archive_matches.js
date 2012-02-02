jQuery(document).ready(function(){
  jQuery('.archive-match-title').click(function(){
    var match_id = jQuery(this).attr('id').substring('archive-match-'.length);  

    if(jQuery('#match-events-'+match_id).is(":visible"))
      jQuery('#match-events-'+match_id).hide();
    else{ 
      jQuery('#match-events-'+match_id).show();   
    }
    return false;
    
  
  });

});