#include "Menu.h"

Menu::Menu()
{
    createdMenu =
    {
        "Pokoje",
        "Klienci",
        "Rezerwacje",
        "Rezerwuj",
        "Dodaj Klienta",
        "Dodaj Pokoj",
        "Wyjdz"
    };
}

int Menu::menu()
{
    Menu::printMenu(selected);

    char c;
    while (selecting) {
        switch ((c = _getch()))
        {
        case KEY_UP:
            if (selected > 0)
            {
                --selected;
                system("cls");
                updated = true;
            }
            break;
        case KEY_DOWN:
            if (selected < createdMenu.size() - 1)
            {
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
    return static_cast<MenuOptions>(selected);
}

void Menu::printMenu(int selected)
{
    int index = 0;
    system("cls");
    for (int i = 0; i < createdMenu.size(); ++i)
    {
        std::cout << i+1 << ". " << createdMenu[i];

        if (selected == i)
            std::cout << " <--" << std::endl;
        else
            std::cout << std::endl;
    }
}
