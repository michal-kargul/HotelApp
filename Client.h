#pragma once
#include <string>

class Client
{
public:
    Client(const std::string& name, const std::string& surname, const std::string& email, const std::string& phoneNumber, const std::string& peselID);

    const std::string& getName() const;
    void setName(const std::string& name);

    const std::string& getSurname() const;
    void setSurname(const std::string& surname);

    const std::string& getEmail() const;
    void setEmail(const std::string& email);

    const std::string& getPhoneNumber() const;
    void setPhoneNumber(const std::string& phoneNumber);

    const std::string& getPeselID() const;

private:
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;
    std::string peselID;
};