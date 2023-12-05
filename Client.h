#pragma once
#include <string>

class Client {
public:
    Client(std::string name, std::string surname, std::string email, std::string phoneNumber, std::string peselID) {
        this->name = name;
        this->surname = surname;
        this->email = email;
        this->phoneNumber = phoneNumber;
        this->peselID = peselID;
    }

    std::string getName();
    void setName(std::string name);

    std::string getSurname();
    void setSurname(std::string surname);

    std::string getEmail();
    void setEmail(std::string email);

    std::string getPhoneNumber();
    void setPhoneNumber(std::string phoneNumber);

    std::string getPeselID();
    void setPeselID(std::string peselID);

private:
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string peselID;
};