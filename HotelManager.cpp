#include "HotelManager.h"

void HotelManager::AddClient() {
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

void HotelManager::AddClientFromConsole() {
    std::string name, surname, email, phoneNumber, peselID;

    std::cout << "Podaj imie klienta: ";
    std::getline(std::cin, name);

    std::cout << "Podaj nazwisko klienta: ";
    std::getline(std::cin, surname);

    std::cout << "Podaj adres e-mail klienta: ";
    std::getline(std::cin, email);

    std::cout << "Podaj numer telefonu klienta: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Podaj pesel klienta: ";
    std::getline(std::cin, peselID);

    Client newClient(name, surname, email, phoneNumber, peselID);
    clients.push_back(newClient);
}

void HotelManager::SaveClientsToCSV()
{
    
    std::ofstream file(filenameClient, std::ios::app);

    if (file.is_open())
    {
        for (const auto& client : clients)
        {
            file << client.getName() << "," << client.getSurname() << "," << client.getEmail() << "," << client.getPhoneNumber() << "," << client.getPeselID() << "\n";
        }
        file.close();
        std::cout << "Clients data added to " << filenameClient << std::endl;
        clients.clear();
    }
    else
    {
        std::cout << "Error while opening file: " << filenameClient << std::endl;
    }
}

void HotelManager::ReadClientsFromCSV()
{
    std::ifstream file(filenameClient);
    clients.clear();

    if (file.is_open())
    {
        std::string line;
        size_t pos = 0;
        while (std::getline(file, line))
        {
            std::vector<std::string> cells;
        
            while ((pos = line.find(",")) != std::string::npos)
            {
                std::string cell = line.substr(0, pos);
                cells.push_back(cell);
                line.erase(0, pos + 1);
            }
            cells.push_back(line);

            Client clientFromCSV(cells[0], cells[1], cells[2], cells[3], cells[4]);
            clients.push_back(clientFromCSV);
        }

        file.close();

        for (const auto& client : clients)
        {
            std::cout << "Imie: " << client.getName() << std::endl;
            std::cout << "Nazwisko: " << client.getSurname() << std::endl;
            std::cout << "Email: " << client.getEmail() << std::endl;
            std::cout << "Numer telefonu: " << client.getPhoneNumber() << std::endl;
            std::cout << "Pesel: " << client.getPeselID() << std::endl;
            std::cout << "==================================================" << std::endl;
        }
    }
    else
    {
        std::cout << "Error while opening file: " << filenameClient << std::endl;
    }
    
}
