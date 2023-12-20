#include "Room.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>


class HotelManager
{
public:

    void AddClient();
    void ReadClientsFromCSV();

private:
    void AddClientFromConsole();
    void SaveClientsToCSV();
    std::vector<Client> clients;
    const std::string filenameClient = "clients.csv";
};
