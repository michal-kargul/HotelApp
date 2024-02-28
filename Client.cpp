#include "Client.h"

Client::Client(const int id, const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber, const std::string& peselID)
    : id(id), name(name), surname(surname), email(email), phoneNumber(phoneNumber), peselID(peselID) 
{}

const int Client::getID() const
{
    return id;
}

const std::string& Client::getName() const
{
    return name;
}

void Client::setName(const std::string& name)
{
    this->name = name;
}

const std::string& Client::getSurname() const
{
    return surname;
}

void Client::setSurname(const std::string& surname)
{
    this->surname = surname;
}

const std::string& Client::getEmail() const
{
    return email;
}

void Client::setEmail(const std::string& email)
{
    this->email = email;
}

const std::string& Client::getPhoneNumber() const
{
    return phoneNumber;
}

void Client::setPhoneNumber(const std::string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

const std::string& Client::getPeselID() const
{
    return peselID;
}

void Client::PrintHeading() const
{
    std::cout << std::left << std::setw(4) << "ID" << std::setw(15) << "Imie" << std::setw(15) << "Nazwisko" << std::setw(20) << "Email" << std::setw(15) << "Nr telefonu" << std::setw(15) << "Pesel" << "\n";
}

void Client::Print() const
{
    std::cout << std::setw(4) << getID() << std::setw(15) << getName() << std::setw(15) << getSurname() << std::setw(20) << getEmail() << std::setw(15) << getPhoneNumber() << std::setw(15) << getPeselID() << "\n";
}

void Client::Edit()
{
    std::cout << "Co chcialbys zedytowac? 1 - Imie, 2 - Nazwisko, 3 - Email, 4 - Numer telefonu" << std::endl;
    char c;
    c = _getch();
    std::string newData;
    switch (static_cast<EditMenu>(c))
    {
    case EditMenu::Name:
        std::cout << "Podaj nowe imie: ";
        std::cin >> newData;
        setName(newData);
        std::cout << "Pomyslnie zaktualizowano" << std::endl;
        break;
    case EditMenu::Surname:
        std::cout << "Podaj nowe nazwisko: ";
        std::cin >> newData;
        setName(newData);
        std::cout << "Pomyslnie zaktualizowano" << std::endl;
        break;
    case EditMenu::Email:
        std::cout << "Podaj nowy adres email: ";
        std::cin >> newData;
        setName(newData);
        std::cout << "Pomyslnie zaktualizowano" << std::endl;
        break;
    case EditMenu::Phone:
        std::cout << "Podaj nowy numer telefonu: ";
        std::cin >> newData;
        setName(newData);
        std::cout << "Pomyslnie zaktualizowano" << std::endl;
        break;
    case EditMenu::Exit:
        break;
    }

}