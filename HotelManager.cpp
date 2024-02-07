#include "HotelManager.h"

void HotelManager::AddClient()
{
    char c;

    do
    {
        AddClientFromConsole();
 
        std::cout << std::endl << "Czy chcesz dodac kolejnego klienta? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n');

    SaveClientsToCSV();
}

void HotelManager::AddClientFromConsole()
{
    int id;
    int i = 0;
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string peselID;
    char c;

    do
    {
        if (clients.empty() && i == 0)
        {
            ReadFromCSV(DataSet::Clients);
        }
        else if (clients.empty() && i != 0)
        {
            id = 1;
        }
        else {
            const auto& lastClient = clients.back();
            id = lastClient.getID() + 1;
        }
        ++i;
    } while (i == 1);

    std::cout << "Podaj imie klienta: ";
    std::getline(std::cin, name);

    std::cout << "Podaj nazwisko klienta: ";
    std::getline(std::cin, surname);

    do
    {
        std::cout << "Podaj adres e-mail klienta: ";
        std::getline(std::cin, email);
    } while (!std::regex_match(email, std::regex("[\\w-]+@([\\w-]+\\.)+[\\w-]+")));

    do
    {
        std::cout << "Podaj numer telefonu klienta: ";
        std::getline(std::cin, phoneNumber);
    } while (!std::regex_match(phoneNumber, std::regex("^[\\+]?[(]?[0-9]{3}[)]?[-\\s\\.]?[0-9]{2,4}[-\\s\\.]?[0-9]{3,6}$"))); //Numer telefonu z lub bez kodu kraju.

    do
    {
        std::cout << std::endl << "Czy klient posiada numer PESEL? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n' && c != 'y');

    if (c == 'n')
        peselID = "n/a";
    else
    {
        do
        {
            std::cout << "Podaj pesel klienta: ";
            std::getline(std::cin, peselID);
        } while (!std::regex_match(peselID, std::regex("^[0-9]{11}$")));
        
    }
    
    Client newClient(id, name, surname, email, phoneNumber, peselID);
    clients.push_back(newClient);
}

void HotelManager::SaveClientsToCSV()
{
    
    std::ofstream file(filenameClient, std::ios::ate);

    if (file.is_open())
    {
        for (const auto& client : clients)
        {
            file << client.getID() << "," << client.getName() << "," << client.getSurname() << "," << client.getEmail() << "," << client.getPhoneNumber() << "," << client.getPeselID() << "\n";
        }
        file.close();
        std::cout << "Clients data added to " << filenameClient << std::endl;
        clients.clear();
    }
    else
    {
        std::cerr << "Error while opening file: " << filenameClient << std::endl;
    }
}


void HotelManager::ReadFromCSV(DataSet ds)
{
    std::string fileName;

    switch (ds)
    {
    case DataSet::Clients:
        fileName = filenameClient;
        clients.clear();
        break;
    case DataSet::Rooms:
        fileName = filenameRoom;
        rooms.clear();
        break;
    case DataSet::Reservations:
        fileName = filenameReservation;
        reservations.clear();
        break;
    default:
        std::cerr << "Zly parametr dla RemoveEntity";
        break;
    }

    std::ifstream file(fileName);

    if (file.is_open())
    {
        std::string line;
        std::string cell;
        size_t pos = 0;

        while (std::getline(file, line, '\n'))
        {
            std::vector<std::string> cells;
            std::istringstream lineStream(line);
            while (std::getline(lineStream, cell, ','))
            {
                cells.push_back(cell);
            }
            switch (ds)
            {
            case DataSet::Clients:
                clients.emplace_back(stoi(cells[0]), cells[1], cells[2], cells[3], cells[4], cells[5]);
                break;
            case DataSet::Rooms:
                rooms.emplace_back(stoi(cells[0]), cells[1], stoi(cells[2]), std::stod(cells[3]), cells[4] == "1");
                break;
            case DataSet::Reservations:
                reservations.emplace_back(stoi(cells[0]), stoi(cells[1]), stoi(cells[2]), std::stoi(cells[3]), cells[4] == "1", cells[5] == "1");
                break;
            default:
                std::cerr << "Zly parametr dla RemoveEntity";
                break;
            }          
        }

        file.close();

    }
    else
    {
        std::cerr << "Error while opening file: " << filenameClient << std::endl;
    }

}

void HotelManager::AddRoom()
{
    char c;

    do
    {
        AddRoomFromConsole();

        std::cout << std::endl << "Czy chcesz dodac kolejny pokoj? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n');

    SaveRoomsToCSV();
}
// TODO: Walidacja
void HotelManager::AddRoomFromConsole()
{
    int id;
    int lastFloorID;
    int i = 0;
    int floor;
    int capacity;
    double pricePerNight;
    bool available;
    char c;
    std::string roomNumber;

    std::cout << "Podaj pietro: ";
    std::cin >> floor;

    lastFloorID = 100 * floor;

    do
    {
        if (rooms.empty() && i == 0)
        {
            ReadFromCSV(DataSet::Rooms);
        }
        else if (rooms.empty() && i != 0)
        {
            id = 1;
        }
        else {
            const auto& lastRoom = rooms.back();
            id = lastRoom.getRoomID() + 1;
        }
        ++i;
    } while (i == 1);

    for (const auto& room : rooms)
    {
        std::cout << std::setw(15) << room.getRoomID() << std::setw(10) << room.getCapacity() << std::setw(15) << room.getPricePerNight() << std::setw(10) << room.isAvailable() << "\n";
    }

    std::cout << "Podaj numer pokoju: ";
    std::cin >> roomNumber;

    std::cout << "Podaj ilosc osob mieszczacych sie w pokoju: ";
    std::cin >> capacity;

    std::cout << "Podaj cene za noc: ";
    std::cin >> pricePerNight;

    do
    {
        std::cout << "Czy pokoj jest gotowy do wynajmu? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
        switch (c)
        {
        case 121:
            available = true;
            break;
        case 110:
            available = false;
            break;
        }
    } while (c != 'n' && c != 'y');

    Room newRoom(id, roomNumber, capacity, pricePerNight, available);
    rooms.push_back(newRoom);
}

void HotelManager::SaveRoomsToCSV()
{

    std::ofstream file(filenameRoom, std::ios::ate);

    if (file.is_open())
    {
        for (const auto& room : rooms)
        {
            file << room.getRoomID() << "," << room.getRoomNumber() << "," << room.getCapacity() << "," << room.getPricePerNight() << "," << room.isAvailable() << "\n";
        }
        file.close();
        std::cout << "Rooms data added to " << filenameRoom << std::endl;
        rooms.clear();
    }
    else
    {
        std::cerr << "Error while opening file: " << filenameRoom << std::endl;
    }
}

void HotelManager::AddReservation()
{
    char c;

    do
    {
        AddReservationFromConsole();

        std::cout << std::endl << "Czy chcesz dodac kolejna rezerwacje? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n');

    SaveReservationsToCSV();
}

void HotelManager::AddReservationFromConsole()
{
    int i = 0;
    int day;
    int reservationID;
    int selectedRoomID;
    int selectedClientID;
    char c;
    char paid;
    std::vector<int> dates;

    do
    {
        if (clients.empty() && i == 0)
        {
            ReadFromCSV(DataSet::Clients);
        }
        else if (clients.empty() && i != 0)
        {
            AddClient();
        }
        ++i;
    } while (i == 1);

    do
    {
        if (rooms.empty() && i == 0)
        {
            ReadFromCSV(DataSet::Rooms);
        }
        else if (clients.empty() && i != 0)
        {
            AddRoom();
        }
        ++i;
    } while (i == 1);

    do
    {
        if (reservations.empty() && i == 0)
        {
            ReadFromCSV(DataSet::Reservations);
        }
        else if (reservations.empty() && i != 0)
        {
            reservationID = 1;
        }
        else {
            const auto& lastReservation = reservations.back();
            reservationID = lastReservation.getReservationID() + 1;
        }
        ++i;
    } while (i == 1);

    //TODO walidacja
    std::cout << "Podaj daty rezerwacji, jezeli nie chcesz podawac wiecej - wpisz 0 ";
    do
    {
        std::cin >> day;
        if (day!=0)
        dates.push_back(day);
        std::cout << std::endl;
    } while (day != 0);

    PrintEntity(DataSet::Clients);
    std::cout << "Podaj ID goscia ";
    std::cin >> selectedClientID;
    std::cout << std::endl;

    PrintEntity(DataSet::Rooms, dates);
    std::cout << "Podaj ID pokoju ";
    std::cin >> selectedRoomID;
    std::cout << std::endl;

    do
    {
        std::cout << std::endl << "Czy rezerwacja zostala oplacona z gory? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n' && c != 'y');

    switch (c)
    {
    case 'y':
        paid = true;
        break;
    case 'n':
        paid = false;
        break;
    }

    for (auto& date : dates)
    {
        reservations.emplace_back(reservationID, selectedRoomID, selectedClientID, date, paid, true);
    }

}

void HotelManager::SaveReservationsToCSV()
{

    std::ofstream file(filenameReservation, std::ios::ate);

    if (file.is_open())
    {
        for (const auto& reservation : reservations)
        {
            file << reservation.getReservationID() << "," << reservation.getRoomID() << "," << reservation.getClientID() << "," << reservation.getDate() << "," << reservation.isPaid() << "," << reservation.getStatus() << "\n";
        }
        file.close();
        std::cout << "Reservations data added to " << filenameReservation << std::endl;
        reservations.clear();
    }
    else
    {
        std::cerr << "Error while opening file: " << filenameReservation << std::endl;
    }
}

void HotelManager::RemoveEntity(DataSet ds)
{
    int id;
    char c;
    switch (ds)
    {
    case DataSet::Clients:
        if (clients.empty())
        {
            ReadFromCSV(DataSet::Clients);
        }
        PrintEntity(DataSet::Clients);
        std::cout << "Podaj ID klienta do usuniecia: ";
        std::cin >> id;
        RemoveClient(id);
        do
        {
            std::cout << std::endl << "Czy chcesz usunac rezerwacje powiazane z tym klientem? Y = tak, N = nie " << std::endl;
            c = _getch();
            std::cout << std::endl;
        } while (c != 'n');
        if (c == 'y')
        {
            //TODO
        }
        break;
    case DataSet::Rooms:
        if (rooms.empty())
        {
            ReadFromCSV(DataSet::Rooms);
        }
        PrintEntity(DataSet::Rooms);
        std::cout << "Podaj ID pokoju do usuniecia: ";
        std::cin >> id;
        RemoveRoom(id);
        do
        {
            std::cout << std::endl << "Czy chcesz usunac rezerwacje powiazane z tym pokojem? Y = tak, N = nie " << std::endl;
            c = _getch();
            std::cout << std::endl;
        } while (c != 'n');
        if (c == 'y')
        {
            //TODO
        }
        break;
    case DataSet::Reservations:
        if (reservations.empty())
        {
            ReadFromCSV(DataSet::Reservations);
        }
        PrintEntity(DataSet::Reservations);
        std::cout << "Podaj ID rezerwacji do usuniecia: ";
        std::cin >> id;
        RemoveReservation(id);
        do
        {
            std::cout << std::endl << "Czy chcesz usunac rezerwacje powiazane z tym pokojem? Y = tak, N = nie " << std::endl;
            c = _getch();
            std::cout << std::endl;
        } while (c != 'n');
        if (c == 'y')
        {
            //TODO
        }
        break;
    default:
        std::cerr << "Zly parametr dla RemoveEntity";
        break;
    }
}
void HotelManager::RemoveClient(int id)
{
    auto it = std::find_if(clients.begin(), clients.end(), [id](const Client& client) {
        return client.getID() == id;
        });

    if (it != clients.end())
    {
        clients.erase(it);
        std::cout << "Klient " << id << " zostal usuniety." << std::endl;
    }
    else
    {
        std::cerr << "Nie znaleziono klienta z podanym id " << id << std::endl;
    }
}

void HotelManager::RemoveRoom(int id)
{
    auto it = std::find_if(rooms.begin(), rooms.end(), [id](const Room& room) {
        return room.getRoomID() == id;
        });

    if (it != rooms.end())
    {
        rooms.erase(it);
        std::cout << "Pokoj " << id << " zostal usuniety." << std::endl;
    }
    else
    {
        std::cerr << "Nie znaleziono pokoju z podanym id " << id << std::endl;
    }
}

void HotelManager::RemoveReservation(int id)
{
    auto it = std::find_if(reservations.begin(), reservations.end(), [id](const Reservation& reservation) {
        return reservation.getReservationID() == id;
        });

    if (it != reservations.end())
    {
        reservations.erase(it);
        std::cout << "Rezerwacja " << id << " zostala usunieta." << std::endl;
    }
    else
    {
        std::cerr << "Nie znaleziono rezerwacji z podanym id " << id << std::endl;
    }
}

void HotelManager::PrintEntity(DataSet ds, const std::vector<int>& dates)
{
    switch (ds)
    {
    case DataSet::Clients:
        if (clients.empty())
        {
            ReadFromCSV(DataSet::Clients);
        }

        PrintEntityHeading(clients.front());

        for (const auto& client : clients)
        {
            PrintEntityData(client);
        }
        break;
    case DataSet::Rooms:
        if (rooms.empty())
        {
            ReadFromCSV(DataSet::Rooms);
        }

        if (!dates.empty() && reservations.empty())
        {
            ReadFromCSV(DataSet::Reservations);
        }
        
        if ((!dates.empty()))
        {
            
            PrintEntityHeading(rooms.front());
            for (const auto& room : rooms)
            {
                bool roomAvailable = true;
                for (const auto& date : dates)
                {
                    if (std::find_if(reservations.begin(), reservations.end(), [&](const auto& reservation) {
                        return reservation.getRoomID() == room.getRoomID() && date == reservation.getDate();
                        }) != reservations.end())
                    {
                        roomAvailable = false;
                        break;
                    }
                }
                if (roomAvailable)
                {
                    PrintEntityData(room);
                }
            }
        }
        else
        {
            PrintEntityHeading(rooms.front());
            for (const auto& room : rooms)
            {
                PrintEntityData(room);
            }
        }
        break;
    case DataSet::Reservations:
        if (reservations.empty())
        {
            ReadFromCSV(DataSet::Reservations);
        }
        PrintEntityHeading(reservations.front());
        for (const auto& reservation : reservations)
        {
            PrintEntityData(reservation);
        }
        break;
    default:
        std::cerr << "Wrong attribute for PrintEntity()";
        break;
    }
}

void HotelManager::PrintEntityHeading(const Entity& entity)
{
    entity.PrintHeading();
}

void HotelManager::PrintEntityData(const Entity& entity)
{
    entity.Print();
}
