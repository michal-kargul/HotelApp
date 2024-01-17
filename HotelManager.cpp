#include "HotelManager.h"

void HotelManager::AddClient()
{
    char c;

    do
    {
        HotelManager::AddClientFromConsole();
 
        std::cout << std::endl << "Czy chcesz dodac kolejnego klienta? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n');

    HotelManager::SaveClientsToCSV();
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
            HotelManager::ReadClientsFromCSV();
        }
        else if (clients.empty() && i != 0)
        {
            id = 1;
        }
        else {
            const auto& lastClient = clients.back();
            id = lastClient.getID() + 1;
        }
        i++;
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

void HotelManager::ReadClientsFromCSV() // w sumie mo¿na po³¹czyæ z funkcj¹ ReadRoomsFromCSV, dodaæ parametr na co ma patrzeæ i oprzeæ logikê funkcji na tym parametrze: Klient lub Pokoj
{
    std::ifstream file(filenameClient);
    clients.clear();

    if (file.is_open())
    {
        std::string line;
        size_t pos = 0;

        while (std::getline(file, line)){
                std::vector<std::string> cells;
                
                //Próbowa³em zastosowaæ tutaj (std::getline(file, line, ',')), lecz w plikach csv znajduje siê jeszcze znak '\n', który trochê niszczy dzia³anie tej pêtli.
                //Mo¿na zastosowaæ tutaj (std::getline(file, line, ',')), lecz wtedy prawdopodobnie operacje na stringu s¹ nieuniknione (wiele to nie zmieni).
                //Uwa¿am, ¿e w tej chwili to rozwi¹zanie nie jest z³e.

                while ((pos = line.find(",")) != std::string::npos)
                {
                    std::string cell = line.substr(0, pos);
                    cells.push_back(cell);
                    line.erase(0, pos + 1);
                }
                cells.push_back(line);

                Client clientFromCSV(stoi(cells[0]), cells[1], cells[2], cells[3], cells[4], cells[5]);
                clients.push_back(clientFromCSV);

        }

        file.close();

    }
    else
    {
        std::cerr << "Error while opening file: " << filenameClient << std::endl;
    }
    
}

void HotelManager::PrintClients()
{
    if (clients.empty()) {
        HotelManager::ReadClientsFromCSV();
    }

    for (const auto& client : clients)
    {
        std::cout << "ID: " << client.getID() << std::endl;
        std::cout << "Imie: " << client.getName() << std::endl;
        std::cout << "Nazwisko: " << client.getSurname() << std::endl;
        std::cout << "Email: " << client.getEmail() << std::endl;
        std::cout << "Numer telefonu: " << client.getPhoneNumber() << std::endl;
        std::cout << "Pesel: " << client.getPeselID() << std::endl;
        std::cout << "==================================================" << std::endl;
                
    }
    
}

void HotelManager::AddRoom()
{
    char c;

    do
    {
        HotelManager::AddRoomFromConsole();

        std::cout << std::endl << "Czy chcesz dodac kolejny pokoj? Nacisnij 'Y' jezeli tak, 'N' jezeli nie" << std::endl;
        c = _getch();
        std::cout << std::endl;
    } while (c != 'n');

    HotelManager::SaveRoomsToCSV();
}
// TODO: Walidacja + wziecie pod uwage wiekszej ilosci pokoi na pietro niz 99.
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

    std::cout << "Podaj pietro: ";
    std::cin >> floor;

    lastFloorID = 100 * floor;

    do
    {
        if (rooms.empty() && i == 0)
        {
            HotelManager::ReadRoomsFromCSV();
        }
        else if (rooms.empty() && i != 0)
        {
            id = 1+(floor*100);
        }
        else {
            for (const auto& room : rooms)
            {
                if ((room.getRoomID() > (floor * 100) && room.getRoomID() < ((floor * 100) + 100)) || (floor == 0 && room.getRoomID() > 0 && room.getRoomID() < 100))
                {   
                    if (lastFloorID < room.getRoomID())
                    lastFloorID = room.getRoomID();
                }
            }

            id = lastFloorID + 1;
        }
        i++;
    } while (i == 1);

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

    Room newRoom(id, capacity, pricePerNight, available);
    rooms.push_back(newRoom);
}

void HotelManager::SaveRoomsToCSV()
{

    std::ofstream file(filenameRoom, std::ios::ate);

    if (file.is_open())
    {
        for (const auto& room : rooms)
        {
            file << room.getRoomID() << "," << room.getCapacity() << "," << room.getPricePerNight() << "," << room.isAvailable() << "\n";
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

void HotelManager::ReadRoomsFromCSV()
{
    std::ifstream file(filenameRoom);
    rooms.clear();

    if (file.is_open())
    {
        std::string line;
        size_t pos = 0;

        while (std::getline(file, line)) {
            std::vector<std::string> cells;

            while ((pos = line.find(",")) != std::string::npos)
            {
                std::string cell = line.substr(0, pos);
                cells.push_back(cell);
                line.erase(0, pos + 1);
            }
            cells.push_back(line);

            Room roomFromCSV(stoi(cells[0]), stoi(cells[1]), std::stod(cells[2]), cells[3] == "1");
            rooms.push_back(roomFromCSV);

        }

        file.close();

    }
    else
    {
        std::cerr << "Error while opening file: " << filenameRoom << std::endl;
    }

}

void HotelManager::PrintRooms()
{
    if (rooms.empty()) {
        HotelManager::ReadRoomsFromCSV();
    }

    for (const auto& room : rooms)
    {
        std::cout << "Numer pokoju: " << room.getRoomID() << std::endl;
        std::cout << "Pojemnosc: " << room.getCapacity() << std::endl;
        std::cout << "Cena za noc: " << room.getPricePerNight() << std::endl;
        std::cout << "Dostepnosc: " << room.isAvailable() << std::endl;
        std::cout << "==================================================" << std::endl;

    }

}