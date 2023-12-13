#include "HotelManager.h"

void HotelManager::AddClient(const Client& client) {
    clients.push_back(client);
}

void HotelManager::SaveClientsToCSV(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {
        for (const auto& client : clients) {
            file << client.getName() << "," << client.getSurname() << "," << client.getEmail() << "," << client.getPhoneNumber() << "," << client.getPeselID() << "\n";
        }
        file.close();
        std::cout << "Clients data added to " << filename << std::endl;
    }
    else {
        std::cout << "Error while open file: " << filename << std::endl;
    }
}
