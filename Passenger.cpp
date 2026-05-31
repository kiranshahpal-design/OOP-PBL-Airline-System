#include "Passenger.h"

using namespace std;

Passenger::Passenger(string pID, string pName) : passengerID(pID), name(pName) {}

string Passenger::getPassengerID() const { return passengerID; }
string Passenger::getName() const { return name; }

void Passenger::addBooking(string ticketID) {
    bookingHistory.push_back(ticketID);
}

vector<string> Passenger::getBookingHistory() const {
    return bookingHistory;
}

EconomyPassenger::EconomyPassenger(string pID, string pName) : Passenger(pID, pName) {}

double EconomyPassenger::getRefundPercentage() {
    return 0.50;
}

void EconomyPassenger::displayPassengerInfo() {
    cout << "[Economy Passenger] ID: " << passengerID << " | Name: " << name << endl;
}

BusinessPassenger::BusinessPassenger(string pID, string pName) : Passenger(pID, pName) {}

double BusinessPassenger::getRefundPercentage() {
    return 0.75;
}

void BusinessPassenger::displayPassengerInfo() {
    cout << "[Business Passenger] ID: " << passengerID << " | Name: " << name << endl;
}

FirstClassPassenger::FirstClassPassenger(string pID, string pName) : Passenger(pID, pName) {}

double FirstClassPassenger::getRefundPercentage() {
    return 0.90;
}

void FirstClassPassenger::displayPassengerInfo() {
    cout << "[First Class Passenger] ID: " << passengerID << " | Name: " << name << endl;
}