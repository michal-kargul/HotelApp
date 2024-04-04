#pragma once
#include "MenuOptions.h"
#include <iostream>
#include <string>
#include <map>
#include <conio.h>
#include <vector>

enum Keys
{
    KEY_UP = 72,
    KEY_DOWN = 80,
    KEY_ENTER = '\r'
};

class Menu
{
public:
    Menu(std::map<MenuOption, std::map<Language, std::string>>& menuMap, Language language);

    MenuOption GetUserInput();

private:
    std::map<MenuOption, std::map<Language, std::string>> menuMap;
    std::vector<std::string> menuVector;
    size_t mapSize;
    bool selecting = true;
    bool updated = false;
    Language lang;
    int selected = 0;

    void printMenu(int selected);
};




