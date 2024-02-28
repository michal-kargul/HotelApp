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
    RemoveClient,
    RemoveRoom,
    EditData,
    Stop,
};

class Menu
{
public:
    Menu();
    MenuOption GetUserInput();

private:
    MenuOption selected = MenuOption::Rooms;
    bool selecting = true;
    bool updated = false;
    void printMenu(MenuOption selected);
    std::map<MenuOption, std::string> menuMapPL;

};