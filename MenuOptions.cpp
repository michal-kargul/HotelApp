#include "MenuOptions.h"

std::map<MenuOption, std::map<Language, std::string>> mainMenuMap =
{
    {MenuOption::Rooms,         {{Language::EN, "Rooms"},                {Language::PL, "Pokoje"}}},
    {MenuOption::Clients,       {{Language::EN, "Clients"},              {Language::PL, "Klienci"}}},
    {MenuOption::Reservations,  {{Language::EN, "Reservations"},         {Language::PL, "Rezerwacje"}}},
    {MenuOption::Book,          {{Language::EN, "Book"},                 {Language::PL, "Rezerwuj"}}},
    {MenuOption::AddClient,     {{Language::EN, "Add Client"},           {Language::PL, "Dodaj Klienta"}}},
    {MenuOption::AddRoom,       {{Language::EN, "Add Room"},             {Language::PL, "Dodaj Pokoj"}}},
    {MenuOption::RemoveClient,  {{Language::EN, "Remove Client"},        {Language::PL, "Usun Klienta"}}},
    {MenuOption::RemoveRoom,    {{Language::EN, "Remove Room"},          {Language::PL, "Usun Pokoj"}}},
    {MenuOption::EditData,      {{Language::EN, "Edit Data"},            {Language::PL, "Edytuj Dane"}}},
    {MenuOption::Stats,         {{Language::EN, "Statistics"},           {Language::PL, "Statystyki"}}},
    {MenuOption::GetClientRoom, {{Language::EN, "Check Room History"},   {Language::PL, "Sprawdz historie pokoju"}}},
    {MenuOption::Stop,          {{Language::EN, "Exit"},                 {Language::PL, "Wyjdz"}}},
};

std::map<MenuOption, std::map<Language, std::string>> decisionMenuMap =
{
    {MenuOption::Yes,     {{Language::EN, "Yes"},     {Language::PL, "Tak"}}},
    {MenuOption::No,      {{Language::EN, "No"},      {Language::PL, "Nie"}}},
};
