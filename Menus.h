#pragma once
#include <map>
#include <string>

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

extern std::map<MainMenuOption, std::map<Language, std::string>> mainMenuMap;
extern std::map<Decision, std::map<Language, std::string>> decisionMenuMap;