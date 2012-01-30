<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title><?php print $head_title ?></title>
<meta name="Keywords" content="Арсенал, Лондон, футбол, ARSSC, Arsenal Russian Speaking Supporters Club, фан-клуб, Хайбери, Арсен Венгер, Анри, Бергкамп, Фабрегас, Адебайор, Ван Перси, Victoria Concordia Crescit, Арсенал в России, Арсенал в СНГ, канониры, гунеры, gunners, gooners, Эмирейтс, Emirates Stadium, Англия, Премьер Лига, Кубок Англии, болельщики, фанаты">
<meta name="Description" content="Официальный сайт Арсенала, Первый официальный фан-сайт, ARSSC, Arsenal Russian Speaking Supporters Club">

<?php print $head ?>
<?php print $styles ?>
<?php print $scripts ?>

<!--[if IE]>
<script src="/misc/jquery.js"></script>
<script src="/misc/drupal.js"></script>
<script src="/sites/all/modules/nice_menus/nice_menus.js"></script>
<![endif]-->

<!--[if lt IE 9]>
	<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->

<link rel="shortcut icon" href="fc_arsenal_theme_favicon.ico" type="image/x-icon">
<link href="<?php print base_path() . path_to_theme();  ?>/css/new-fc-arsenal.css" rel="stylesheet">

</head>
<body class="<?php print $classes;?>" <?php print $attributes;?>>

<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?> 

</body>
</html>