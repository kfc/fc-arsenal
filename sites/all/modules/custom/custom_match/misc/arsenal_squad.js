(function ($) {
  $(document).ready(function(){ 
  
    $(".field-name-field-match-arsenal-squad").find(".form-type-checkbox").each(function(){
      var checkbox = $($(this).children('input[type="checkbox"]')[0]);
      var nid = $(checkbox).val();
      
       var lang = $(checkbox).attr('name').replace('field_match_arsenal_squad[','');
        lang = lang.substring(0,lang.indexOf(']'));
       
      if($(checkbox).attr('checked'))
        $(".form-item-field-match-arsenal-squad-subs-"+lang+"-"+nid).hide();
        
      $(checkbox).click(function(){
        if($(this).attr('checked'))
          $(".form-item-field-match-arsenal-squad-subs-"+lang+"-"+nid).hide();
        else
          $(".form-item-field-match-arsenal-squad-subs-"+lang+"-"+nid).show();    
      });
    });
    
    
    $(".field-name-field-match-arsenal-squad-subs").find(".form-type-checkbox").each(function(){
      var checkbox = $($(this).children('input[type="checkbox"]')[0]);
      var nid = $(checkbox).val();
      
       var lang = $(checkbox).attr('name').replace('field_match_arsenal_squad_subs[','');
        lang = lang.substring(0,lang.indexOf(']'));
       
      if($(checkbox).attr('checked'))
        $(".form-item-field-match-arsenal-squad-"+lang+"-"+nid).hide();
        
      $(checkbox).click(function(){
        if($(this).attr('checked'))
          $(".form-item-field-match-arsenal-squad-"+lang+"-"+nid).hide();
        else
          $(".form-item-field-match-arsenal-squad-"+lang+"-"+nid).show();    
      });
    });
    
  });
})(jQuery);