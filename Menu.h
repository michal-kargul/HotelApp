#pragma once

#include <iostream>
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

enum MenuOptions
{
    rooms,
    clients,
    reservations,
    book,
    addUser,
    addRoom,
    stop,
};

class Menu
{
public:
    Menu();

    int selected = 0;
    bool selecting = true;
    bool updated = false;

    int menu();

private:
    void printMenu(int selected);
    std::vector<std::string> createdMenu;

};