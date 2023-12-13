#include "Menu.h"
#include "HotelManager.h"
#include "Client.h"

int main() {

   // Menu m1 = { "1. Pokoje" , "2. Rezerwacje", "3. Rezerwuj" , "4. Rejestruj", "5. Wyjdz", "6. Test"};

    //std::cout << m1.menu();

    HotelManager hotelManager;

    Client client1("Michal2", "Kargul", "michal@test.com", "123456789", "1234567890");
    Client client2("TestMK13", "Testmk2Surn", "test@test.com", "555666444", "1112222333344");
    hotelManager.AddClient(client1);
    hotelManager.AddClient(client2);

    hotelManager.SaveClientsToCSV("clients.csv");

    return 0;
}
