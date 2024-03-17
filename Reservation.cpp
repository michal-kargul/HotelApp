#include "Reservation.h"

Reservation::Reservation(int reservationID, int roomID, int clientID, int date, bool paid, bool status)
    : reservationID(reservationID), roomID(roomID), clientID(clientID), date(date), paid(paid), status(status)
{}


const int& Reservation::getReservationID() const
{
    return reservationID;
}

const int& Reservation::getRoomID() const
{
    return roomID;
}

void Reservation::setRoomID(int roomID)
{
    this->roomID = roomID;
}

const int& Reservation::getClientID() const
{
    return clientID;
}

void Reservation::setClientID(int clientID)
{
    clientID = clientID;
}

const int& Reservation::getDate() const
{
    return date;
}

void Reservation::setDate(int date)
{
    this->date = date;
}

const bool& Reservation::isPaid() const
{
    return paid;
}

void Reservation::setPaid(bool paid)
{
    this->paid = paid;
}

const bool& Reservation::getStatus() const
{
    return paid;
}

void Reservation::setStatus(bool status)
{
    this->status = status;
}

void Reservation::PrintHeading() const
{
    std::cout << std::left << std::setw(15) << "ID rezerwacji" << std::setw(15) << "ID pokoju" << std::setw(15) << "ID klienta" << std::setw(15) << "Data" << std::setw(10) << "Oplacone" << "\n";
}

void Reservation::Print() const
{
    std::cout << std::setw(15) << getReservationID() << std::setw(15) << getRoomID() << std::setw(15) << getClientID() << std::setw(15) << getDate() << std::setw(10) << isPaid() << "\n";
}

void Reservation::Edit()
{
    //TODO
}

void Reservation::ProcessData(std::ostream& str) const
{
    str << getReservationID() << "," << getRoomID() << "," << getClientID() << "," << getDate() << "," << isPaid() << "," << getStatus() << "\n";
}