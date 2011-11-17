<?php
/**
 * @file
 * feature_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_views_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'articles';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Легенды клуба';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Заголовок: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_biography_image']['id'] = 'field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['table'] = 'field_data_field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['field'] = 'field_biography_image';
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Содержимое: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'biography' => 'biography',
  );

  /* Display: Легенды */
  $handler = $view->new_display('page', 'Легенды', 'legends');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class'] = 'biography-list-column';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'center-align';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_biography_image']['id'] = 'field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['table'] = 'field_data_field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['field'] = 'field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['label'] = '';
  $handler->display->display_options['fields']['field_biography_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_biography_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_biography_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['element_class'] = 'center-align';
  $handler->display->display_options['fields']['field_biography_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['empty'] = '<img src="/sites/all/themes/fc_arsenal_theme/img/old_logo_big.png" height="100" />';
  $handler->display->display_options['fields']['field_biography_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_biography_image']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_biography_image]';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'center-align';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'biography' => 'biography',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '71',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'biography_category';
  $handler->display->display_options['path'] = 'legends';

  /* Display: Биографии */
  $handler = $view->new_display('page', 'Биографии', 'biographies');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Биографии игроков';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class'] = 'biography-list-column';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'center-align';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_biography_image']['id'] = 'field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['table'] = 'field_data_field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['field'] = 'field_biography_image';
  $handler->display->display_options['fields']['field_biography_image']['label'] = '';
  $handler->display->display_options['fields']['field_biography_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_biography_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['path'] = 'node/[field_nid]';
  $handler->display->display_options['fields']['field_biography_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_biography_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_biography_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['element_class'] = 'center-align';
  $handler->display->display_options['fields']['field_biography_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['empty'] = '<img src="/sites/all/themes/fc_arsenal_theme/img/old_logo_big.png" height="100" />';
  $handler->display->display_options['fields']['field_biography_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_biography_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_biography_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_biography_image']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_biography_image]';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'center-align';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'biography' => 'biography',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['operator'] = 'not';
  $handler->display->display_options['filters']['tid']['value'] = array(
    71 => '71',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'biography_category';
  $handler->display->display_options['path'] = 'biographies';

  /* Display: Статьи */
  $handler = $view->new_display('page', 'Статьи', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Заголовок: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = '%1';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['path'] = 'articles/%';
  $translatables['articles'] = array(
    t('Master'),
    t('Легенды клуба'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Изображение'),
    t('Все'),
    t('Легенды'),
    t('<img src="/sites/all/themes/fc_arsenal_theme/img/old_logo_big.png" height="100" />'),
    t('[field_biography_image]'),
    t('Биографии'),
    t('Биографии игроков'),
    t('node/[field_nid]'),
    t('Статьи'),
    t('%1'),
  );
  $export['articles'] = $view;

  $view = new view;
  $view->name = 'audio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'audio';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'audio';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content revision: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'audio' => 'audio',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Аудиофайлы';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content revision: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['path'] = 'audio';
  $translatables['audio'] = array(
    t('Master'),
    t('audio'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Page'),
    t('Аудиофайлы'),
  );
  $export['audio'] = $view;

  $view = new view;
  $view->name = 'books';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'books';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'books';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: Файл */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Библиотека';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Поле: Содержимое: Автор */
  $handler->display->display_options['fields']['field_book_author']['id'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['fields']['field_book_author']['field'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_author']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_book_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_author']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_author']['field_api_classes'] = 0;
  /* Поле: Содержимое: Обложка */
  $handler->display->display_options['fields']['field_book_cover']['id'] = 'field_book_cover';
  $handler->display->display_options['fields']['field_book_cover']['table'] = 'field_data_field_book_cover';
  $handler->display->display_options['fields']['field_book_cover']['field'] = 'field_book_cover';
  $handler->display->display_options['fields']['field_book_cover']['label'] = '';
  $handler->display->display_options['fields']['field_book_cover']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_cover']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_cover']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_book_cover']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_book_cover']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_book_cover']['type'] = 'lightbox2__image__book_cover__original';
  $handler->display->display_options['fields']['field_book_cover']['settings'] = array(
    'image_style' => 'book_cover',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_book_cover']['field_api_classes'] = 0;
  /* Поле: Содержимое: Файл */
  $handler->display->display_options['fields']['field_book_file']['id'] = 'field_book_file';
  $handler->display->display_options['fields']['field_book_file']['table'] = 'field_data_field_book_file';
  $handler->display->display_options['fields']['field_book_file']['field'] = 'field_book_file';
  $handler->display->display_options['fields']['field_book_file']['label'] = '';
  $handler->display->display_options['fields']['field_book_file']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_book_file']['alter']['text'] = '[field_book_file-fid]';
  $handler->display->display_options['fields']['field_book_file']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_book_file']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_book_file']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_book_file']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_book_file']['element_type'] = '0';
  $handler->display->display_options['fields']['field_book_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_book_file']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_book_file']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_book_file']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_book_file']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_book_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_book_file']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'books';
  $translatables['books'] = array(
    t('Master'),
    t('books'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Файл'),
    t('Page'),
    t('Библиотека'),
    t('Автор'),
    t('[field_book_file-fid]'),
  );
  $export['books'] = $view;

  $view = new view;
  $view->name = 'gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Gallery';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery' => 'gallery',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'gallery_type';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;

  /* Display: References */
  $handler = $view->new_display('references', 'References', 'references_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery' => 'gallery',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    58 => '58',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'gallery_type';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  $translatables['gallery'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('References'),
  );
  $export['gallery'] = $view;

  $view = new view;
  $view->name = 'gallery_image_picker';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Gallery Image Picker';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: Файл */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Поле: Содержимое: Картинки */
  $handler->display->display_options['fields']['field_gallery_images']['id'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['field'] = 'field_gallery_images';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Содержимое: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Gallery Images */
  $handler = $view->new_display('block', 'Gallery Images', 'gallery_images');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '10';
  $handler->display->display_options['style_options']['fill_single_line'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: Файл */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Файл: ID файла */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['fid']['link_to_file'] = 0;
  /* Поле: Файл: Путь */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['uri']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uri']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uri']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['uri']['link_to_file'] = 0;
  $handler->display->display_options['fields']['uri']['file_download_path'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $translatables['gallery_image_picker'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Файл'),
    t('Картинки'),
    t('Все'),
    t('Gallery Images'),
  );
  $export['gallery_image_picker'] = $view;

  $view = new view;
  $view->name = 'image_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'image_gallery';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Галереи';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Заголовок: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_wallpaper_image']['id'] = 'field_wallpaper_image';
  $handler->display->display_options['fields']['field_wallpaper_image']['table'] = 'field_data_field_wallpaper_image';
  $handler->display->display_options['fields']['field_wallpaper_image']['field'] = 'field_wallpaper_image';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery' => 'gallery',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Фото-галереи';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Галереи не найдены';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Картинки */
  $handler->display->display_options['fields']['field_gallery_images']['id'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['path'] = 'gallery/[nid]';
  $handler->display->display_options['fields']['field_gallery_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['element_type'] = '0';
  $handler->display->display_options['fields']['field_gallery_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images']['settings'] = array(
    'image_style' => 'image_gallery_cover_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_gallery_images']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_gallery_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_images']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['separator'] = '';
  $handler->display->display_options['fields']['field_gallery_images']['field_api_classes'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'image_gallery_title_link';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_gallery_images]';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'gallery/[nid]';
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery' => 'gallery',
  );
  /* Filter criterion: Содержимое: Тип галереи (field_gallery_type) */
  $handler->display->display_options['filters']['field_gallery_type_tid']['id'] = 'field_gallery_type_tid';
  $handler->display->display_options['filters']['field_gallery_type_tid']['table'] = 'field_data_field_gallery_type';
  $handler->display->display_options['filters']['field_gallery_type_tid']['field'] = 'field_gallery_type_tid';
  $handler->display->display_options['filters']['field_gallery_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gallery_type_tid']['expose']['operator_id'] = 'field_gallery_type_tid_op';
  $handler->display->display_options['filters']['field_gallery_type_tid']['expose']['operator'] = 'field_gallery_type_tid_op';
  $handler->display->display_options['filters']['field_gallery_type_tid']['expose']['identifier'] = 'field_gallery_type_tid';
  $handler->display->display_options['filters']['field_gallery_type_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_gallery_type_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_gallery_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_gallery_type_tid']['vocabulary'] = 'gallery_type';
  $handler->display->display_options['filters']['field_gallery_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_gallery_type_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'gallery';

  /* Display: Последняя фото-галерея */
  $handler = $view->new_display('block', 'Последняя фото-галерея', 'latest_gallery');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Фото';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: Файл */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Картинки */
  $handler->display->display_options['fields']['field_gallery_images']['id'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['table'] = 'field_data_field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['field'] = 'field_gallery_images';
  $handler->display->display_options['fields']['field_gallery_images']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_images']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['element_type'] = '0';
  $handler->display->display_options['fields']['field_gallery_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_images']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_images']['type'] = 'lightbox2__image__square_thumbnail__original';
  $handler->display->display_options['fields']['field_gallery_images']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_gallery_images']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_gallery_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_gallery_images']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_gallery_images']['separator'] = '';
  $handler->display->display_options['fields']['field_gallery_images']['field_api_classes'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[first_photo_url]" rel="lightbox[gallery]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';

  /* Display: Страница */
  $handler = $view->new_display('page', 'Страница', 'gallery_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Заголовок: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/gallery">&lt;&lt; Вернуться к списку галерей</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: Файл */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Файл: Путь */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uri']['element_type'] = '0';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['uri']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uri']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uri']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['uri']['link_to_file'] = 0;
  $handler->display->display_options['fields']['uri']['file_download_path'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['path'] = 'gallery/%';

  /* Display: Обои */
  $handler = $view->new_display('page', 'Обои', 'wallpapers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Обои';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: Файл */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_wallpaper_image']['id'] = 'field_wallpaper_image';
  $handler->display->display_options['fields']['field_wallpaper_image']['table'] = 'field_data_field_wallpaper_image';
  $handler->display->display_options['fields']['field_wallpaper_image']['field'] = 'field_wallpaper_image';
  $handler->display->display_options['fields']['field_wallpaper_image']['label'] = '';
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_wallpaper_image']['element_class'] = 'wallpaper-thumb-wrapper';
  $handler->display->display_options['fields']['field_wallpaper_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wallpaper_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_wallpaper_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_wallpaper_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_wallpaper_image']['type'] = 'lightbox2__image__square_thumbnail__wallpaper_preview';
  $handler->display->display_options['fields']['field_wallpaper_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_wallpaper_image']['field_api_classes'] = 0;
  /* Поле: Файл: ID файла */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['text'] = '<img src="/sites/all/themes/fc_arsenal_theme/img/download-icon-small.png" width="16" height="16" />';
  $handler->display->display_options['fields']['fid']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['path'] = 'wallpaper_download/[fid]';
  $handler->display->display_options['fields']['fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['alt'] = 'Сохранить на диск';
  $handler->display->display_options['fields']['fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fid']['element_type'] = '0';
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['fid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['fid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['fid']['link_to_file'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'wallpaper' => 'wallpaper',
  );
  $handler->display->display_options['path'] = 'wallpapers';
  $translatables['image_gallery'] = array(
    t('Master'),
    t('Галереи'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Изображение'),
    t('Все'),
    t('Page'),
    t('Фото-галереи'),
    t('Применить'),
    t('Галереи не найдены'),
    t('gallery/[nid]'),
    t('[field_gallery_images]'),
    t('Последняя фото-галерея'),
    t('Фото'),
    t('Файл'),
    t('<a href="[first_photo_url]" rel="lightbox[gallery]">[title]</a>'),
    t('Страница'),
    t('<a href="/gallery">&lt;&lt; Вернуться к списку галерей</a>'),
    t('Обои'),
    t('<img src="/sites/all/themes/fc_arsenal_theme/img/download-icon-small.png" width="16" height="16" />'),
    t('wallpaper_download/[fid]'),
    t('Сохранить на диск'),
    t('[title]'),
  );
  $export['image_gallery'] = $view;

  $view = new view;
  $view->name = 'matches';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'matches';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Поле: Содержимое: События Арсенала */
  $handler->display->display_options['fields']['field_match_events']['id'] = 'field_match_events';
  $handler->display->display_options['fields']['field_match_events']['table'] = 'field_data_field_match_events';
  $handler->display->display_options['fields']['field_match_events']['field'] = 'field_match_events';
  /* Поле: Содержимое: События соперника */
  $handler->display->display_options['fields']['field_match_events_opponent']['id'] = 'field_match_events_opponent';
  $handler->display->display_options['fields']['field_match_events_opponent']['table'] = 'field_data_field_match_events_opponent';
  $handler->display->display_options['fields']['field_match_events_opponent']['field'] = 'field_match_events_opponent';
  /* Sort criterion: Содержимое: События соперника (field_match_events_opponent:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_match_events_opponent';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'match' => 'match',
  );

  /* Display: Последний матч */
  $handler = $view->new_display('block', 'Последний матч', 'prev_match');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Последний матч';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Содержимое: Противник (field_match_opponent) */
  $handler->display->display_options['relationships']['field_match_opponent_nid']['id'] = 'field_match_opponent_nid';
  $handler->display->display_options['relationships']['field_match_opponent_nid']['table'] = 'field_data_field_match_opponent';
  $handler->display->display_options['relationships']['field_match_opponent_nid']['field'] = 'field_match_opponent_nid';
  $handler->display->display_options['relationships']['field_match_opponent_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_match_opponent_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Противник */
  $handler->display->display_options['fields']['field_match_opponent']['id'] = 'field_match_opponent';
  $handler->display->display_options['fields']['field_match_opponent']['table'] = 'field_data_field_match_opponent';
  $handler->display->display_options['fields']['field_match_opponent']['field'] = 'field_match_opponent';
  $handler->display->display_options['fields']['field_match_opponent']['label'] = '';
  $handler->display->display_options['fields']['field_match_opponent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_opponent']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_match_opponent']['field_api_classes'] = 0;
  /* Поле: Содержимое: Где играют */
  $handler->display->display_options['fields']['field_match_place']['id'] = 'field_match_place';
  $handler->display->display_options['fields']['field_match_place']['table'] = 'field_data_field_match_place';
  $handler->display->display_options['fields']['field_match_place']['field'] = 'field_match_place';
  $handler->display->display_options['fields']['field_match_place']['label'] = '';
  $handler->display->display_options['fields']['field_match_place']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_place']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_place']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_place']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_place']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_place']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_place']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_place']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_match_place']['field_api_classes'] = 0;
  /* Поле: Содержимое: Дата и время начала */
  $handler->display->display_options['fields']['field_match_start_date']['id'] = 'field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['field'] = 'field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_match_start_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_start_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['type'] = 'date_long';
  $handler->display->display_options['fields']['field_match_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_match_start_date']['field_api_classes'] = 0;
  /* Поле: Содержимое: Стадия/Тур */
  $handler->display->display_options['fields']['field_match_round']['id'] = 'field_match_round';
  $handler->display->display_options['fields']['field_match_round']['table'] = 'field_data_field_match_round';
  $handler->display->display_options['fields']['field_match_round']['field'] = 'field_match_round';
  $handler->display->display_options['fields']['field_match_round']['label'] = '';
  $handler->display->display_options['fields']['field_match_round']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_round']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_round']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_round']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_round']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_round']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_round']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_round']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_round']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_match_round']['field_api_classes'] = 0;
  /* Поле: Содержимое: Турнир */
  $handler->display->display_options['fields']['field_match_tournament']['id'] = 'field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['table'] = 'field_data_field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['field'] = 'field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['label'] = '';
  $handler->display->display_options['fields']['field_match_tournament']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_tournament']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_match_tournament']['field_api_classes'] = 0;
  /* Поле: Содержимое: Счёт */
  $handler->display->display_options['fields']['field_match_result']['id'] = 'field_match_result';
  $handler->display->display_options['fields']['field_match_result']['table'] = 'field_data_field_match_result';
  $handler->display->display_options['fields']['field_match_result']['field'] = 'field_match_result';
  $handler->display->display_options['fields']['field_match_result']['label'] = '';
  $handler->display->display_options['fields']['field_match_result']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_result']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_result']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_result']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_result']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_result']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_result']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_result']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_result']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_match_result']['field_api_classes'] = 0;
  /* Поле: Содержимое: Эмблема */
  $handler->display->display_options['fields']['field_team_logo']['id'] = 'field_team_logo';
  $handler->display->display_options['fields']['field_team_logo']['table'] = 'field_data_field_team_logo';
  $handler->display->display_options['fields']['field_team_logo']['field'] = 'field_team_logo';
  $handler->display->display_options['fields']['field_team_logo']['relationship'] = 'field_match_opponent_nid';
  $handler->display->display_options['fields']['field_team_logo']['label'] = '';
  $handler->display->display_options['fields']['field_team_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_team_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_logo']['settings'] = array(
    'image_style' => 'team_logo_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_team_logo']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'матч-центр';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Дата и время начала (field_match_start_date) */
  $handler->display->display_options['sorts']['field_match_start_date_value']['id'] = 'field_match_start_date_value';
  $handler->display->display_options['sorts']['field_match_start_date_value']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['sorts']['field_match_start_date_value']['field'] = 'field_match_start_date_value';
  $handler->display->display_options['sorts']['field_match_start_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'match' => 'match',
  );
  /* Filter criterion: Содержимое: Дата и время начала (field_match_start_date) */
  $handler->display->display_options['filters']['field_match_start_date_value']['id'] = 'field_match_start_date_value';
  $handler->display->display_options['filters']['field_match_start_date_value']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['filters']['field_match_start_date_value']['field'] = 'field_match_start_date_value';
  $handler->display->display_options['filters']['field_match_start_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_match_start_date_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_match_start_date_value']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['field_match_start_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_match_start_date_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_match_start_date_value']['year_range'] = '-3:+3';

  /* Display: Следующий матч */
  $handler = $view->new_display('block', 'Следующий матч', 'next_match');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Матч';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Содержимое: Противник (field_match_opponent) */
  $handler->display->display_options['relationships']['field_match_opponent_nid']['id'] = 'field_match_opponent_nid';
  $handler->display->display_options['relationships']['field_match_opponent_nid']['table'] = 'field_data_field_match_opponent';
  $handler->display->display_options['relationships']['field_match_opponent_nid']['field'] = 'field_match_opponent_nid';
  $handler->display->display_options['relationships']['field_match_opponent_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_match_opponent_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Противник */
  $handler->display->display_options['fields']['field_match_opponent']['id'] = 'field_match_opponent';
  $handler->display->display_options['fields']['field_match_opponent']['table'] = 'field_data_field_match_opponent';
  $handler->display->display_options['fields']['field_match_opponent']['field'] = 'field_match_opponent';
  $handler->display->display_options['fields']['field_match_opponent']['label'] = '';
  $handler->display->display_options['fields']['field_match_opponent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_opponent']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_opponent']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_match_opponent']['field_api_classes'] = 0;
  /* Поле: Содержимое: Где играют */
  $handler->display->display_options['fields']['field_match_place']['id'] = 'field_match_place';
  $handler->display->display_options['fields']['field_match_place']['table'] = 'field_data_field_match_place';
  $handler->display->display_options['fields']['field_match_place']['field'] = 'field_match_place';
  $handler->display->display_options['fields']['field_match_place']['label'] = '';
  $handler->display->display_options['fields']['field_match_place']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_place']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_place']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_place']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_place']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_place']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_place']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_place']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_place']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_place']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_match_place']['field_api_classes'] = 0;
  /* Поле: Содержимое: Дата и время начала */
  $handler->display->display_options['fields']['field_match_start_date']['id'] = 'field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['field'] = 'field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_match_start_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_start_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['type'] = 'date_long';
  $handler->display->display_options['fields']['field_match_start_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_match_start_date']['field_api_classes'] = 0;
  /* Поле: Содержимое: Стадия/Тур */
  $handler->display->display_options['fields']['field_match_round']['id'] = 'field_match_round';
  $handler->display->display_options['fields']['field_match_round']['table'] = 'field_data_field_match_round';
  $handler->display->display_options['fields']['field_match_round']['field'] = 'field_match_round';
  $handler->display->display_options['fields']['field_match_round']['label'] = '';
  $handler->display->display_options['fields']['field_match_round']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_round']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_round']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_round']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_round']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_round']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_round']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_round']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_round']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_match_round']['field_api_classes'] = 0;
  /* Поле: Содержимое: Турнир */
  $handler->display->display_options['fields']['field_match_tournament']['id'] = 'field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['table'] = 'field_data_field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['field'] = 'field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['label'] = '';
  $handler->display->display_options['fields']['field_match_tournament']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_tournament']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_match_tournament']['field_api_classes'] = 0;
  /* Поле: Содержимое: Счёт */
  $handler->display->display_options['fields']['field_match_result']['id'] = 'field_match_result';
  $handler->display->display_options['fields']['field_match_result']['table'] = 'field_data_field_match_result';
  $handler->display->display_options['fields']['field_match_result']['field'] = 'field_match_result';
  $handler->display->display_options['fields']['field_match_result']['label'] = '';
  $handler->display->display_options['fields']['field_match_result']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_result']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_result']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_result']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_result']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_result']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_result']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_result']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_result']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_match_result']['field_api_classes'] = 0;
  /* Поле: Содержимое: Эмблема */
  $handler->display->display_options['fields']['field_team_logo']['id'] = 'field_team_logo';
  $handler->display->display_options['fields']['field_team_logo']['table'] = 'field_data_field_team_logo';
  $handler->display->display_options['fields']['field_team_logo']['field'] = 'field_team_logo';
  $handler->display->display_options['fields']['field_team_logo']['relationship'] = 'field_match_opponent_nid';
  $handler->display->display_options['fields']['field_team_logo']['label'] = '';
  $handler->display->display_options['fields']['field_team_logo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_logo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_logo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_logo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_team_logo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_team_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_logo']['settings'] = array(
    'image_style' => 'team_logo_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_team_logo']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'матч-центр';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Дата и время начала (field_match_start_date) */
  $handler->display->display_options['sorts']['field_match_start_date_value']['id'] = 'field_match_start_date_value';
  $handler->display->display_options['sorts']['field_match_start_date_value']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['sorts']['field_match_start_date_value']['field'] = 'field_match_start_date_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = '$next_match_id =  db_query("
      SELECT sd.entity_id     
      FROM {field_data_field_match_start_date} sd
      WHERE sd.field_match_start_date_value > :start_date 
      ORDER BY sd.field_match_start_date_value
      LIMIT 1 
    ",array(\':start_date\'=>date(\'Y-n-d h:i\')))->fetchField();

return $next_match_id;';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'match' => 'match',
  );

  /* Display: Календарь */
  $handler = $view->new_display('page', 'Календарь', 'calendar');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Календарь';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Выбрать';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_match_result' => 'field_match_result',
    'field_match_start_date' => 'field_match_start_date',
    'field_match_tournament' => 'field_match_tournament',
    'field_match_round' => 'field_match_round',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'field_match_start_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'field_match_result' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'field_match_start_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'field_match_tournament' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'field_match_round' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Мачтчи не найдены.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Матч';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Счёт */
  $handler->display->display_options['fields']['field_match_result']['id'] = 'field_match_result';
  $handler->display->display_options['fields']['field_match_result']['table'] = 'field_data_field_match_result';
  $handler->display->display_options['fields']['field_match_result']['field'] = 'field_match_result';
  $handler->display->display_options['fields']['field_match_result']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_result']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_result']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_result']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_result']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_match_result']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_result']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_result']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_result']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_result']['field_api_classes'] = 0;
  /* Поле: Содержимое: Дата и время начала */
  $handler->display->display_options['fields']['field_match_start_date']['id'] = 'field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['field'] = 'field_match_start_date';
  $handler->display->display_options['fields']['field_match_start_date']['label'] = 'Дата и время';
  $handler->display->display_options['fields']['field_match_start_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_start_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_start_date']['type'] = 'date_short';
  $handler->display->display_options['fields']['field_match_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_match_start_date']['field_api_classes'] = 0;
  /* Поле: Содержимое: Турнир */
  $handler->display->display_options['fields']['field_match_tournament']['id'] = 'field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['table'] = 'field_data_field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['field'] = 'field_match_tournament';
  $handler->display->display_options['fields']['field_match_tournament']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_tournament']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_tournament']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_match_tournament']['field_api_classes'] = 0;
  /* Поле: Содержимое: Стадия/Тур */
  $handler->display->display_options['fields']['field_match_round']['id'] = 'field_match_round';
  $handler->display->display_options['fields']['field_match_round']['table'] = 'field_data_field_match_round';
  $handler->display->display_options['fields']['field_match_round']['field'] = 'field_match_round';
  $handler->display->display_options['fields']['field_match_round']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_round']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_round']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_round']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_round']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_match_round']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_round']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_round']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_round']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_round']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'матч-центр';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Дата и время начала (field_match_start_date) */
  $handler->display->display_options['sorts']['field_match_start_date_value']['id'] = 'field_match_start_date_value';
  $handler->display->display_options['sorts']['field_match_start_date_value']['table'] = 'field_data_field_match_start_date';
  $handler->display->display_options['sorts']['field_match_start_date_value']['field'] = 'field_match_start_date_value';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'match' => 'match',
  );
  /* Filter criterion: Содержимое: Сезон (field_match_season) */
  $handler->display->display_options['filters']['field_match_season_tid']['id'] = 'field_match_season_tid';
  $handler->display->display_options['filters']['field_match_season_tid']['table'] = 'field_data_field_match_season';
  $handler->display->display_options['filters']['field_match_season_tid']['field'] = 'field_match_season_tid';
  $handler->display->display_options['filters']['field_match_season_tid']['value'] = array(
    40 => '40',
  );
  $handler->display->display_options['filters']['field_match_season_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_match_season_tid']['expose']['operator_id'] = 'field_match_season_tid_op';
  $handler->display->display_options['filters']['field_match_season_tid']['expose']['operator'] = 'field_match_season_tid_op';
  $handler->display->display_options['filters']['field_match_season_tid']['expose']['identifier'] = 'field_match_season_tid';
  $handler->display->display_options['filters']['field_match_season_tid']['expose']['required'] = 1;
  $handler->display->display_options['filters']['field_match_season_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_match_season_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_match_season_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_match_season_tid']['vocabulary'] = 'season';
  $handler->display->display_options['filters']['field_match_season_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_match_season_tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'calendar';

  /* Display: События матча (Арсенал) */
  $handler = $view->new_display('block', 'События матча (Арсенал)', 'match_events');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: События Арсенала */
  $handler->display->display_options['fields']['field_match_events']['id'] = 'field_match_events';
  $handler->display->display_options['fields']['field_match_events']['table'] = 'field_data_field_match_events';
  $handler->display->display_options['fields']['field_match_events']['field'] = 'field_match_events';
  $handler->display->display_options['fields']['field_match_events']['label'] = '';
  $handler->display->display_options['fields']['field_match_events']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_events']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_events']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_events']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_events']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_events']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_events']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_events']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_events']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_events']['settings'] = array(
    'edit' => 'Изменить',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
  );
  $handler->display->display_options['fields']['field_match_events']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_match_events']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_match_events']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_match_events']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: События Арсенала (field_match_events:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_match_events';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['sorts']['delta']['expose']['label'] = 'События Арсенала (field_match_events:delta)';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: События матча (соперник) */
  $handler = $view->new_display('block', 'События матча (соперник)', 'match_events_opponent');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: События соперника */
  $handler->display->display_options['fields']['field_match_events_opponent']['id'] = 'field_match_events_opponent';
  $handler->display->display_options['fields']['field_match_events_opponent']['table'] = 'field_data_field_match_events_opponent';
  $handler->display->display_options['fields']['field_match_events_opponent']['field'] = 'field_match_events_opponent';
  $handler->display->display_options['fields']['field_match_events_opponent']['label'] = '';
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_match_events_opponent']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_match_events_opponent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['settings'] = array(
    'edit' => 'Изменить',
    'delete' => 'Удалить',
    'add' => 'Добавить',
    'description' => 1,
  );
  $handler->display->display_options['fields']['field_match_events_opponent']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_match_events_opponent']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_match_events_opponent']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: События соперника (field_match_events_opponent:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_match_events_opponent';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $translatables['matches'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Заголовок'),
    t('События Арсенала'),
    t('События соперника'),
    t('Все'),
    t('Последний матч'),
    t('field_match_opponent'),
    t('матч-центр'),
    t('Следующий матч'),
    t('Матч'),
    t('Календарь'),
    t('Выбрать'),
    t('Мачтчи не найдены.'),
    t('Счёт'),
    t('Дата и время'),
    t('Турнир'),
    t('Стадия/Тур'),
    t('События матча (Арсенал)'),
    t('События Арсенала (field_match_events:delta)'),
    t('События матча (соперник)'),
  );
  $export['matches'] = $view;

  $view = new view;
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'news';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Заголовок: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Новостей, соответствующих критериям поиска, не существует.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y - h:i';
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_news_image']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Поле: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['totalcount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['totalcount']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['format_plural'] = 0;
  /* Поле: Содержимое: Счётчик комментариев */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  /* Поле: Содержимое: Описание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Содержимое: Created date */
  $handler->display->display_options['arguments']['created_fulldate']['id'] = 'created_fulldate';
  $handler->display->display_options['arguments']['created_fulldate']['table'] = 'node';
  $handler->display->display_options['arguments']['created_fulldate']['field'] = 'created_fulldate';
  $handler->display->display_options['arguments']['created_fulldate']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_fulldate']['summary']['format'] = 'default_summary';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );

  /* Display: Новости по категориям */
  $handler = $view->new_display('page', 'Новости по категориям', 'news_by_category');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Заголовок: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = '%1';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Категория (field_news_category) */
  $handler->display->display_options['arguments']['field_news_category_tid']['id'] = 'field_news_category_tid';
  $handler->display->display_options['arguments']['field_news_category_tid']['table'] = 'field_data_field_news_category';
  $handler->display->display_options['arguments']['field_news_category_tid']['field'] = 'field_news_category_tid';
  $handler->display->display_options['arguments']['field_news_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_news_category_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_news_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_news_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_news_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_news_category_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_news_category_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'news/%';
  $handler->display->display_options['menu']['title'] = '[term]';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Архив новостей */
  $handler = $view->new_display('page', 'Архив новостей', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Архив новостей';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Новостей, соответствующих критериям поиска, не существует.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Дата: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'month';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_select';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['default_to_date'] = '';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-5:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'OR';
  $handler->display->display_options['filters']['date_filter']['date_group'] = 'date';
  $handler->display->display_options['path'] = 'news-all/date';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'архив новостей';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Последние новости */
  $handler = $view->new_display('block', 'Последние новости', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y - h:i';
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'image_style' => 'news_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_news_image']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Поле: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['totalcount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['totalcount']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['format_plural'] = 0;
  /* Поле: Содержимое: Счётчик комментариев */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  /* Поле: Содержимое: Описание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '18',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;

  /* Display: Главная новость */
  $handler = $view->new_display('block', 'Главная новость', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y - h:i';
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_news_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_news_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_news_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_news_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_news_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_news_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_news_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'image_style' => 'news_article',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_news_image']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Поле: Content statistics: Total views */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = '';
  $handler->display->display_options['fields']['totalcount']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['external'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['totalcount']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['totalcount']['alter']['html'] = 0;
  $handler->display->display_options['fields']['totalcount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['totalcount']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['totalcount']['hide_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = 0;
  $handler->display->display_options['fields']['totalcount']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['totalcount']['format_plural'] = 0;
  /* Поле: Содержимое: Счётчик комментариев */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  $translatables['news'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Новостей, соответствующих критериям поиска, не существует.'),
    t('.'),
    t(','),
    t('Описание'),
    t('Все'),
    t('Новости по категориям'),
    t('%1'),
    t('Архив новостей'),
    t('Применить'),
    t('Последние новости'),
    t('Главная новость'),
  );
  $export['news'] = $view;

  $view = new view;
  $view->name = 'partner_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Partner sites';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Наши друзья';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: DraggableViews: Порядок */
  $handler->display->display_options['fields']['value0']['id'] = 'value0';
  $handler->display->display_options['fields']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['fields']['value0']['field'] = 'value0';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: DraggableViews: Порядок */
  $handler->display->display_options['sorts']['value0']['id'] = 'value0';
  $handler->display->display_options['sorts']['value0']['table'] = 'draggableviews_structure_node0';
  $handler->display->display_options['sorts']['value0']['field'] = 'value0';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner_site' => 'partner_site',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'partner_sites_page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Поле: Содержимое: URL ссылки */
  $handler->display->display_options['fields']['field_partner_link_url']['id'] = 'field_partner_link_url';
  $handler->display->display_options['fields']['field_partner_link_url']['table'] = 'field_data_field_partner_link_url';
  $handler->display->display_options['fields']['field_partner_link_url']['field'] = 'field_partner_link_url';
  $handler->display->display_options['fields']['field_partner_link_url']['label'] = '';
  $handler->display->display_options['fields']['field_partner_link_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partner_link_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_link_url']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_partner_link_url']['field_api_classes'] = 0;
  /* Поле: Содержимое: Описание */
  $handler->display->display_options['fields']['field_partner_description']['id'] = 'field_partner_description';
  $handler->display->display_options['fields']['field_partner_description']['table'] = 'field_data_field_partner_description';
  $handler->display->display_options['fields']['field_partner_description']['field'] = 'field_partner_description';
  $handler->display->display_options['fields']['field_partner_description']['label'] = '';
  $handler->display->display_options['fields']['field_partner_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_partner_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_description']['field_api_classes'] = 0;
  /* Поле: Содержимое: Текст ссылки */
  $handler->display->display_options['fields']['field_partner_link_text']['id'] = 'field_partner_link_text';
  $handler->display->display_options['fields']['field_partner_link_text']['table'] = 'field_data_field_partner_link_text';
  $handler->display->display_options['fields']['field_partner_link_text']['field'] = 'field_partner_link_text';
  $handler->display->display_options['fields']['field_partner_link_text']['label'] = '';
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['path'] = '[field_partner_link_url]';
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['alt'] = '[field_partner_link_text]';
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partner_link_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_link_text']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_partner_link_text']['field_api_classes'] = 0;
  /* Поле: Содержимое: Баннер */
  $handler->display->display_options['fields']['field_partner_banner_image']['id'] = 'field_partner_banner_image';
  $handler->display->display_options['fields']['field_partner_banner_image']['table'] = 'field_data_field_partner_banner_image';
  $handler->display->display_options['fields']['field_partner_banner_image']['field'] = 'field_partner_banner_image';
  $handler->display->display_options['fields']['field_partner_banner_image']['label'] = '';
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['path'] = '[field_partner_link_url]';
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['absolute'] = 1;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['alt'] = '[field_partner_link_text]';
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['element_class'] = 'partner-banner-image';
  $handler->display->display_options['fields']['field_partner_banner_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_banner_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_partner_banner_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_banner_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_partner_banner_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_partner_banner_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_partner_banner_image']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Вес: Вес */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'node_weight';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'partners';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'друзья';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'partner_sites_homepage_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Наши друзья';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: URL ссылки */
  $handler->display->display_options['fields']['field_partner_link_url']['id'] = 'field_partner_link_url';
  $handler->display->display_options['fields']['field_partner_link_url']['table'] = 'field_data_field_partner_link_url';
  $handler->display->display_options['fields']['field_partner_link_url']['field'] = 'field_partner_link_url';
  $handler->display->display_options['fields']['field_partner_link_url']['label'] = '';
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partner_link_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_link_url']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_url']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_partner_link_url']['field_api_classes'] = 0;
  /* Поле: Содержимое: Текст ссылки */
  $handler->display->display_options['fields']['field_partner_link_text']['id'] = 'field_partner_link_text';
  $handler->display->display_options['fields']['field_partner_link_text']['table'] = 'field_data_field_partner_link_text';
  $handler->display->display_options['fields']['field_partner_link_text']['field'] = 'field_partner_link_text';
  $handler->display->display_options['fields']['field_partner_link_text']['label'] = '';
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['element_type'] = '0';
  $handler->display->display_options['fields']['field_partner_link_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_link_text']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_partner_link_text']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Вес: Вес */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'node_weight';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'partner_site' => 'partner_site',
  );
  /* Filter criterion: Содержимое: Помещено на главную страницу */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $translatables['partner_sites'] = array(
    t('Master'),
    t('Наши друзья'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Порядок'),
    t('Page'),
    t('[field_partner_link_url]'),
    t('[field_partner_link_text]'),
    t('_blank'),
    t('Block'),
  );
  $export['partner_sites'] = $view;

  $view = new view;
  $view->name = 'persons';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'persons';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Содержимое: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Фото */
  $handler->display->display_options['fields']['field_person_photo']['id'] = 'field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['table'] = 'field_data_field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['field'] = 'field_person_photo';
  /* Sort criterion: Содержимое: Роль в клубе (field_person_role) */
  $handler->display->display_options['sorts']['field_person_role_tid']['id'] = 'field_person_role_tid';
  $handler->display->display_options['sorts']['field_person_role_tid']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['sorts']['field_person_role_tid']['field'] = 'field_person_role_tid';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'person_role';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';

  /* Display: Arsenal players for match */
  $handler = $view->new_display('references', 'Arsenal players for match', 'arsenal_squad_for_match');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'references_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Номер */
  $handler->display->display_options['fields']['field_person_number']['id'] = 'field_person_number';
  $handler->display->display_options['fields']['field_person_number']['table'] = 'field_data_field_person_number';
  $handler->display->display_options['fields']['field_person_number']['field'] = 'field_person_number';
  $handler->display->display_options['fields']['field_person_number']['label'] = '';
  $handler->display->display_options['fields']['field_person_number']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_person_number']['alter']['text'] = '[field_person_number-value]. ';
  $handler->display->display_options['fields']['field_person_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_number']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_person_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_number']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_number']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_person_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_person_number']['field_api_classes'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Поле: Содержимое: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '([term_node_tid-name])';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'news_category' => 0,
    'person_role' => 0,
    'season' => 0,
    'tags' => 0,
    'tournament' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Роль в клубе (field_person_role) */
  $handler->display->display_options['sorts']['field_person_role_tid']['id'] = 'field_person_role_tid';
  $handler->display->display_options['sorts']['field_person_role_tid']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['sorts']['field_person_role_tid']['field'] = 'field_person_role_tid';
  /* Sort criterion: Содержимое: Номер (field_person_number) */
  $handler->display->display_options['sorts']['field_person_number_value']['id'] = 'field_person_number_value';
  $handler->display->display_options['sorts']['field_person_number_value']['table'] = 'field_data_field_person_number';
  $handler->display->display_options['sorts']['field_person_number_value']['field'] = 'field_person_number_value';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    14 => '14',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'person_role';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  /* Filter criterion: Содержимое: Команда (field_person_team) */
  $handler->display->display_options['filters']['field_person_team_nid']['id'] = 'field_person_team_nid';
  $handler->display->display_options['filters']['field_person_team_nid']['table'] = 'field_data_field_person_team';
  $handler->display->display_options['filters']['field_person_team_nid']['field'] = 'field_person_team_nid';
  $handler->display->display_options['filters']['field_person_team_nid']['value'] = array(
    4 => '4',
  );

  /* Display: Основной состав */
  $handler = $view->new_display('page', 'Основной состав', 'first_squad');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Состав команды';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = 'term_node_tid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Номер */
  $handler->display->display_options['fields']['field_person_number']['id'] = 'field_person_number';
  $handler->display->display_options['fields']['field_person_number']['table'] = 'field_data_field_person_number';
  $handler->display->display_options['fields']['field_person_number']['field'] = 'field_person_number';
  $handler->display->display_options['fields']['field_person_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_number']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_person_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_number']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_number']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_person_number']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_person_number']['field_api_classes'] = 0;
  /* Поле: Содержимое: Фото */
  $handler->display->display_options['fields']['field_person_photo']['id'] = 'field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['table'] = 'field_data_field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['field'] = 'field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_person_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_person_photo']['settings'] = array(
    'image_style' => 'squad_player_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_person_photo']['field_api_classes'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Игрок';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Национальность */
  $handler->display->display_options['fields']['field_person_nationality']['id'] = 'field_person_nationality';
  $handler->display->display_options['fields']['field_person_nationality']['table'] = 'field_data_field_person_nationality';
  $handler->display->display_options['fields']['field_person_nationality']['field'] = 'field_person_nationality';
  $handler->display->display_options['fields']['field_person_nationality']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_nationality']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['field_api_classes'] = 0;
  /* Поле: Содержимое: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '[term_node_tid-tid]';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'news_category' => 0,
    'person_role' => 0,
    'season' => 0,
    'tags' => 0,
    'tournament' => 0,
  );
  /* Поле: Содержимое: Описание роли в клубе (при необходимости) */
  $handler->display->display_options['fields']['field_person_role_description']['id'] = 'field_person_role_description';
  $handler->display->display_options['fields']['field_person_role_description']['table'] = 'field_data_field_person_role_description';
  $handler->display->display_options['fields']['field_person_role_description']['field'] = 'field_person_role_description';
  $handler->display->display_options['fields']['field_person_role_description']['label'] = '';
  $handler->display->display_options['fields']['field_person_role_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_role_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_role_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Содержимое: Роль в клубе (field_person_role) */
  $handler->display->display_options['sorts']['field_person_role_tid']['id'] = 'field_person_role_tid';
  $handler->display->display_options['sorts']['field_person_role_tid']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['sorts']['field_person_role_tid']['field'] = 'field_person_role_tid';
  /* Sort criterion: Содержимое: Номер (field_person_number) */
  $handler->display->display_options['sorts']['field_person_number_value']['id'] = 'field_person_number_value';
  $handler->display->display_options['sorts']['field_person_number_value']['table'] = 'field_data_field_person_number';
  $handler->display->display_options['sorts']['field_person_number_value']['field'] = 'field_person_number_value';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Команда (field_person_team) */
  $handler->display->display_options['filters']['field_person_team_nid']['id'] = 'field_person_team_nid';
  $handler->display->display_options['filters']['field_person_team_nid']['table'] = 'field_data_field_person_team';
  $handler->display->display_options['filters']['field_person_team_nid']['field'] = 'field_person_team_nid';
  $handler->display->display_options['filters']['field_person_team_nid']['value'] = array(
    4 => '4',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    19 => '19',
    20 => '20',
    21 => '21',
    22 => '22',
    77 => '77',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'person_role';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'players';
  $handler->display->display_options['menu']['title'] = 'состав';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Тренеры */
  $handler = $view->new_display('page', 'Тренеры', 'trainers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Тренерский штаб';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = 'field_person_role';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Содержимое: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 0;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'news_category' => 0,
    'person_role' => 0,
    'season' => 0,
    'tags' => 0,
    'tournament' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Фото */
  $handler->display->display_options['fields']['field_person_photo']['id'] = 'field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['table'] = 'field_data_field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['field'] = 'field_person_photo';
  $handler->display->display_options['fields']['field_person_photo']['label'] = '';
  $handler->display->display_options['fields']['field_person_photo']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_photo']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_photo']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_photo']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_photo']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_person_photo']['settings'] = array(
    'image_style' => 'squad_player_thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_person_photo']['field_api_classes'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Тренер';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Национальность */
  $handler->display->display_options['fields']['field_person_nationality']['id'] = 'field_person_nationality';
  $handler->display->display_options['fields']['field_person_nationality']['table'] = 'field_data_field_person_nationality';
  $handler->display->display_options['fields']['field_person_nationality']['field'] = 'field_person_nationality';
  $handler->display->display_options['fields']['field_person_nationality']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_nationality']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_nationality']['field_api_classes'] = 0;
  /* Поле: Содержимое: Роль в клубе */
  $handler->display->display_options['fields']['field_person_role']['id'] = 'field_person_role';
  $handler->display->display_options['fields']['field_person_role']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['fields']['field_person_role']['field'] = 'field_person_role';
  $handler->display->display_options['fields']['field_person_role']['label'] = '';
  $handler->display->display_options['fields']['field_person_role']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_person_role']['alter']['text'] = '[field_person_role-tid]';
  $handler->display->display_options['fields']['field_person_role']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_role']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_role']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_role']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_role']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_person_role']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_role']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_role']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_role']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_person_role']['field_api_classes'] = 0;
  /* Поле: Содержимое: Описание роли в клубе (при необходимости) */
  $handler->display->display_options['fields']['field_person_role_description']['id'] = 'field_person_role_description';
  $handler->display->display_options['fields']['field_person_role_description']['table'] = 'field_data_field_person_role_description';
  $handler->display->display_options['fields']['field_person_role_description']['field'] = 'field_person_role_description';
  $handler->display->display_options['fields']['field_person_role_description']['label'] = '';
  $handler->display->display_options['fields']['field_person_role_description']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['text'] = '([field_person_role_description])';
  $handler->display->display_options['fields']['field_person_role_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_person_role_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_role_description']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_person_role_description']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    15 => '15',
    17 => '17',
    30 => '30',
    18 => '18',
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'person_role';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'trainers';
  $translatables['persons'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('term'),
    t('Фото'),
    t('Arsenal players for match'),
    t('[field_person_number-value]. '),
    t('([term_node_tid-name])'),
    t('Основной состав'),
    t('Состав команды'),
    t('Номер'),
    t('Игрок'),
    t('Национальность'),
    t('[term_node_tid-tid]'),
    t('Тренеры'),
    t('Тренерский штаб'),
    t('Тренер'),
    t('[field_person_role-tid]'),
    t('([field_person_role_description])'),
  );
  $export['persons'] = $view;

  $view = new view;
  $view->name = 'random_article';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'random_article';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';

  /* Display: Случайный материал */
  $handler = $view->new_display('block', 'Случайный материал', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'center-align';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Изображение */
  $handler->display->display_options['fields']['field_banner_image']['id'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['table'] = 'field_data_field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['field'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['label'] = '';
  $handler->display->display_options['fields']['field_banner_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_banner_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_banner_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_banner_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_banner_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_banner_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_banner_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_banner_image']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Изображение (field_banner_image:fid) */
  $handler->display->display_options['filters']['field_banner_image_fid']['id'] = 'field_banner_image_fid';
  $handler->display->display_options['filters']['field_banner_image_fid']['table'] = 'field_data_field_banner_image';
  $handler->display->display_options['filters']['field_banner_image_fid']['field'] = 'field_banner_image_fid';
  $handler->display->display_options['filters']['field_banner_image_fid']['operator'] = 'not empty';
  /* Filter criterion: Содержимое: Показывать в блоке &quot;Случайный материал&quot; (field_banner_show_in_random_node) */
  $handler->display->display_options['filters']['field_banner_show_in_random_node_value']['id'] = 'field_banner_show_in_random_node_value';
  $handler->display->display_options['filters']['field_banner_show_in_random_node_value']['table'] = 'field_data_field_banner_show_in_random_node';
  $handler->display->display_options['filters']['field_banner_show_in_random_node_value']['field'] = 'field_banner_show_in_random_node_value';
  $handler->display->display_options['filters']['field_banner_show_in_random_node_value']['value'] = array(
    1 => '1',
  );

  /* Display: Страницы из истории */
  $handler = $view->new_display('block', 'Страницы из истории', 'random_articles_homepage_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Страницы из истории';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    0 => 'AND',
    1 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    62 => '62',
  );
  $handler->display->display_options['filters']['tid']['group'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'article_type';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'biography' => 'biography',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 0;
  $handler->display->display_options['block_description'] = 'Страницы из истории';

  /* Display: Информация фан-клуба */
  $handler = $view->new_display('block', 'Информация фан-клуба', 'fanclub_information');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Информация фан-клуба';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    63 => '63',
  );
  $handler->display->display_options['filters']['tid']['group'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'article_type';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  $translatables['random_article'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Заголовок'),
    t('Случайный материал'),
    t('Страницы из истории'),
    t('Информация фан-клуба'),
  );
  $export['random_article'] = $view;

  $view = new view;
  $view->name = 'video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'video';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'video';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  /* Relationship: Содержимое: Файл (field_video_file:fid) */
  $handler->display->display_options['relationships']['field_video_file_fid']['id'] = 'field_video_file_fid';
  $handler->display->display_options['relationships']['field_video_file_fid']['table'] = 'field_data_field_video_file';
  $handler->display->display_options['relationships']['field_video_file_fid']['field'] = 'field_video_file_fid';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: Файл */
  $handler->display->display_options['fields']['field_video_file']['id'] = 'field_video_file';
  $handler->display->display_options['fields']['field_video_file']['table'] = 'field_data_field_video_file';
  $handler->display->display_options['fields']['field_video_file']['field'] = 'field_video_file';
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Содержимое: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Has taxonomy term';
  $handler->display->display_options['filters']['tid']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['tid']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'video_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Выбрать';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Видеофайлы не найдены.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Файл */
  $handler->display->display_options['fields']['field_video_file']['id'] = 'field_video_file';
  $handler->display->display_options['fields']['field_video_file']['table'] = 'field_data_field_video_file';
  $handler->display->display_options['fields']['field_video_file']['field'] = 'field_video_file';
  $handler->display->display_options['fields']['field_video_file']['label'] = '';
  $handler->display->display_options['fields']['field_video_file']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_video_file']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_video_file']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_video_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_file']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_video_file']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_video_file']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_video_file']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_video_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video_file']['type'] = 'media';
  $handler->display->display_options['fields']['field_video_file']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  $handler->display->display_options['fields']['field_video_file']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a rel="lightmodal\\[|width:660px;height:550px;scrolling:auto;\\]" href="play_video/[nid]">[field_video_file]</a>';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Поле: Содержимое: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['text'] = '([term_node_tid])';
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['term_node_tid']['element_wrapper_class'] = 'video-category-wrapper';
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'news_category' => 0,
    'person_role' => 0,
    'season' => 0,
    'tags' => 0,
    'video_type' => 0,
    'gallery_type' => 0,
    'match_event_type' => 0,
    'article_type' => 0,
    'tournament' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Содержимое: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'video_type';
  $handler->display->display_options['filters']['tid']['error_message'] = 1;
  $handler->display->display_options['path'] = 'video';

  /* Display: Последнее видео */
  $handler = $view->new_display('block', 'Последнее видео', 'latest_video');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Содержимое: Файл (field_video_file:fid) */
  $handler->display->display_options['relationships']['field_video_file_fid']['id'] = 'field_video_file_fid';
  $handler->display->display_options['relationships']['field_video_file_fid']['table'] = 'field_data_field_video_file';
  $handler->display->display_options['relationships']['field_video_file_fid']['field'] = 'field_video_file_fid';
  $handler->display->display_options['relationships']['field_video_file_fid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  /* Поле: Файл: Путь */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_video_file_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uri']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uri']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uri']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uri']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uri']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['uri']['link_to_file'] = 0;
  $handler->display->display_options['fields']['uri']['file_download_path'] = 0;
  /* Поле: Содержимое: Файл */
  $handler->display->display_options['fields']['field_video_file']['id'] = 'field_video_file';
  $handler->display->display_options['fields']['field_video_file']['table'] = 'field_data_field_video_file';
  $handler->display->display_options['fields']['field_video_file']['field'] = 'field_video_file';
  $handler->display->display_options['fields']['field_video_file']['label'] = '';
  $handler->display->display_options['fields']['field_video_file']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_video_file']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_video_file']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_video_file']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_video_file']['element_type'] = '0';
  $handler->display->display_options['fields']['field_video_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_file']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_video_file']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_video_file']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_video_file']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_video_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video_file']['type'] = 'media';
  $handler->display->display_options['fields']['field_video_file']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  $handler->display->display_options['fields']['field_video_file']['field_api_classes'] = 0;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $translatables['video'] = array(
    t('Master'),
    t('video'),
    t('more'),
    t('Apply'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('file from field_video_file'),
    t('Файл'),
    t('Post date'),
    t('Все'),
    t('Has taxonomy term'),
    t('Page'),
    t('Видео'),
    t('Выбрать'),
    t('Видеофайлы не найдены.'),
    t('<a rel="lightmodal\[|width:660px;height:550px;scrolling:auto;\]" href="play_video/[nid]">[field_video_file]</a>'),
    t('([term_node_tid])'),
    t('Последнее видео'),
  );
  $export['video'] = $view;

  return $export;
}
