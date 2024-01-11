#include "Menu.h"
#include "HotelManager.h"

int main() {

    Menu m1;

    bool exit = false;

    HotelManager hotel;

    do
    {
        try
        {
            switch (m1.GetUserInput())
            {
            case MenuOption::Rooms:
                hotel.PrintRooms();
                system("pause");
                break;
            case MenuOption::Clients:
                hotel.PrintClients();
                system("pause");
                break;
            case MenuOption::Reservations:
                std::cout << "RezerwacjeTest" << std::endl;
                break;
            case MenuOption::Book:
                std::cout << "RezerwujTest" << std::endl;
                break;
            case MenuOption::AddClient:
                hotel.AddClient();
                break;
            case MenuOption::AddRoom:
                hotel.AddRoom();
                break;
            case MenuOption::Stop:
                exit = true;
                break;
            default:
                std::cout << "Error" << std::endl;
                break;
            }
        }
        catch (...)
        {
            std::cerr << "Blad"; //Musze sie zastanowic jakie bledy moga sie pojawiac - przy wielu walidacjach niestety narazie nie przychodzi mi nic do glowy.
        }

        
    } while (exit != true);

    return 0;
}
