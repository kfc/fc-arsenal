<div class="chatroom-chat-page">
<?php if ($messages): print $messages; endif; ?>

<!-- BOF: CHAT-CONTENT -->
	<div id="content">
	<?php print $content;?>
	</div>
<!-- EOF: CHAT-CONTENT -->

<!-- BOF: RIGHT MENU -->
	<div id="right-menu" class="side-menu">
		<div class="block">
			<h2>Пользователи в чате</h2>
			<div class="contet">
				<?php 
				 $online_users_block = theme('chatroom_block_chat_online_list');
				 print $online_users_block['content'];
				?>
			</div>
		</div>
		<?php if(user_access('administer chats')) {?>
		<div class="block">
			<h2>Команды чата</h2>
			<div class="contet">
				<?php 
				 $commands_block = theme('chatroom_block_commands');
				 print $commands_block['content'];
				?>
			</div>
		</div>
		<?php } ?>
	</div>
	
<!-- EOF: RIGHT MENU -->
<div class="cf">&nbsp;</div>
</div>