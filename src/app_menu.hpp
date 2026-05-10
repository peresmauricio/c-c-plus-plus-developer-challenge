#ifndef APP_MENU_H_INCLUDED
#define APP_MENU_H_INCLUDED


/**
 * @brief Function to initialize progs of the system.
 */
void app_progs_init(void);

/**
 * @brief Function to initialize de menu data.
 * @details Read the datbase, identify all menus and menu itens and
 * construct the array of menus. 
 */
void app_menu_init();

/**
 * @brief f
 */
void app_menu_control();

#endif // APP_MENU_H_INCLUDED