
#include "lib_menu.h"
#include <iostream>

MenuItem::MenuItem(const std::string& name, int id) : name(name), id(id) {}
MenuItem::~MenuItem() {}
Menu::~Menu() = default;
void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

void Menu::display() const {} 
