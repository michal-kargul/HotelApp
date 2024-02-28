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
#include <functional>


enum class DataSet
{
    Clients,
    Rooms,
    Reservations
};

class HotelManager
{
public:

    void AddClient();
    void ReadFromCSV(const DataSet ds);
    void AddRoom();
    void PrintEntity(const DataSet ds);
    void RemoveEntity(const DataSet ds);
    void PrintEntityHeading(const Entity& entity);
    void PrintEntityData(const Entity& entity);
    void EditData();
    void EditEntity(Entity& entity);
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
    void RemoveRoom(int id);
    void RemoveClient(int id);
    void RemoveReservation(int id);
    void PrintEntityWithFilter(const Entity* entity, std::function<bool(const Entity*)> filter);
};
