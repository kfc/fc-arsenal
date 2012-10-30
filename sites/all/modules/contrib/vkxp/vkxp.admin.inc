<?php

/**
 * @file vkxp.admin.inc
 * Contains VKXP settings form.
 */

/**
 * Page callback.
 * Return form with VKXP main settings.
 */
function vkxp_admin_main_settings($form, &$form_state) {

  // Application settings.
  $form['vkxp_application'] = array(
    '#type' => 'fieldset',
    '#title' => t('Application settings'),
    '#collapsible' => TRUE,
    '#description' => t('Note: You have to !create standalone vkontakte application to make this module work.',
      array('!create' => l(t('create'), 'http://vk.com/editapp?act=create', array('attributes' => array('target' => '_blank'))))),
  );

  $form['vkxp_application']['vkxp_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#required' => TRUE,
    '#default_value' => variable_get('vkxp_app_id', ''),
    '#description' => t('ID of vk application.'),
  );

  $form['vkxp_application']['vkxp_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Application secret code'),
    '#required' => TRUE,
    '#default_value' => variable_get('vkxp_app_secret', ''),
    '#description' => t('Secret code of vk application.')
  );

  // Owner settings.
  $form['vkxp_owner'] = array(
    '#type' => 'fieldset',
    '#title' => t('Owner settings'),
    '#description' => t('Set user or group to which data will be transferred.'),
    '#collapsible' => TRUE,
  );

  $form['vkxp_owner']['vkxp_group_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Owner ID'),
    '#required' => TRUE,
    '#default_value' => variable_get('vkxp_group_id', ''),
    '#description' => t('User ID or Group ID.'),
  );

  $form['vkxp_owner']['vkxp_wall_owner'] = array(
    '#type' => 'select',
    '#title' => t('Select owner type'),
    '#options' => array(
      'group' => t('Group'),
      'user' => t('User'),
    ),
    '#default_value' => variable_get('vkxp_wall_owner', 'group'),
    '#description' => t('Who owns the above ID.'),
  );

  // Additional settings.
  $form['vkxp_additional'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional settings'),
    '#collapsible' => TRUE,
  );

  $form['vkxp_additional']['vkxp_official'] = array(
    '#type' => 'checkbox',
    '#title' => t('Write from group name'),
    '#default_value' => variable_get('vkxp_official', 1),
    '#description' => t('Check this if you want to post messages from group name.'),
  );

  $form['vkxp_additional']['vkxp_add_link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add link on wall to posted page'),
    '#default_value' => variable_get('vkxp_add_link', 0),
    '#description' => t('Check this if you want to post node url on vk wall.'),
  );

  // Submit buttons.
  $form['actions'] = array(
    '#type' => 'action',
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  $form['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Recieve new access token'),
  );

  return $form;
}

/**
 * Submit callback for vkxp main settings form.
 */
function vkxp_admin_main_settings_submit($form, &$form_state) {
  $values = &$form_state['values'];

  // Trim values just in case.
  $values['vkxp_app_id']     = trim($values['vkxp_app_id']);
  $values['vkxp_app_secret'] = trim($values['vkxp_app_secret']);

  // If application ID or application secret key was changed we should get new access token.
  $app_id_changed = variable_get('vkxp_app_id', 0)     != $values['vkxp_app_id'];
  $secret_changed = variable_get('vkxp_app_secret', 0) != $values['vkxp_app_secret'];
  $reset_clicked  = $values['op'] == $values['reset'];

  // Save form state values.
  system_settings_form_submit($form, $form_state);

  if ($app_id_changed || $secret_changed || $reset_clicked) {

    // Build params for http://vk.com to get new access token.
    $params = array();
    $params['client_id']     = $form_state['values']['vkxp_app_id'];
    $params['scope']         = VKXP_AUTHORIZE_SCOPE;
    $params['redirect_uri']  = url(VKXP_AUTHORIZE_REDIRECT_URI, array('absolute' => TRUE));
    $params['response_type'] = VKXP_AUTHORIZE_RESPONSE_TYPE;
    $params['display']       = VKXP_AUTHORIZE_DISPLAY;

    // Redirect user to authorize page.
    drupal_goto(VKXP_AUTHORIZE_URI . '?' . drupal_http_build_query($params));
  }
}
