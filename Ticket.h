#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class InvalidCancellationException : public exception {
public:
    const char* what() const throw() {
        return "Error: Ticket cannot be cancelled or is already cancelled!";
    }
};

class Ticket {
private:
    string ticketID;
    string passengerID;
    string flightNumber;
    double farePaid;
    string status;

public:
    Ticket(string tID, string pID, string fNo, double fare);
    
    string getTicketID() const;
    string getPassengerID() const;
    string getFlightNumber() const;
    double getFarePaid() const;
    string getStatus() const;
    void cancelTicket();

    bool operator==(const Ticket& other) const;
    friend ostream& operator<<(ostream& os, Ticket& t);
};

#endif