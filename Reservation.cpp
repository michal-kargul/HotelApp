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