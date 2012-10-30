<?php

/**
 * @file vkxp.pages.inc
 * Contains page and form for captcha processing.
 */

/**
 * Page callback.
 * Processes request result from http://vk.com.
 */
function vkxp_authorize() {

  // If $_GET contains 'code' it means that authorization was successfull.
  if (isset($_GET['code'])) {

    $params = array();
    $params['client_id']     = variable_get('vkxp_app_id', 0);
    $params['client_secret'] = variable_get('vkxp_app_secret', 0);
    $params['code']          = $_GET['code'];
    $params['redirect_uri']  = url(VKXP_ACCESS_TOKEN_REDIRECT_URI, array('absolute' => TRUE));

    // Make request to vk.com.
    $result = vkxp_query('', $params, VKXP_ACCESS_TOKEN_URI);

    if (isset($result['access_token'])) {

      // Save new access token.
      variable_set('vkxp_access_token', $result['access_token']);

      // Write message in watchdog about event.
      _vkxp_watchdog(array(
        'text' => t('Access token was recieved from http://vk.com. Now you may post your nodes there.'),
        'severity' => 'status'));
    }
    else {
      _vkxp_watchdog(array(
        'text' => t('Access token was not recieved from vkontakte. Error: !error (!error_description)',
          array('!error' => $result['error'], '!error_description' => $result['error_description'])),
        'severity' =>  'error'));
    }
  }

  // If $_GET contains error it means that authorization failed.
  elseif (isset($_GET['error'])) {
    _vkxp_watchdog(array(
      'text' => t('Access code was not recieved from vkontakte. Error: !error (!error_description)',
        array('!error' => $_GET['error'], '!error_description'=> $_GET['error_description'])),
      'severity' => 'error'));
  }

  // Redirect user to settings page.
  drupal_goto('admin/config/services/vkxp/main');
}
