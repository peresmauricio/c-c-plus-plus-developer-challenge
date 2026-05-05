#ifndef LIB_MENU_H_INCLUDED
#define LIB_MENU_H_INCLUDED

#include <vector>
#include <string>

/** @brief Represents a menu item */
class MenuItem
{
    private:
        std::string name;
        int id;
    public:
        MenuItem(const std::string& name, int id);
        ~MenuItem();
        std::string getName() const { return name; }
        int getId() const { return id; }
};

/** @brief Represents a menu */
class Menu
{
    private:
        std::vector<MenuItem> items;
        std::string title;

    public:
        Menu(std::string strTitle) : title(strTitle) {};
        ~Menu();
        void addItem(const MenuItem& item);
        std::string getTitle() const { return title; }
        const std::vector<MenuItem>& getItems() const { return items; }
        virtual void display() const;
};



#endif // LIB_MENU_H_INCLUDED   