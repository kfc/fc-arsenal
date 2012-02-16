<div class="book-item">
	<div class="book-cover"><?php echo $fields['field_book_cover'] -> content;?></div>
	<div class="book-info">
		<div class="book-name"><?php echo $fields['title'] -> content;?></div>
		<div class="book-author"><?php echo $fields['field_book_author'] -> content;?></div>
		<?php $file = file_load($fields['field_book_file'] -> content);
      $pathinfo = pathinfo($file -> uri);
		?>
		<div class="file-format"><?php echo t('File format')?>:<span class="extension"><?php echo strtolower($pathinfo['extension']);?></span></div>
		<div class="download-link"><?php echo l(theme('image',array('path'=>drupal_get_path('theme','fc_arsenal_theme').'/img/download-icon-small.png','width'=>'16px')).t('Download book') , 'file_download/'.$fields['field_book_file']->content,array('html'=>TRUE, 'attributes'=>array('title'=>t('Download file').' "'.$fields['title']->content.'"')))?></div>
	</div>
	<div class="cf">&nbsp;</div>
</div>