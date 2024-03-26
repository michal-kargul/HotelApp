#pragma once
#include "Entity.h"
#include <string>
#include <map>

enum class EditMenu
{
    Name = 1,
    Surname,
    Email,
    Phone,
    Exit,
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

    void PrintHeading() const final;
    void Print() const final;
    void Edit() final;
    void ProcessData(std::ostream& str) const final;

private:
    int id;
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string peselID;
    std::map<EditMenu, std::string> editMenuOptions =
    {
        {EditMenu::Name, "Imie"},
        {EditMenu::Surname, "Nazwisko"},
        {EditMenu::Email, "Email"},
        {EditMenu::Phone, "Numer telefonu"},
        {EditMenu::Exit, "Wyjscie"},
    };
};