(function ($) {
  $(document).ready(function(){
    ///for tabs
    //show active
    $('#node-match .tabs .header .tab').click(function(){
  	  number = this.id;
		  $('div.tabs .header .tab').removeClass("tab-active");
      $('div.tabs .header #'+number).addClass("tab-active");
      $('div.tabs .content .tab').removeClass("tab-active");
      $('div.tabs .content #'+number+'content').addClass("tab-active");
    });
    
    
    $("#next-match-link").click(function(){
      var block = $('div[rel="block-next_match"]');
      
      //id example match-27
      var id = $(block).attr('id').substring(6);
      if(id > 0)
      {
        //get_next_match_ajax
        //jQuery.ajax( 'get_next_match_ajax/12');
        $.ajax({
         type: "POST",
         url: "get_next_match_ajax/"+id,
         success: function(data){
           $(block).html(data['html']);
           $(block).attr('id', "match-"+data['id']);
         }
       });
      }
      return false;
    });
    
    
    //$("object").wrap("<div></div>");
  });
})(jQuery);
