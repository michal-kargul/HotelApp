#pragma once

#include "Menus.h"
#include <iostream>
#include <string>
#include <map>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

template<typename T>
class Menu
{
public:
    Menu(std::map<T, std::map<Language, std::string>>& menuMap, Language language);

    T GetUserInput();

private:
    std::map<T, std::map<Language, std::string>> menuMap;
    size_t mapSize;
    bool selecting = true;
    bool updated = false;
    Language lang;

    void printMenu(T selected);
};

template<typename T>
Menu<T>::Menu(std::map<T, std::map<Language, std::string>>& menuMap, Language language) : menuMap(menuMap), lang(language)
{
    mapSize = menuMap.size();
}

template<typename T>
T Menu<T>::GetUserInput()
{
    using EnumType = std::underlying_type_t<T>;
    EnumType selected = static_cast<EnumType>(0);

    printMenu(static_cast<T>(selected));

    selecting = true;

    char c;
    while (selecting)
    {
        switch ((c = _getch()))
        {
        case KEY_UP:
            if (static_cast<int>(selected) > 0)
            {
                selected = static_cast<EnumType>(static_cast<int>(selected) - 1);
                system("cls");
                updated = true;
            }
            break;
        case KEY_DOWN:
            if (static_cast<int>(selected) < mapSize - 1)
            {
                selected = static_cast<EnumType>(static_cast<int>(selected) + 1);
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
            printMenu(static_cast<T>(selected));
            updated = false;
        }
    }
    system("cls");
    return static_cast<T>(selected);
}

template<typename T>
void Menu<T>::printMenu(T selected)
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
