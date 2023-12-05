#include "Room.h"

int Room::getRoomNumber() {
    return roomNumber;
}

void Room::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

int Room::getCapacity() {
    return capacity;
}

void Room::setCapacity(int capacity) {
    this->capacity = capacity;
}

double Room::getPricePerNight() {
    return pricePerNight;
}

void Room::setPricePerNight(double price) {
    pricePerNight = price;
}

bool Room::isAvailable() {
    return available;
}

void Room::setAvailability(bool available) {
    this->available = available;
}