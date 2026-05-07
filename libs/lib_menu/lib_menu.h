#ifndef LIB_MENU_H_INCLUDED
#define LIB_MENU_H_INCLUDED

#include <vector>
#include <string>

/** 
 * @brief Class to represents a menu item entity.
 * @ 
 * */
class MenuItem
{
private: 
    std::string name;  ///< String with the description of a Menu Item.
    int id;            ///< Identifier value to select the menu by user.
public:
    /**
     * @brief Class Constructor
     * @param name Description of the item.
     * @param id Identifier value to select the menu by user.
     */
    MenuItem(const std::string& name, int id);
    /**
     * @brief Class Destructor
     */
    ~MenuItem();
    /**
     * @brief Method to read the name description of Item.
     * @return String of name.
     */
    std::string getName() const { return name;}
    /**
     * @brief Method to read the ID item value.
     * @return int ID value of Item.
     */
    int getId() const { return id; }
};

/** 
 * @brief Class to represents a menu abstraction.
 * */
class Menu
{
private:
    std::vector<MenuItem> items;       ///< Vector list of Itens in a Menu
    std::string title;                 ///< String of Menu's title.
public:
    /**
     * @brief Class Constructor
     * @param strTitle String of title menu.
     */
    Menu(std::string strTitle) : title(strTitle) {};
    /**
     * @brief Class destructor
     */
    virtual ~Menu();
    /**
     * @brief Method to add a new item in the menu.
     * @param item MenuItem Object to be added in the Menu list.
     */
    void addItem(const MenuItem& item);
    /**
     * @brief Method to read the string Menu's title.
     * @return String of title.
     */
    std::string getTitle() const { return title;}
    /**
     * @brief Method to read a Itens list of menu.
     * @return std::vector<MenuItem>& Vector reference of list menu.
     */
    const std::vector<MenuItem>& getItems() const { return items;}
    /**
     * @brief Method to show the menu
     * @details This method could be overrade to implement according the interface.
     */
    virtual void display() const;
};



#endif // LIB_MENU_H_INCLUDED   