<?php
foreach($rows as $id => $row):
$link = url('node/'.$view->result[$id]->nid,array('absolute'=>TRUE));
?>
<item>
  <title><?php echo $view->result[$id]->node_title?></title>
  <link><?php echo $link;?></link>
<?php $nodeView = node_view(node_load($view->result[$id]->nid));
?>
  <description><![CDATA[
    <?php echo render($nodeView['body']);?>
  ]]>
  </description>
  <pubDate><?php echo date('r',$view->result[$id]->node_created);?></pubDate>
  <guid isPermaLink="false"><?php echo $link.'#full';?></guid>
  <comments><?php echo $link.'#comments';?></comments>
</item>

<?php endforeach;?>
