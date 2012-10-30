Install
=============

1) Go to http://vk.com/editapp?act=create and create STANDALONE application.

2) Extract module in sites/all/modules directory.

3) Go to module settings page /admin/modules and enable VKXP (VKontakte CrossPoster) module.

4) Go to vkxp settings page /admin/config/services/vkxp and paste there application ID, application secret key (from application settings page) and group ID.

5) Click 'Save configuration' button and give your application access to your web site.

6) Configure node type that should be crossposted on /admin/structure/types/manage/[NODE_TYPE] page.


Usage
=============

When creating or editing node, just check "Post this node to vk.com" and data will be automatically sent to vk.com.


External usage
==============

If you are authorized on vk server (if you get access token after 5th step of installation) you may make queries to vk api using this function:

vkxp_query($api_method, $post_fields, $requert_url);

About VK api you can read here http://vkontakte.ru/developers.php#devstep2

Also it is possible to change this query using hook_vkxp_query_alter(). Read about it in vkxp.api.php


CREDITS
=============

Module was developed by Maslouski Yauheni (http://drupalace.ru).
Module development was not sponsored by anyone. It was created for the love of Drupal.
