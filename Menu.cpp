#include "Menu.h"

Menu::Menu()
{
    menuMapPL =
    {
        {MenuOption::Rooms, "Pokoje"},
        {MenuOption::Clients, "Klienci"},
        {MenuOption::Reservations, "Rezerwacje"},
        {MenuOption::Book, "Rezerwuj"},
        {MenuOption::AddClient, "Dodaj Klienta"},
        {MenuOption::AddRoom, "Dodaj Pokoj"},
        {MenuOption::RemoveRoom, "Usun Pokoj"},
        {MenuOption::Stop, "Wyjdz"}
    };
}

MenuOption Menu::GetUserInput()
{
    Menu::printMenu(selected);

    selecting = true;

    char c;
    while (selecting)
    {
        switch ((c = _getch()))
        {
        case KEY_UP:
            if (selected > 0)
            {
                selected = static_cast<MenuOption>(static_cast<int>(selected) - 1);
                system("cls");
                updated = true;
            }
            break;
        case KEY_DOWN:
            if (selected < menuMapPL.size() - 1)
            {
                selected = static_cast<MenuOption>(static_cast<int>(selected) + 1);
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
    return static_cast<MenuOption>(selected);
}

void Menu::printMenu(MenuOption selected)
{
    system("cls");
    for (const auto& pair : menuMapPL)
    {
        std::cout << pair.first + 1 << ". " << pair.second;

        if (selected == static_cast<int>(pair.first))
            std::cout << " <--" << std::endl;
        else
            std::cout << std::endl;

    }
}
