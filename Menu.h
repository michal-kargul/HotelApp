#pragma once

#include <iostream>
#include <string>
#include <vector>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

class Menu {
public:

    Menu(std::initializer_list<std::string> stringsMenu);

    int selected = 0;
    bool selecting = true;
    bool updated = false;

    int menu();

private:
    void printMenu(int selected);
    std::vector<std::string> createdMenu;
};