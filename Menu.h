#pragma once

#include <iostream>
#include <string>
#include <map>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

enum MenuOption
{
    Rooms,
    Clients,
    Reservations,
    Book,
    AddClient,
    AddRoom,
    Stop,
};

class Menu
{
public:
    Menu();
    MenuOption GetUserInput();

private:
    int selected = 0;
    bool selecting = true;
    bool updated = false;
    void printMenu(int selected);
    std::map<MenuOption, std::string> menuMapPL;

};