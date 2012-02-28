<?php

/**
 * @file media_rutube/media_rutube.theme.inc
 *
 * Theme and preprocess functions for Media: Rutube.
 */

/**
 * Preprocess function for theme('media_rutube_video').
 */
function media_rutube_preprocess_media_rutube_video(&$variables) {
  $wrapper = file_stream_wrapper_get_instance_by_uri($variables['uri']);
  $parts = $wrapper->get_parameters();
  $variables['video_id'] = check_plain($parts['v']);
  $variables['width'] = isset($variables['width']) ? $variables['width'] : variable_get('media_rutube_width', 450);
  $variables['height'] = isset($variables['height']) ? $variables['height'] : variable_get('media_rutube_height', 330);
}

/**
 * Return player code
 */
function theme_media_rutube_video($variables) {
  return '
    <div class="media-rutube-wrapper" style="width:' . $variables['width'] . 'px; height:' . $variables['height'] . 'px;">
      <OBJECT width="' . $variables['width'] . '" height="' . $variables['height'] . '">
        <PARAM name="movie" value="http://video.rutube.ru/' . $variables['video_id'] . '"></PARAM>
        <PARAM name="wmode" value="window"></PARAM>
        <PARAM name="allowFullScreen" value="false"></PARAM>
        <EMBED src="http://video.rutube.ru/' . $variables['video_id'] . '" type="application/x-shockwave-flash" wmode="window" width="'. $variables['width'] .'" height="'.$variables['height'].'" allowFullScreen="false" ></EMBED>
      </OBJECT>
    </div>
  ';
}

