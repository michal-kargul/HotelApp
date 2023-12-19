#pragma once

class Room
{
public:
    Room(int roomNumber, int capacity, double pricePerNight, bool isAvailable);

    int getRoomNumber();
    void setRoomNumber(int roomNumber);

    int getCapacity();
    void setCapacity(int capacity);

    double getPricePerNight();
    void setPricePerNight(double price);

    bool isAvailable();
    void setAvailability(bool available);

private:
    int roomNumber;
    int capacity;
    double pricePerNight;
    bool available;
};