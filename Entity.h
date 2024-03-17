#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>

class Entity
{
public:
    virtual void PrintHeading() const = 0;
    virtual void Print() const = 0;
    virtual void Edit() = 0;
    virtual void ProcessData(std::ostream& str) const = 0;
};