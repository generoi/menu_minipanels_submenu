<?php
/**
 * @file
 */

$plugin = array(
  'title' => t("Menu Minipanels children menu items"),
  'description' => t('Renders the menu items of the Menu Minipanels context.'),
  'category' => t('Menus'),
  'required context' => new ctools_context_required(t("Menu Minipanels"), 'menu_minipanels_submenu'),
);

/**
 * Output function
 */
function menu_minipanels_submenu_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $menu_link = $context->data;
  $tree = menu_tree_all_data($menu_link['menu_name'], $menu_link, 2);
  $output = menu_tree_output($tree);

  $block = new stdClass();
  $block->content = drupal_render($output[$menu_link['mlid']]['#below']);
  return $block;
}

function menu_minipanels_submenu_menu_content_type_edit_form($form, &$form_state) {
  /** Defined so that context has a place to be set. */
  return $form;
}
