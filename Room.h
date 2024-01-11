#pragma once

class Room
{
public:
    Room(int roomID, int capacity, double pricePerNight, bool isAvailable);

    const int& getRoomID() const;

    const int& getCapacity() const;
    void setCapacity(int capacity);

    const double& getPricePerNight() const;
    void setPricePerNight(double price);

    const bool& isAvailable() const;
    void setAvailability(bool available);

private:
    int roomID;
    int capacity;
    double pricePerNight;
    bool available;
};