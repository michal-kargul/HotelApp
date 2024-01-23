#pragma once
#include <iostream>
#include <iomanip>

class Entity
{
public:
    virtual void PrintHeading() const = 0;
    virtual void Print() const = 0;
};