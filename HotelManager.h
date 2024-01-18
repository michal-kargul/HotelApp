#include "Room.h"
#include "Client.h"
#include "Reservation.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <conio.h>
#include <regex>


class HotelManager
{
public:

    void AddClient();
    void PrintClients();
    void ReadClientsFromCSV();
    void AddRoom();
    void PrintRooms();
    void ReadRoomsFromCSV();
    void AddReservation();
    void AddReservationFromConsole();

private:
    void AddClientFromConsole();
    void SaveClientsToCSV();
    std::vector<Client> clients;
    const std::string filenameClient = "clients.csv";
    void AddRoomFromConsole();
    void SaveRoomsToCSV();
    std::vector<Room> rooms;
    const std::string filenameRoom = "rooms.csv";
    std::vector<Reservation> reservations;
};
