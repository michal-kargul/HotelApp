#include "Room.h"
#include "Client.h"
#include "Reservation.h"
#include <iostream>
#include <sstream>
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
    void ReadFromCSV(const std::string& whatToRead);
    void AddRoom();
    void PrintRooms();
    void PrintRooms(int date);
    void PrintReservations();
    void AddReservation();
    void AddReservationFromConsole();

private:
    void AddClientFromConsole();
    void SaveClientsToCSV();
    std::vector<Client> clients;
    const std::string filenameClient = "clients.csv";
    void AddRoomFromConsole();
    void SaveRoomsToCSV();
    void SaveReservationsToCSV();
    std::vector<Room> rooms;
    const std::string filenameRoom = "rooms.csv";
    const std::string filenameReservation = "reservations.csv";
    std::vector<Reservation> reservations;
};
