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

void Room::setRoomNumber(const std::string& name)
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