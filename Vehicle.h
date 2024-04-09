#pragma once

#include <string>
#include <iostream>


class Vehicle
{
public:
    Vehicle(std::string plateNumber);

    std::string GetPlateNumber() const;

private:
    std::string plateNumber;
};