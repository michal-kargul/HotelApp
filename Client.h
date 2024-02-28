#pragma once
#include "Entity.h"
#include <string>

enum class EditMenu
{
    Name = '1',
    Surname = '2',
    Email = '3',
    Phone = '4',
    Exit = '5',
};

class Client : public Entity
{
public:
    Client(const int id, const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber, const std::string& peselID);

    const int getID() const;

    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getSurname() const;
    void setSurname(const std::string& surname);

    const std::string& getEmail() const;
    void setEmail(const std::string& email);

    const std::string& getPhoneNumber() const;
    void setPhoneNumber(const std::string& phoneNumber);

    const std::string& getPeselID() const;

    virtual void PrintHeading() const override;
    virtual void Print() const override;
    virtual void Edit() override;

private:
    int id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string peselID;
};