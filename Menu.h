#pragma once

#include <iostream>
#include <string>
#include <map>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

enum class MenuType
{
    Main,
    Decision,
};

enum class Language
{
    EN,
    PL,
};

enum MainMenuOption
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

enum class Decision
{
    Yes,
    No,
};

class Menu
{
public:
    Menu(MenuType mt);

    template<typename T>
    T GetUserInput();

private:
    MenuType mt;
    bool selecting = true;
    bool updated = false;
    template<typename T>
    void printMenu(T selected, Language lang);
    int* mapPtr = nullptr;
    size_t mapSize;
    
    std::map<MainMenuOption, std::map<Language, std::string>> mainMenuMap =
    {
        {MainMenuOption::Rooms,         {{Language::EN, "Rooms"},           {Language::PL, "Pokoje"}}},
        {MainMenuOption::Clients,       {{Language::EN, "Clients"},         {Language::PL, "Klienci"}}},
        {MainMenuOption::Reservations,  {{Language::EN, "Reservations"},    {Language::PL, "Rezerwacje"}}},
        {MainMenuOption::Book,          {{Language::EN, "Book"},            {Language::PL, "Rezerwuj"}}},
        {MainMenuOption::AddClient,     {{Language::EN, "Add Client"},      {Language::PL, "Dodaj Klienta"}}},
        {MainMenuOption::AddRoom,       {{Language::EN, "Add Room"},        {Language::PL, "Dodaj Pokoj"}}},
        {MainMenuOption::RemoveClient,  {{Language::EN, "Remove Client"},   {Language::PL, "Usun Klienta"}}},
        {MainMenuOption::RemoveRoom,    {{Language::EN, "Remove Room"},     {Language::PL, "Usun Pokoj"}}},
        {MainMenuOption::EditData,      {{Language::EN, "Edit Data"},       {Language::PL, "Edytuj Dane"}}},
        {MainMenuOption::Stop,          {{Language::EN, "Exit"},            {Language::PL, "Wyjdz"}}},
    };
    std::map<Decision, std::map<Language, std::string>> decisionMenuMap =
    {
        {Decision::Yes,     {{Language::EN, "Yes"},     {Language::PL, "Tak"}}},
        {Decision::No,      {{Language::EN, "No"},      {Language::PL, "Nie"}}},
    };

};

template<typename T>
T Menu::GetUserInput()
{
    using EnumType = std::underlying_type_t<T>;
    EnumType selected = static_cast<EnumType>(0);

    printMenu(selected, Language::EN);

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
        if (updated) {
            printMenu(selected, Language::EN);
            updated = false;
        }
    }
    system("cls");
    return static_cast<T>(selected);
}

template<typename T>
void Menu::printMenu(T selected, Language lang)
{
    auto& menuMap = *reinterpret_cast<std::map<T, std::map<Language, std::string>>*>(mapPtr);

    system("cls");
    for (const auto& pair : menuMap)
    {
        if (selected == static_cast<int>(pair.first))
        {
            std::cout << "--> ";
            std::cout << pair.first + 1 << ". " << pair.second.at(lang) << std::endl;
        }
        else
        {
            std::cout << "    ";
            std::cout << pair.first + 1 << ". " << pair.second.at(lang) << std::endl;
        }
    }
}