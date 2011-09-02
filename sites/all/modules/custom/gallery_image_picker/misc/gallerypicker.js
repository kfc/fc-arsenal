(function ($) {
  $(document).ready(function(){ 
    
    $('[rel=image_gallerypicker]').change(function(){  
      var nid = $(this).val();   
      var field_id = $(this).attr('id').substring('gallerypicker_gallery_select_'.length);
      var image_wrapper_div = $('#image_gallerypicker_images_wrapper_'+field_id);
      if(nid > 0)
      {
        $.ajax({
         type: "POST",
         url: "/get_gallery_images/"+nid,
         beforeSend: function(){
          $(image_wrapper_div).html('<div style="background: url(/misc/progress.gif) repeat-x; height:20px; width: 100%;"></div>'); 
         },
         success: function(data){  
           $(image_wrapper_div).html(data['html']);
           checkSelected();
           $('[rel=image_item_gallerypicker]').each(function(){
            $(this).click(function(){
              var value = $("#image_gallery_picker_selected_value").val();
              if(value != $(this).attr('id').substring(4))
                $("#"+'fid_'+value).removeClass('active');
              $(this).addClass('active');
              $("#image_gallery_picker_selected_value").val($(this).attr('id').substring(4));
    
          });
          });
         }
       });
      }
      else
        $(image_wrapper_div).html(Drupal.t('No image selected'));  
      
      return false;
    
    }); 
    
    function checkSelected(){
      var value = $("#image_gallery_picker_selected_value").val();
      $('[rel=image_item_gallerypicker]').each(function(){
        if($(this).attr('id') == 'fid_'+value) {
          $(this).addClass('active');
        }
      });
    };
    
    //fire event on startup
    $('[rel=image_gallerypicker]').trigger('change');
    
    
  });  
})(jQuery);