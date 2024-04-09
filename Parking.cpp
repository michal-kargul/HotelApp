#include "Parking.h"

//void Parking::Park(VehicleConcept auto& vehicle)
//{
//    std::cout << "Zaparkowano pojazd z numerem rejestracyjnym: " << vehicle.GetPlateNumber() << std::endl;
//    parkedVehicles.push_back(vehicle);
// 
//    Nie dzialalo! - Severity	Code	Description	Project	File	Line	Suppression State	Details
//                      Error	LNK2019	unresolved external symbol "public: void __cdecl Parking::Park<class Vehicle>(class Vehicle &)" (? ? $Park@VVehicle@@@Parking@@QEAAXAEAVVehicle@@@Z) referenced in function "public: void __cdecl HotelManager::ParkVehicle(void)" (? ParkVehicle@HotelManager@@QEAAXXZ)	HotelApp	C : \Users\kargu\source\repos\HotelApp\HotelManager.obj	1

//}

void Parking::Unpark(const std::string& plateNumber)
{
    auto it = std::find_if(parkedVehicles.begin(), parkedVehicles.end(), [&](const auto& vehicle)
        {
        return vehicle.GetPlateNumber() == plateNumber;
        });

    if (it != parkedVehicles.end())
    {
        std::cout << "Pojazd z numerem rejestracyjnym: " << plateNumber << " opuscil parking." << std::endl;
        parkedVehicles.erase(it);
    }
    else
    {
        std::cout << "Pojazd z numerem rejestracyjnym " << plateNumber << " nie znajduje sie na parkingu." << std::endl;
    }
}

void Parking::DisplayParkedVehicles() const
{
    std::cout << "Lista zaparkowanych pojazdow:" << std::endl;
    for (const auto& vehicle : parkedVehicles)
    {
        std::cout << "- " << vehicle.GetPlateNumber() << std::endl;
    }
}
