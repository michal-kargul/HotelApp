#include "Room.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <vector>


class HotelManager
{
public:

    void AddClient(const Client& client);

    void SaveClientsToCSV(const std::string& filename);

private:
    std::vector<Client> clients;
};
