#include "Vehicle.h"

Vehicle::Vehicle(std::string plateNumber) : plateNumber(plateNumber) {}

std::string Vehicle::GetPlateNumber() const
{
    return plateNumber;
}