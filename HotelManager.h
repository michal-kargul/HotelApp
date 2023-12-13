#include <iostream>
#include <fstream>
#include <vector>
#include "Room.h"
#include "Client.h"

class HotelManager {
public:

    void AddClient(const Client& client);

    void SaveClientsToCSV(const std::string& filename);

private:
    std::vector<Client> clients;
};
