#include <iostream>
#include <conio.h> 
#include <string>
#include "Menu.h"

Menu::Menu (std::initializer_list<std::string> stringsMenu) {
    for (auto str : stringsMenu) {
        createdMenu.push_back(str);
    }
}

int Menu::menu() {

    Menu::printMenu(selected);

    char c;
    while (selecting) {

        switch ((c = _getch())) {
        case KEY_UP:
            if (selected > 0) {
                --selected;
                system("cls");
                updated = true;
            }
            break;
        case KEY_DOWN:
            if (selected < createdMenu.size() - 1) {
                ++selected;
                system("cls");
                updated = true;
            }
            break;
        case KEY_ENTER:
            selecting = false;
            break;
        default: break;
        }
        if (updated) {
            printMenu(selected);
            updated = false;
        }

    }
    system("cls");

    return (selected + 1);
}

void Menu::printMenu(int selected) {
    int index = 0;

    for (int i = 0; i < createdMenu.size(); ++i) {
        std::cout << createdMenu[i];

        if (selected == i)
            std::cout << " <--" << std::endl;
        else
            std::cout << std::endl;
    }
}