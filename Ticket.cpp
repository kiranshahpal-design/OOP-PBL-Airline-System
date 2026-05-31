#include "Ticket.h"

using namespace std;

Ticket::Ticket(string tID, string pID, string fNo, double fare)
    : ticketID(tID), passengerID(pID), flightNumber(fNo), farePaid(fare), status("Booked") {}

string Ticket::getTicketID() const { return ticketID; }
string Ticket::getPassengerID() const { return passengerID; }
string Ticket::getFlightNumber() const { return flightNumber; }
double Ticket::getFarePaid() const { return farePaid; }
string Ticket::getStatus() const { return status; }

void Ticket::cancelTicket() {
    if (status == "Cancelled") {
        throw InvalidCancellationException();
    }
    status = "Cancelled";
}

bool Ticket::operator==(const Ticket& other) const {
    return this->ticketID == other.ticketID;
}

ostream& operator<<(ostream& os, Ticket& t) {
    os << "Ticket ID: " << t.ticketID << " | Passenger ID: " << t.passengerID 
       << " | Flight: " << t.flightNumber << " | Paid: $" << t.farePaid << " | Status: " << t.status;
    return os;
}