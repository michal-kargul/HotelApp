#include "Client.h"

std::string Client::getName() {
    return name;
}

void Client::setName(std::string name) {
    this->name = name;
}

std::string Client::getSurname() {
    return surname;
}

void Client::setSurname(std::string surname) {
    this->surname = surname;
}

std::string Client::getEmail() {
    return email;
}

void Client::setEmail(std::string email) {
    this->email = email;
}

std::string Client::getPhoneNumber() {
    return phoneNumber;
}

void Client::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

std::string Client::getPeselID() {
    return peselID;
}

void Client::setPeselID(std::string peselID) {
    this->peselID = peselID;
}