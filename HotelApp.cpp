#include "Menu.h"
#include "HotelManager.h"
#include <thread>
#include <chrono>

int main() {

    Menu m1(MenuType::Main);

    bool exit = false;

    HotelManager hotel;
    
    do
    {
        try
        {
            switch (m1.GetUserInput<MainMenuOption>())
            {
            case MainMenuOption::Rooms:
                hotel.PrintEntity(DataSet::Rooms);
                system("pause");
                break;
            case MainMenuOption::Clients:
                hotel.PrintEntity(DataSet::Clients);
                system("pause");
                break;
            case MainMenuOption::Reservations:
                hotel.PrintEntity(DataSet::Reservations);
                system("pause");
                break;
            case MainMenuOption::Book:
                hotel.AddReservation();
                break;
            case MainMenuOption::AddClient:
                hotel.AddClient();
                break;
            case MainMenuOption::AddRoom:
                hotel.AddRoom();
                break;
            case MainMenuOption::RemoveClient:
                hotel.RemoveEntity(DataSet::Rooms);
                break;
            case MainMenuOption::RemoveRoom:
                hotel.RemoveEntity(DataSet::Rooms);
                break;
            case MainMenuOption::EditData:
                hotel.EditData();
                break;
            case MainMenuOption::Stop:
                exit = true;
                break;
            default:
                std::cout << "Error" << std::endl;
                break;
            }
        }
        catch (const char* e)
        {
            std::cerr << "Message: " << e;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        catch (...)
        {
            std::cerr << "Error";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        
    } while (exit != true);

    return 0;
}
