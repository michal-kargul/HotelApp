#include "Menu.h"

Menu::Menu(std::map<MenuOption, std::map<Language, std::string>>& menuMap, Language language) : menuMap(menuMap), lang(language), mapSize(menuMap.size())
{}

MenuOption Menu::GetUserInput()
{
    printMenu(selected);

    selecting = true;

    char c;
    while (selecting)
    {
        switch (c = _getch())
        {
        case KEY_UP:
            if (static_cast<int>(selected) > 0)
            {
                selected = static_cast<int>(selected) - 1;
                system("cls");
                updated = true;
            }
            break;
        case KEY_DOWN:
            if (static_cast<int>(selected) < mapSize - 1)
            {
                selected = static_cast<int>(selected) + 1;
                system("cls");
                updated = true;
            }
            break;
        case KEY_ENTER:
            selecting = false;
            break;
        default: break;
        }
        if (updated)
        {
            printMenu(selected);
            updated = false;
        }
    }
    system("cls");
    return static_cast<MenuOption>(selected);
}

void Menu::printMenu(int selected)
{
    system("cls");
    for (const auto& pair : menuMap)
    {
        if (selected == pair.first)
        {
            std::cout << "--> ";
            std::cout << static_cast<int>(pair.first) + 1 << ". " << pair.second.at(lang) << std::endl;
        }
        else
        {
            std::cout << "    ";
            std::cout << static_cast<int>(pair.first) + 1 << ". " << pair.second.at(lang) << std::endl;
        }
    }
}