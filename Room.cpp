#include "Room.h"

Room::Room(int roomID, int capacity, double pricePerNight, bool isAvailable)
    : roomID(roomID), capacity(capacity), pricePerNight(pricePerNight), available(isAvailable)
{}


const int Room::getRoomID() const
{
    return roomID;
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