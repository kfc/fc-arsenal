<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ru" lang="ru">
  <head>
    <title><?php print $head_title ?></title>
     <meta name="Keywords" content="Арсенал, Лондон, футбол, ARSSC, Arsenal Russian Speaking Supporters Club, фан-клуб, Хайбери, Арсен Венгер, Анри, Бергкамп, Фабрегас, Адебайор, Ван Перси, Victoria Concordia Crescit, Арсенал в России, Арсенал в СНГ, канониры, гунеры, gunners, gooners, Эмирейтс, Emirates Stadium, Англия, Премьер Лига, Кубок Англии, болельщики, фанаты"/> 
     <meta name="Author" content="Alexandr [Lunya] Lunyov"/> 
     <meta name="Description" content="Официальный сайт Арсенала, Первый официальный фан-сайт, ARSSC, Arsenal Russian Speaking Supporters Club"/>
    <link rel="alternate" type="application/rss+xml" title="RSS" href="http://www.fc-arsenal.com/rss.php" />
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
    <link href="<?php print base_path() . path_to_theme();  ?>/css/fc-arsenal.css" rel="stylesheet" type="text/css">
  </head>
 <body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html> 