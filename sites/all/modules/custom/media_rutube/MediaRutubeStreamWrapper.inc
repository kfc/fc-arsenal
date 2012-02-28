<?php

/**
 *  @file
 *  Create a Rutube Video Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $wrapper = new ResourceRutubeStreamWrapper('rutube://v/[video-code]');
 */
class MediaRutubeStreamWrapper extends MediaReadOnlyStreamWrapper {
  function getTarget($f) {
    return FALSE;
  }

  static function getMimeType($uri, $mapping = NULL) {
    return 'video/rutube';
  }

  function getOriginalThumbnailPath() {
    $parts = $this->get_parameters();
    return 'http://tub.rutube.ru/thumbs/'.substr($parts['v'],0,2).'/'.substr($parts['v'],2,2).'/'.$parts['v'].'-1.jpg';
  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    $local_path = 'public://media-rutube/' . check_plain($parts['v']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      @copy($this->getOriginalThumbnailPath(), $local_path);
    }
    return $local_path;
  }
}

