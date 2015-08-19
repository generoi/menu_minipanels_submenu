<?php
/**
 * @file
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Menu Minipanels Submenu'),
  'keyword' => 'menu_minipanels_submenu',
  'description' => t('Provides the menu item context that is calling mini-panels.'),
  'context name' => 'menu_minipanels_submenu',
  'context' => 'menu_minipanels_submenu_context_create',
  'convert list' => 'menu_minipanels_submenu_context_convert_list',
  'convert' => 'menu_minipanels_submenu_context_convert',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the ID of an entity for this context.'),
  ),
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function menu_minipanels_submenu_context_create($empty, $data = NULL, $conf = FALSE, $plugin) {
  $context = new ctools_context('menu_minipanels_submenu');
  $context->plugin = 'menu_minipanels_submenu';
  if ($empty) {
    return $context;
  }
  else {
    $context->data = $data;
    $context->title = t('Menu item');
    return $context;
  }
}

/**
 * Provide a list of sub-keywords.
 *
 * This is used to provide keywords from the context for use in a content type,
 * pane, etc.
 */
function menu_minipanels_submenu_context_convert_list() {
  return array(
    'title' => t('Menu Minipanel Submenu Context'),
  );
}

/**
 * Convert a context into a string to be used as a keyword by content types, etc.
 */
function menu_minipanels_submenu_context_convert($context, $type) {
  if (empty($context->data)) return;
  switch ($type) {
    case 'title':
      return $context->title;
  }
}
