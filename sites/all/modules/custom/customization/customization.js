(function ($) {
  $(document).ready(function(){
  $('.node-form #edit-menu-parent option').each(function(){
    if($(this).html().substring(0,6)=='------'){                                          
      $(".node-form #edit-menu-parent option[value='"+$(this).val()+"']").remove();  
    }
  
  });  
    
    
  });
})(jQuery);