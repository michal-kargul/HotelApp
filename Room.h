#pragma once
#include "Entity.h"
#include <string>

class Room : public Entity
{
public:
    Room(int roomID, const std::string& roomNumber, int capacity, double pricePerNight, bool isAvailable);

    const int getRoomID() const;

    const std::string& getRoomNumber() const;
    void setRoomNumber(const std::string& name);

    const int getCapacity() const;
    void setCapacity(int capacity);

    const double getPricePerNight() const;
    void setPricePerNight(double price);

    const bool isAvailable() const;
    void setAvailability(bool available);

    virtual void PrintHeading() const override;
    virtual void Print() const override;
    virtual void Edit() override;
    virtual void ProcessData(std::ostream& str) const override;

private:
    int roomID;
    std::string roomNumber;
    int capacity;
    double pricePerNight;
    bool available;
};