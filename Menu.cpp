#include <iostream>
#include <conio.h> 
#include <string>
#include "Menu.h"

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
            if (selected < stringsMenu_.size() - 1) {
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

    for (int i = 0; i < stringsMenu_.size(); ++i) {
        std::cout << stringsMenu_[i];

        if (selected == i)
            std::cout << " <--" << std::endl;
        else
            std::cout << std::endl;
    }
}