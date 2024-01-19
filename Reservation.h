#pragma once

class Reservation
{
public:
    Reservation(int reservationID, int roomID, int clientID, int date, bool paid, bool status);

    const int& getReservationID() const;

    const int& getRoomID() const;
    void setRoomID(int roomID);

    const int& getClientID() const;
    void setClientID(int clientID);

    const int& getDate() const;
    void setDate(int date);

    const bool& isPaid() const;
    void setPaid(bool paid);

    const bool& getStatus() const;
    void setStatus(bool status);

private:
    int reservationID;
    int roomID;
    int clientID;
    int date;
    bool paid;
    bool status;
};