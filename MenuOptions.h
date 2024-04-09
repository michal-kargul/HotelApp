#pragma once
#include <map>
#include <string>

enum class Language
{
    EN,
    PL,
};

enum MenuOption
{
    //mainMenu
    Rooms,
    Clients,
    Reservations,
    Book,
    AddClient,
    AddRoom,
    RemoveClient,
    RemoveRoom,
    EditData,
    Stats,
    GetClientRoom,
    ParkVehicle,
    RemoveVehicle,
    ParkedVehicles,
    Stop,
    //decisionMenu
    Yes,
    No,
    
};

extern std::map<MenuOption, std::map<Language, std::string>> mainMenuMap;
extern std::map<MenuOption, std::map<Language, std::string>> decisionMenuMap;
extern std::map<MenuOption, std::map<Language, std::string>> parkingMenuMap;