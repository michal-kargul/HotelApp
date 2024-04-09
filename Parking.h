#pragma once

#include <iostream>
#include <vector>
#include <concepts>
#include "Vehicle.h"

template<typename T>
concept VehicleConcept = requires(T v)
{
    { v.GetPlateNumber() } -> std::convertible_to<std::string>;
};

class Parking {
public:

    template <VehicleConcept T>
    void Park(T& vehicle) {
        std::cout << "Zaparkowano pojazd z numerem rejestracyjnym: " << vehicle.GetPlateNumber() << std::endl;
        parkedVehicles.push_back(vehicle);
    }

    void Unpark(const std::string& plateNumber);

    void DisplayParkedVehicles() const;

private:
    std::vector<Vehicle> parkedVehicles;
};