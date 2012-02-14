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
      var block = $('div[rel="block-match"]');
      
      //id example match-27
      var id = $(block).attr('id').substring(6);
      if(id > 0)
      {
        $.ajax({
         type: "POST",
         url: "/get_next_match_ajax/"+id,
         success: function(data){
           $(block).html(data['html']);
           $(block).attr('id', "match-"+data['id']);
           updateBlockTitle('next', data['id'], data['last_match_id']);
         }
       });
      }
      return false;
    });
    
    $("#prev-match-link").click(function(){
      var block = $('div[rel="block-match"]');
      var title_text = $('#block-views-matches-next-match h2');
      //id example match-27
      var id = $(block).attr('id').substring(6);
      if(id > 0)
      {
        $.ajax({
         type: "POST",
         url: "/get_prev_match_ajax/"+id,
         success: function(data){
           $(block).html(data['html']);
           $(block).attr('id', "match-"+data['id']);
           updateBlockTitle('prev', data['id'], data['first_match_id']);
         }
       });
      }
      return false;
    });
    
    updateBlockTitle = function(action, result_id, check_id){
      var title_text = $('#block-views-matches-next-match h2');
      if(action == 'prev'){
        if(result_id == check_id)
          $("#prev-match-link").css('visibility','hidden');  
        else{
          //if($('#next-match-link').is(":hidden"))
            $("#next-match-link").css('visibility','visible');  
        }
      }
      if(action == 'next'){  
        if(result_id == check_id)
          $("#next-match-link").css('visibility','hidden');
        else{
          //if($('#prev-match-link').css('visibility','visible'))
            $("#prev-match-link").css('visibility','visible');  
        }
      }
    };
  
  $('#news-node-form').children('#edit-menu-parent option')[0].each(function(){
    console.log($(this));
  
  });  
    
    
  });
})(jQuery);
