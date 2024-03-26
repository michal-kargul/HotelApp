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

    SaveToCSV(DataSet::Clients);
    SaveToCSV(DataSet::IDs);
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

    ReadFromCSV(DataSet::Clients);
    ReadFromCSV(DataSet::IDs);
    
    id = ++ids.at("Client");

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
    ids["Client"] = id;
}

void HotelManager::ReadFromCSV(const DataSet ds)
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
    case DataSet::IDs:
        fileName = filenameIDs;
        ids.clear();
        break;
    default:
        throw std::string("Zly parametr dla RemoveEntity");
        break;
    }

    std::ifstream file(fileName);

    if (file.is_open())
    {
        std::string line;
        std::string cell;
        auto pos = 0;

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
            case DataSet::IDs:
                ids.insert({ cells[0],stoi(cells[1]) });
                break;
            default:
                throw std::string("Zly parametr dla ReadFromCSV");
                break;
            }          
        }
        file.close();
    }
    else
    {
        throw std::string("Error while opening file: ");
    }

}

void HotelManager::SaveToCSV(const DataSet ds)
{
    std::string fileName;

    switch (ds)
    {
    case DataSet::Clients:
        fileName = filenameClient;
        break;
    case DataSet::Rooms:
        fileName = filenameRoom;
        break;
    case DataSet::Reservations:
        fileName = filenameReservation;
        break;
    case DataSet::IDs:
        fileName = filenameIDs;
        break;
    default:
        throw std::string("Zly parametr dla SaveToCSV");
        break;
    }

    std::ofstream file(fileName, std::ios::ate);

    if (file.is_open())
    {
        switch (ds)
        {
        case DataSet::Clients:
            for (const auto& client : clients)
            {
                client.ProcessData(file);
            }
            break;
        case DataSet::Rooms:
            for (const auto& room : rooms)
            {
                room.ProcessData(file);
            }
            break;
        case DataSet::Reservations:
            for (const auto& reservation : reservations)
            {
                reservation.ProcessData(file);
            }
            break;
        case DataSet::IDs:
            for (const auto& [key, value] : ids)
                file << key << "," << value << "\n";
            break;
        default:
            throw std::string("Zly parametr dla SaveToCSV");
            break;
        }
        
        file.close();
        std::cout << "Data added to " << fileName << std::endl;
        clients.clear();
    }
    else
    {
        throw std::string("Error while opening file: ");
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

    SaveToCSV(DataSet::Rooms);
    SaveToCSV(DataSet::IDs);
}

void HotelManager::AddRoomFromConsole()
{
    int id;
    int lastFloorID;
    int i = 0;
    int floor;
    int capacity;
    double pricePerNight;
    bool available=false;
    char c;
    std::string roomNumber;

    std::cout << "Podaj pietro: ";
    std::cin >> floor;

    lastFloorID = 100 * floor;

    ReadFromCSV(DataSet::Rooms);
    ReadFromCSV(DataSet::IDs);

    id = ++ids.at("Room");

    std::cout << "Podaj numer pokoju: ";
    std::cin >> roomNumber;

    do
    {
        std::cout << "Podaj ilosc osob mieszczacych sie w pokoju: ";
        std::cin >> capacity;
    } while (std::cin.fail());

    do
    {
        std::cout << "Podaj cene za noc: ";
        std::cin >> pricePerNight;
    } while (std::cin.fail());

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

    SaveToCSV(DataSet::Reservations);
    SaveToCSV(DataSet::IDs);
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
    
    ReadFromCSV(DataSet::Clients);
    ReadFromCSV(DataSet::Rooms);
    ReadFromCSV(DataSet::Reservations);
    ReadFromCSV(DataSet::IDs);

    if (clients.empty())
    {
        AddClient();
    }

    if (rooms.empty())
    {
        AddRoom();
    }

    reservationID = ++ids.at("Reservation");

    //TODO walidacja
    std::cout << "Podaj daty rezerwacji, jezeli nie chcesz podawac wiecej - wpisz 0 " << std::endl;
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

    PrintEntityHeading(rooms.front());
    std::vector<int> availableRooms;
    for (const auto& room : rooms) {
        auto roomPtr = std::make_unique<const Room>(room);
        PrintEntityWithFilter(roomPtr.get(), [&](const Entity* entity) //No suitable conversion function from "std::unique_ptr<const Room, std::default_delete<const Room>>" to "const Entity *" exists - muszê tu zastosowaæ get(), aby dopasowaæ siê do pierwszego parametru funkcji PrintEntityWithFilter

            {
            if (auto roomPtr = dynamic_cast<const Room*>(entity))
            {
                bool roomAvailable = true;
                for (const auto& date : dates)
                {
                    if (std::find_if(reservations.begin(), reservations.end(), [&](const auto& reservation)
                        {
                            return reservation.getRoomID() == roomPtr->getRoomID() && date == reservation.getDate();
                        }) != reservations.end())
                    {
                        roomAvailable = false;
                        break;
                    }
                }
                if (roomAvailable)
                {
                    availableRooms.push_back(roomPtr->getRoomID());
                }

                return roomAvailable;
            }
            return false;
            });
    }

    do
    {
        std::cout << "Podaj ID pokoju" << std::endl;
        std::cin >> selectedRoomID;
    } while (std::find(availableRooms.begin(), availableRooms.end(), selectedRoomID) == availableRooms.end());
    
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

void HotelManager::RemoveEntity(const DataSet ds)
{
    int id;
    char c;
    bool removedFlag = false;
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
            if (reservations.empty())
            {
                ReadFromCSV(DataSet::Reservations);
            }
            reservations.erase(std::remove_if(reservations.begin(), reservations.end(), [id](const auto& reservation) {
                if (reservation.getClientID() == id)
                {
                    std::cout << "Rezerwacja o id:" << reservation.getReservationID() << " zostanie usunieta" << std::endl;
                }
                return reservation.getClientID() == id;
                }), reservations.end());

            std::cout << "Czy potwierdzasz?";

            do
            {
                c = _getch();
            } while (c != 'n' && c != 'y');

            if (c == 'y')
            {
                SaveToCSV(DataSet::Reservations);
            }
            SaveToCSV(DataSet::Rooms);
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
        } while (c != 'n' && c != 'y');
        if (c == 'y')
        {
            if (reservations.empty())
            {
                ReadFromCSV(DataSet::Reservations);
            }
            reservations.erase(std::remove_if(reservations.begin(), reservations.end(), [id](const auto& reservation) {
                if (reservation.getRoomID() == id)
                {
                    std::cout << "Rezerwacja o id:" << reservation.getReservationID() << " zostanie usunieta" << std::endl;
                }
                return reservation.getRoomID() == id;
                }), reservations.end());
            std::cout << "Czy potwierdzasz?";
            do
            {
                c = _getch();
            } while (c != 'n' && c != 'y');
            if (c == 'y')
            {
                SaveToCSV(DataSet::Reservations);
            }
            SaveToCSV(DataSet::Rooms);
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
        break;
    default:
        throw std::string("Zly parametr dla RemoveEntity");
        break;
    }
}

void HotelManager::RemoveClient(const int id)
{
    auto sizeBeforeRemoval = clients.size();

    clients.erase(std::remove_if(clients.begin(), clients.end(), [id](const Client& client) {
        return client.getID() == id;
        }), clients.end());

    auto sizeAfterRemoval = clients.size();

    if (sizeAfterRemoval < sizeBeforeRemoval) {
        std::cout << "Klient " << id << " zostal usuniety." << std::endl;
    }
    else {
        throw std::string("Nie znaleziono klienta z podanym id ");
    }
}

void HotelManager::RemoveRoom(const int id)
{
    auto sizeBeforeRemoval = rooms.size();

    rooms.erase(std::remove_if(rooms.begin(), rooms.end(), [id](const Room& room) {
        return room.getRoomID() == id;
        }), rooms.end());

    auto sizeAfterRemoval = rooms.size();

    if (sizeAfterRemoval < sizeBeforeRemoval) {
        std::cout << "Pokoj " << id << " zostal usuniety." << std::endl;
    }
    else {
        throw std::string("Nie znaleziono pokoju z podanym id ");
    }
}

void HotelManager::RemoveReservation(const int id)
{
    auto sizeBeforeRemoval = reservations.size();

    reservations.erase(std::remove_if(reservations.begin(), reservations.end(), [id](const Reservation& reservation) {
        return reservation.getReservationID() == id;
        }), reservations.end());

    auto sizeAfterRemoval = reservations.size();

    if (sizeAfterRemoval < sizeBeforeRemoval) {
        std::cout << "Rezerwacja " << id << " zostala usunieta." << std::endl;
    }
    else {
        throw std::string("Nie znaleziono rezerwacji z podanym id ");
    }
}

void HotelManager::PrintEntity(const DataSet ds)
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

        PrintEntityHeading(rooms.front());
        for (const auto& room : rooms)
        {
            PrintEntityData(room);
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
        throw std::string("Wrong attribute for PrintEntity()");
        break;
    }
}

void HotelManager::EditData()
{
    //TODO Reservation/Room
    if (clients.empty())
    {
        ReadFromCSV(DataSet::Clients);
    }
    int id;
    std::cout << "Wybierz id klienta: ";
    std::cin >> id;

    auto it = std::find_if(clients.begin(), clients.end(), [&](const auto& client)
        {
            return client.getID() == id;
        });
    Client& foundClient = *it;
    EditEntity(foundClient);
}

void HotelManager::PrintEntityHeading(const Entity& entity)
{
    entity.PrintHeading();
}

void HotelManager::PrintEntityData(const Entity& entity)
{
    entity.Print();
}

void HotelManager::EditEntity(Entity& entity)
{
    entity.Edit();
}

void HotelManager::PrintEntityWithFilter(const Entity* entity, std::function<bool(const Entity*)> filter)
{
    if (filter(entity))
    {
        entity->Print();
    }
}
