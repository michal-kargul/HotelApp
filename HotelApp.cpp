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
                hotel.PrintEntity(DataSet::Rooms);
                system("pause");
                break;
            case MenuOption::Clients:
                hotel.PrintEntity(DataSet::Clients);
                system("pause");
                break;
            case MenuOption::Reservations:
                hotel.PrintEntity(DataSet::Reservations);
                system("pause");
                break;
            case MenuOption::Book:
                hotel.AddReservation();
                break;
            case MenuOption::AddClient:
                hotel.AddClient();
                break;
            case MenuOption::AddRoom:
                hotel.AddRoom();
                break;
            case MenuOption::RemoveClient:
                hotel.RemoveEntity(DataSet::Rooms);
                break;
            case MenuOption::RemoveRoom:
                hotel.RemoveEntity(DataSet::Rooms);
                break;
            case MenuOption::EditData:
                hotel.EditData();
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
