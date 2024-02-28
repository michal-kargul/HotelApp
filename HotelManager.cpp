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
    default:
        std::cerr << "Zly parametr dla RemoveEntity";
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

    ReadFromCSV(DataSet::Rooms);

    if (rooms.empty())
    {
        id = 1;
    }
    else
    {
        const auto& lastRoom = rooms.back();
        id = lastRoom.getRoomID() + 1;
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
    
    ReadFromCSV(DataSet::Clients);
    ReadFromCSV(DataSet::Rooms);
    ReadFromCSV(DataSet::Reservations);

    if (clients.empty())
    {
        AddClient();
    }

    if (rooms.empty())
    {
        AddRoom();
    }

    if (reservations.empty())
    {
        reservationID = 1;
    }
    else
    {
        const auto& lastReservation = reservations.back();
        reservationID = lastReservation.getReservationID() + 1;
    }

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
        PrintEntityWithFilter(roomPtr.get(), [&](const Entity* entity) //No suitable conversion function from "std::unique_ptr<const Room, std::default_delete<const Room>>" to "const Entity *" exists - musz� tu zastosowa� get(), aby dopasowa� si� do pierwszego parametru funkcji PrintEntityWithFilter

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
            reservations.erase(std::remove_if(reservations.begin(), reservations.end(), [id](const Reservation& reservation) {
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
                SaveReservationsToCSV();
            }
            SaveRoomsToCSV();
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
            reservations.erase(std::remove_if(reservations.begin(), reservations.end(), [id](const Reservation& reservation) {
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
                SaveReservationsToCSV();
            }
            SaveRoomsToCSV();
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
        std::cerr << "Zly parametr dla RemoveEntity";
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
        std::cerr << "Nie znaleziono klienta z podanym id " << id << std::endl;
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
        std::cerr << "Nie znaleziono pokoju z podanym id " << id << std::endl;
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
        std::cerr << "Nie znaleziono rezerwacji z podanym id " << id << std::endl;
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
        std::cerr << "Wrong attribute for PrintEntity()";
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

    auto it = std::find_if(clients.begin(), clients.end(), [&](const Client& client)
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
