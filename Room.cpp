#include "Room.h"

Room::Room(int roomID, const std::string& roomNumber, int capacity, double pricePerNight, bool isAvailable)
    : roomID(roomID), roomNumber(roomNumber), capacity(capacity), pricePerNight(pricePerNight), available(isAvailable)
{}


const int Room::getRoomID() const
{
    return roomID;
}

const std::string& Room::getRoomNumber() const
{
    return roomNumber;
}

void Room::setRoomNumber(const std::string& roomNumber)
{
    this->roomNumber = roomNumber;
}

const int Room::getCapacity() const
{
    return capacity;
}

void Room::setCapacity(int capacity)
{
    this->capacity = capacity;
}

const double Room::getPricePerNight() const
{
    return pricePerNight;
}

void Room::setPricePerNight(double price)
{
    pricePerNight = price;
}

const bool Room::isAvailable() const
{
    return available;
}

void Room::setAvailability(bool available)
{
    this->available = available;
}

void Room::PrintHeading() const
{
    std::cout << std::left << std::setw(15) << "ID pokoju" << std::setw(15) << "Numer pokoju" << std::setw(10) << "Pojemnosc" << std::setw(15) << "Cena za noc" << std::setw(10) << "Dostepnosc" << "\n";
}

void Room::Print() const
{
    std::cout << std::setw(15) << getRoomID() << std::setw(15) << getRoomNumber() << std::setw(10) << getCapacity() << std::setw(15) << getPricePerNight() << std::setw(10) << isAvailable() << "\n";
}

void Room::Edit()
{
    //TODO
}

void Room::ProcessData(std::ostream& str) const
{
    str << getRoomID() << "," << getRoomNumber() << "," << getCapacity() << "," << getPricePerNight() << "," << isAvailable() << "\n";
}
