#include "Menu.h"
#include "HotelManager.h"

int main() {

    Menu m1;

    bool exit = false;

    HotelManager hotel;

    do
    {
        switch (m1.menu())
        {
        case MenuOptions::Rooms:
            std::cout << "PokojeTest" << std::endl;
            break;
        case MenuOptions::Clients:
            hotel.ReadClientsFromCSV();
            break;
        case MenuOptions::Reservations:
            std::cout << "RezerwacjeTest" << std::endl;
            break;
        case MenuOptions::Book:
            std::cout << "RezerwujTest" << std::endl;
            break;
        case MenuOptions::AddClient:
            hotel.AddClient();
            break;
        case MenuOptions::AddRoom:
            std::cout << "DodajPokojTest" << std::endl;
            break;
        case MenuOptions::Stop:
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
