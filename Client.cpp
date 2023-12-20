#include "Client.h"

Client::Client(const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber, const std::string& peselID) : name(name), surname(surname), email(email), phoneNumber(phoneNumber), peselID(peselID) {}

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