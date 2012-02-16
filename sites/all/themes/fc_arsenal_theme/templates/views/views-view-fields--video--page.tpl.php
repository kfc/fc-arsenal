<div class="video-item">
	<div class="video">
		<a rel="lightmodal[|width:660px;height:550px;scrolling: auto;]" href="play_video/<?php echo $fields['nid'] -> raw;?>"><?php echo $fields['field_video_file'] -> content;?></a>
	</div>
	<div class="video-name">
		<a rel="lightmodal[|width:660px;height:550px;scrolling: auto;]" href="play_video/<?php echo $fields['nid'] -> raw;?>"> <?php echo $fields['title']->raw
		?></a>
	</div>
  <?php echo $fields['term_node_tid']->content?>
</div>