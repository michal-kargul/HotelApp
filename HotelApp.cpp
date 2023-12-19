#include "Menu.h"
#include "HotelManager.h"
#include "Client.h"

int main() {

    Menu m1;

    bool exit = false;

    do
    {
        switch (m1.menu())
        {
        case MenuOptions::rooms:
            std::cout << "PokojeTest" << std::endl;
            break;
        case MenuOptions::clients:
            std::cout << "KlienciTest" << std::endl;
            break;
        case MenuOptions::reservations:
            std::cout << "RezerwacjeTest" << std::endl;
            break;
        case MenuOptions::book:
            std::cout << "RezerwujTest" << std::endl;
            break;
        case MenuOptions::addUser:
            std::cout << "DodajKlientaTest" << std::endl;
            break;
        case MenuOptions::addRoom:
            std::cout << "DodajPokojTest" << std::endl;
            break;
        case MenuOptions::stop:
            exit = true;
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
        }
        system("pause");
        m1.selecting = true;
    } while (exit != true);

    return 0;
}
