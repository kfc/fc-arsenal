<?php
 echo format_date(strtotime($row->field_field_match_start_date[0]['raw']['value']) + date('Z'),'short') 
?>
