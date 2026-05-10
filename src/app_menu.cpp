
#include "app_menu.hpp"
#include "app_progs.hpp"
#include "lib_menu.h"
#include <nlohmann/json.hpp>
#include <vector>
#include "HmiCli.h"
#include <cstdlib>
#include <thread>
#include "symbol.h"
#include "string.h"
#include <sstream>
#include "parser.h"
#include "tree_expression.h"
#include "app_progs.hpp"
#include "app_menu.hpp"

using json = nlohmann::json;

/**
 * @brief Variable to store the menu informations to perform the menu system.
 */
std::vector<Menu> gMenu_list;
/**
 * @brief Variable to control the flow of menu. 
 */

uint8_t guIndex_menu = 0;

uint8_t gucHmi_ctr_machine = 0;

bool gHmi_running;
static HmiCli gHmi;   // Create a interface 

enum HMI_CTR_STATES {
    HMI_CTR_UPDATE = 0,
    HMI_CTR_WAIT_FOR_INPUT,
    HMI_CTR_INVALID_INPUT,
    //APP_PROCESSING,
    //APP_DISPLAYING_RESULT,
    HMI_CTR_FINALIZANDO
};

/// Local functions --------------------------------------------------------

/**
 * @brief Load the menu info from database to system menus.
 * @details Construct the navigation menu list of the system. 
 *          Load the informations of all menus from data base, 
 *          create the menus and organize the navigation in a 
 *          list. 
 * @return true if every think ok, false if there is some errors reading database.
 */
bool menu_load_menus();

/**
 * @brief Function to check if the characters of string is only digits.
 * @param pString String to check
 * @return true if there are only number, otherwise false.
 */
bool is_number(const std::string& pString);

/// Implementation ---------------------------------------------------------


void app_menu_init(){
    
    menu_load_menus();

    guIndex_menu = 0;
    gucHmi_ctr_machine = HMI_CTR_UPDATE;
    gHmi_running = true;
}


bool menu_load_menus()
{
    json jMenu_items = json::array();
    int number_of_menus = app_progs_get_number_of_menus();

    try{
        // get data to create each menu of the system.
        for(int i=0; i < number_of_menus; i++)
        {
            Menu menu_temp;
            // load menus of the system
            jMenu_items = app_progs_get_itens_of_menu(i);

            for(const auto& item : jMenu_items){
                // check if the item is a menu
                if(item.value("ind", -1) == 0){
                    menu_temp.setTitle(item.at("op").get<std::string>());
                } 
                else{
                    MenuItem option_menu(item.at("op").get<std::string>() ,item.value("ind", -1) );
                    option_menu.set_id(item.value("id", -1));
                    option_menu.set_id_m(item.value("id_m", -1));
                    option_menu.set_id_mx(item.value("id_mx", -1));
                    menu_temp.addItem(option_menu);
                    //menu_temp.addItem( MenuItem(item.at("op").get<std::string>() ,item.value("ind", -1) ) );
                }
            }
            // insert in menu in the menu list of the system.
            gMenu_list.push_back(menu_temp);
        }
    } 
    catch (const nlohmann::json::type_error& e) {
        //std::cout << "Tipo inválido (não é string)\n";
        // TODO log
        return false;
    }


    return true;

    //mainMenu.addItem(MenuItem("Addition", MatrixOptions::ADDITION));
    //mainMenu.addItem(MenuItem("Subtraction", MatrixOptions::SUBTRACTION));
   // mainMenu.addItem(MenuItem("Multiplication", MatrixOptions::MULTIPLICATION));
   // mainMenu.addItem(MenuItem("Determinant", MatrixOptions::DETERMINANT));
   // mainMenu.addItem(MenuItem("Exit", MatrixOptions::EXIT));
}

bool is_number(const std::string& pString)
{
    return !pString.empty() && std::all_of(pString.begin(), pString.end(),[](unsigned char c){ return std::isdigit(c); });
}

void app_menu_control()
{
    std::string optionSelected;

    do{
        std::string equation;  // store the operation expression to execute.  
        
        switch(gucHmi_ctr_machine){

            case HMI_CTR_UPDATE:
                system("clear"); // Clear the console for better readability. 
                gHmi.displayMenu(gMenu_list[guIndex_menu]);
                
                gucHmi_ctr_machine = HMI_CTR_WAIT_FOR_INPUT;

                break;
            case HMI_CTR_WAIT_FOR_INPUT:

                optionSelected = gHmi.getUserChoice("Select an option: ");

                // Validate the user input.
                if(is_number(optionSelected))
                {
                    bool opt = false;    
                    long iOpt_select = std::stol(optionSelected);
                    
                    for(const auto& item : gMenu_list[guIndex_menu].getItems()){
                        
                        if(item.get_ind() == iOpt_select){
                            opt = true;
                            if(item.get_id_m() != item.get_id_mx()){
                                
                                // jump to another menu
                                guIndex_menu = item.get_id_mx();
                                gucHmi_ctr_machine = HMI_CTR_UPDATE;
                            }
                            if(item.getName() == "Exit"){
                                gucHmi_ctr_machine = HMI_CTR_FINALIZANDO;
                            }
                            // select the action to execute.

                            break;  // stop search. Finded the option.
                        } 
                    }
                    if(!opt){
                        gucHmi_ctr_machine = HMI_CTR_INVALID_INPUT;
                    }
                }
                else
                {
                    gucHmi_ctr_machine = HMI_CTR_INVALID_INPUT;
                }
/*
                if(optionSelected >= MatrixOptions::MAX_OPTIONS) {
                    gucHmi_ctr_machine = APP_INVALID_INPUT;
                }
                else if(optionSelected == MatrixOptions::EXIT){
                    gucHmi_ctr_machine = APP_FINALIZANDO;
                }
                else {
                    gucHmi_ctr_machine = APP_PROCESSING;
                }
*/
                break;    
            case HMI_CTR_INVALID_INPUT:
                std::cout << "\nInvalid input. Please try again." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                gucHmi_ctr_machine = HMI_CTR_UPDATE;
                break;
/*               
            case APP_PROCESSING:{   
                std::cout << "Request to Execution Option." << std::endl;
  
                switch (optionSelected)
                {
                case MatrixOptions::DETERMINANT:
                    
                    std::cout << "Calculation of determinant" << std::endl;
                    equation = "det A";                                                                                                    

                    break;
                case MatrixOptions::ADDITION:
                    std::cout << "Addition selected" << std::endl;
                    equation = "A + B"; //"";
                    break;
                case MatrixOptions::SUBTRACTION:
                    std::cout << "Subtraction selected" << std::endl;
                    equation = "A - B";
                    break;
                case MatrixOptions::MULTIPLICATION:
                    std::cout << "Multiplication selected" << std::endl;
                    equation = "A * B";
                    break;
                default:
                    std::cout << "Not implemented yet"; 
                    break;
                }   
                // Execute the operation.
                matrix_perform_operation(equation);
                
                std::this_thread::sleep_for(std::chrono::seconds(5));

                gucHmi_ctr_machine = APP_WAITING_FOR_INPUT;
                break;   
            }      
*/   
            case HMI_CTR_FINALIZANDO:
                std::cout << "App Finalizando" << std::endl;
                gHmi_running = false;
                break;

        }

    } while (gHmi_running);
}