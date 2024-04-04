#include "MenuOptions.h"
#include "Menu.h"
#include "HotelManager.h"
#include <thread>
#include <chrono>

int main() {

    Menu m1(mainMenuMap, Language::PL);

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
            case MenuOption::Stats:
                hotel.GetStats();
                break;
            case MenuOption::GetClientRoom:
                hotel.GetClientDataPerRoom();
                break;
            case MenuOption::Stop:
                exit = true;
                break;
            default:
                std::cout << "Error" << std::endl;
                break;
            }
        }
        catch (const std::string e)
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
