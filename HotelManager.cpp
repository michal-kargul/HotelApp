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
            ReadFromCSV("clients");
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


void HotelManager::ReadFromCSV(const std::string& whatToRead)
{
    std::string fileName;

    //TODO whatToRead zamienic na enum i else if na switch.

    if (whatToRead == "clients")
    {
        fileName = filenameClient;
        clients.clear();
    }
    else if (whatToRead == "rooms")
    {
        fileName = filenameRoom;
        rooms.clear();
    }
    else if (whatToRead == "reservations")
    {
        fileName = filenameReservation;
        reservations.clear();
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
            if (whatToRead == "clients")
            {
                Client clientFromCSV(stoi(cells[0]), cells[1], cells[2], cells[3], cells[4], cells[5]);
                clients.push_back(clientFromCSV);
            }
            else if (whatToRead == "rooms")
            {
                Room roomFromCSV(stoi(cells[0]), cells[1], stoi(cells[2]), std::stod(cells[3]), cells[4] == "1");
                rooms.push_back(roomFromCSV);
            }
            else if (whatToRead == "reservations")
            {
                Reservation reservationFromCSV(stoi(cells[0]), stoi(cells[1]), stoi(cells[2]), std::stoi(cells[3]), cells[4] == "1", cells[5] == "1");
                reservations.push_back(reservationFromCSV);
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
            ReadFromCSV("rooms");
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
            ReadFromCSV("clients");
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
            ReadFromCSV("rooms");
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
            ReadFromCSV("reservations");
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
        Reservation newReservation(reservationID, selectedRoomID, selectedClientID, date, paid, true);
        reservations.push_back(newReservation);
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

void HotelManager::PrintEntity(DataSet ds, const std::vector<int>& date)
{
    switch (ds)
    {
    case DataSet::Clients:
        if (clients.empty())
        {
            ReadFromCSV("clients");
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
            ReadFromCSV("rooms");
        }

        if (!date.empty() && reservations.empty())
        {
            ReadFromCSV("reservations");
        }
        
        if (!date.empty())
        {
            PrintEntityHeading(rooms.front());
            for (const auto& room : rooms)
            {
                for (const auto& reservation : reservations)
                {
                    bool dateMatch = false;

                    for (int currentDate : date)
                    {
                        if (currentDate == reservation.getDate())
                        {
                            dateMatch = true;
                            break;
                        }
                    }
                    if (!dateMatch || ((reservation.getRoomID() != room.getRoomID()) && dateMatch)) //Tu jest teraz cos nie tak - do poprawy
                    {
                        PrintEntityData(room);
                    }
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
            ReadFromCSV("reservations");
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
