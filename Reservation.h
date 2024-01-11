#pragma once

class Reservation
{
public:
    Reservation(int reservationID, int roomID, int clientID, int date, bool paid);

    const int& getReservationID() const;

    const int& getRoomID() const;
    void setRoomID(int roomID);

    const int& getClientID() const;
    void setClientID(int clientID);

    const int& getDate() const;
    void setDate(int date);

    const bool& isPaid() const;
    void setPaid(bool available);

private:
    int reservationID;
    int roomID;
    int clientID;
    int date;
    bool paid;
};