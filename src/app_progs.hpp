#ifndef PROGS_H_INCLUDED
#define PROGS_H_INCLUDED
/**
 * @brief
 * @details 
 */

 #include <nlohmann/json.hpp>

using json = nlohmann::json;

/**
 * @brief Function to initialize progs of the system.
 */
void app_progs_init(void);

/**
 * @brief Function to get the number of menus in the sistem.
 * @details Analize the store data to check number of menus.
 * @return int of number of menus.
 * 
 */
int app_progs_get_number_of_menus();

/**
 * @brief Function to get menu itens
 * @details Read data base and get every itens of a specified menu index.
 * @param pmenu_index Index of a menu
 * @return json list with menu itens related to pmenu_index id.
 */
json app_progs_get_itens_of_menu(const int pmenu_index);

/**
 * @brief Function to read the name of item.
 * @param piId_register -  register Id of tuple of database.
 * @return name string of item.
 */
std::string app_progs_get_menu_item_name(int piId_register);

/**
 * @brief Function to read the expression of operation item.
 * @param piId_register Id of the operation register.
 * @return String of expression associated with item.
 */
std::string app_progs_get_expression(int piId_register);

#endif // PROGS_H_INCLUDED