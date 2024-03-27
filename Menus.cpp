#include "Menus.h"

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