
#include "lib_menu.h"
#include <iostream>


MenuItem::MenuItem(const std::string& name, int id) : name(name), id(id) {}
MenuItem::~MenuItem() {}


Menu::~Menu() = default;
void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

/** @brief Display function implementation shows the menu in defaul output */
void Menu::display() const{
    std::vector<MenuItem> items = this->getItems();
    std::cout << this->getTitle() << "\n" << std::endl;
    
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << std::endl;
    }
}

