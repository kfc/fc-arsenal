<?php
/**
 * @file
 * conten_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function conten_types_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Статья'),
      'base' => 'node_content',
      'description' => t('Статья — это документ, который обычно используется для новостей, анонсов и любых других сообщений, для которых не задействованы другие типы документов. Этот тип документа также используют для ведения персонального блога. По умолчанию, документы этого типа выводятся на первую страницу сайта и их разрешено комментировать.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'audio' => array(
      'name' => t('Аудиофайл'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'banner' => array(
      'name' => t('Баннер'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'biography' => array(
      'name' => t('Биография'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Имя'),
      'help' => '',
    ),
    'book' => array(
      'name' => t('Книга'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'gallery' => array(
      'name' => t('Галерея'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'match' => array(
      'name' => t('Матч'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('Новость'),
      'base' => 'node_content',
      'description' => t('Раздел «Новости». Добавление новости'),
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Страница'),
      'base' => 'node_content',
      'description' => t('Страница — это документ, который используется для страниц с редко изменяемой информацией. Например, таких страниц как «О сайте» или «Наш адрес». По умолчанию, документы этого типа не выводятся на первую страницу сайта и их комментирование отключено.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'partner_site' => array(
      'name' => t('Дружественный сайт'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название ресурса'),
      'help' => '',
    ),
    'person' => array(
      'name' => t('Персона'),
      'base' => 'node_content',
      'description' => t('Игроки, тренеры, руководство клуба и т.п'),
      'has_title' => '1',
      'title_label' => t('Имя'),
      'help' => '',
    ),
    'referee' => array(
      'name' => t('Судья'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Имя'),
      'help' => '',
    ),
    'stadium' => array(
      'name' => t('Стадион'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Команда'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Видео'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'wallpaper' => array(
      'name' => t('Обои'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
  );
  return $items;
}
