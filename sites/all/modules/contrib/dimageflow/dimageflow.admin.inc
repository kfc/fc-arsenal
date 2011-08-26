<?php
// $Id: dimageflow.module,v 1.0 2011/08/02 19:59:43 sas Exp $
/**
 * admin functions.
 */
function dimageflow_settings() {
	$token = array(
	t("[image_path] - path to image."),
	t("[nid] - image node id."),
	);
	if(variable_get('dimageflow_clear_cache', FALSE)){

		drupal_flush_all_caches();
		variable_set('dimageflow_clear_cache', FALSE);
	}
	$node_types = node_type_get_types();
	foreach($node_types as $key => $type){
		$opt_types[$key] = $type->name;
	}
	// Gather bundle information.
	$instances = field_info_instances('node');
	$opt_tax_field = array();

	foreach(field_info_fields() as $field_name => $field){
			if($field['type'] == 'image' && $field['module'] == 'image' && isset($field['bundles']['node']) ){
				foreach($field['bundles']['node'] as $bundle){
					$bundles_fields[$bundle][$field_name] = $instances[$bundle][$field_name]['label'];
				}
			} elseif( $field['type'] == 'taxonomy_term_reference' && $field['module'] == 'taxonomy' && isset($field['bundles']['node']) ) {
				$bundle = current($field['bundles']['node']);
				$opt_tax_field[$field_name] = $instances[$bundle][$field_name]['label'];
			}
	}	

	$form['dimageflow_gallery_page'] = array(
	'#type' => 'textfield',
	'#title' => t("Gallery page"),
	'#default_value' => variable_get('dimageflow_gallery_page', DIMAGEFLOW_GALLERY_PAGE),
	);
	if($bundles_fields){
		foreach($bundles_fields as $bundle => $fields){
			$form['dimageflow_fields_' . $bundle] = array(
		'#type' => 'fieldset',
		'#description' => t('Include for fields.'),
		'#title' => $node_types[$bundle]->name,
			);
			$form['dimageflow_fields_' . $bundle]['dimageflow_fields_' . $bundle] = array(
		'#type' => 'select',
		'#default_value' => variable_get('dimageflow_fields_' . $bundle, 0),
		'#options' => array_merge(array(t('None')), $fields),
			);
		}
	}
	$styles = image_styles();
	foreach($styles as $style_name => $style){
		$styles_opt[$style_name] = $style_name;
	}
	$form['dimageflow_preview_image_style'] = array(
	'#type' => 'select',
	'#title' => t('Thumbnail image style'),
	'#default_value' => variable_get('dimageflow_preview_image_style', DIMAGEFLOW_THUMB_IS_NAME),
	'#options' => $styles_opt
	);
	
	$form['dimageflow_gallery_taxonomy_field'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary for gallery title.'),
    '#default_value' => variable_get('dimageflow_gallery_taxonomy_field', 0),
    '#options' => array_merge(array(t('None')), $opt_tax_field),
	);
	
	$form['dimageflow_path_for_image_view'] = array(
    '#type' => 'textfield',
    '#title' => t('Path for image view'),
    '#default_value' => variable_get('dimageflow_path_for_image_view', 'node/[nid]'),
	'#description' => t('You can use token: !token', array('!token' => theme('item_list', array('items' => $token)))),
	);
	$form['dimageflow_attributes'] = array(
    '#type' => 'textfield',
    '#title' => t('Attributes'),
    '#default_value' => variable_get('dimageflow_attributes', ''),
	'#description' => t('You can use token: !token', array('!token' => theme('item_list', array('items' => $token)))),
	);
	$form['dimageflow_params'] = array(
	'#type' => 'fieldset',
	'#title' => t('ImageFlow params')	
	);
	$form['dimageflow_params']['dimageflow_params_circular'] = array(
	'#type' => 'checkbox',
	'#title' => t('Circular'),
	'#default_value' => variable_get('dimageflow_params_circular', FALSE),
	);	
	$form['dimageflow_params']['dimageflow_params_imagesheight'] = array(
    '#type' => 'textfield',
	'#title' => 'imagesHeight',
	'#size' => 3,
    '#default_value' => variable_get('dimageflow_params_imagesheight', 0.67),
	'#description' => t('Height of the images div container in percent, default value: 0.67'),
	);
	$form['dimageflow_params']['dimageflow_params_image_focus_m'] = array(
    '#type' => 'textfield',
	'#title' => 'imageFocusM',
	'#size' => 3,
    '#default_value' => variable_get('dimageflow_params_image_focus_m', 1),
	'#description' => t('Multiplicator for the focussed image size in percent, default value: 1.0'),
	);
	$form['dimageflow_params']['dimageflow_params_imagesm'] = array(
    '#type' => 'textfield',
	'#title' => 'imagesM',
	'#size' => 3,
    '#default_value' => variable_get('dimageflow_params_imagesm', 1),
	'#description' => t('Multiplicator for all images in percent, default value: 1.0'),
	);
	$form['dimageflow_params']['dimageflow_params_onclick'] = array(
    '#type' => 'textarea',
	'#title' => 'onClick',
    '#default_value' => variable_get('dimageflow_params_onclick', 'document.location = this.url;'),
	'#description' => t("Function that is called onclick of the focussed image, examples (New window): window.open(this.url, '_blank', 
                                'width=500,height=500,left=200,top=200'); default value: document.location = this.url;"),
	);

	$form['#submit'][] = 'dimageflow_settings_submit';
	return system_settings_form($form);
}

function dimageflow_settings_submit($form, &$form_state) {
	if($form_state['values']['dimageflow_gallery_page'] !== variable_get('dimageflow_gallery_page', DIMAGEFLOW_GALLERY_PAGE)){
		variable_set('dimageflow_clear_cache', TRUE);
	}
}