#include "Flight.h"

using namespace std;

Flight::Flight(string fNo, string orig, string dest, int seats, double fare)
    : flightNumber(fNo), origin(orig), destination(dest), totalSeats(seats), availableSeats(seats), baseFare(fare) {}

string Flight::getFlightNumber() const { return flightNumber; }
string Flight::getOrigin() const { return origin; }
string Flight::getDestination() const { return destination; }
int Flight::getAvailableSeats() const { return availableSeats; }

void Flight::bookSeat() {
    if (availableSeats <= 0) {
        throw FlightFullException();
    }
    availableSeats--;
}

void Flight::releaseSeat() {
    if (availableSeats < totalSeats) {
        availableSeats++;
    }
}

ostream& operator<<(ostream& os, Flight& f) {
    f.displayDetails();
    return os;
}

DomesticFlight::DomesticFlight(string fNo, string orig, string dest, int seats, double fare)
    : Flight(fNo, orig, dest, seats, fare) {}

double DomesticFlight::calculateBaseFare() {
    return baseFare;
}

void DomesticFlight::displayDetails() {
    cout << "[Domestic Flight] No: " << flightNumber << " | " << origin << " -> " << destination 
         << " | Seats: " << availableSeats << "/" << totalSeats << " | Fare: $" << calculateBaseFare() << endl;
}

InternationalFlight::InternationalFlight(string fNo, string orig, string dest, int seats, double fare, bool visaReq)
    : Flight(fNo, orig, dest, seats, fare), visaRequired(visaReq) {}

double InternationalFlight::calculateBaseFare() {
    return baseFare + 150.0;
}

void InternationalFlight::displayDetails() {
    cout << "[International Flight] No: " << flightNumber << " | " << origin << " -> " << destination 
         << " | Seats: " << availableSeats << "/" << totalSeats << " | Fare: $" << calculateBaseFare() 
         << " | Visa Req: " << (visaRequired ? "Yes" : "No") << endl;
}

CharterFlight::CharterFlight(string fNo, string orig, string dest, int seats, double fare, string holder)
    : Flight(fNo, orig, dest, seats, fare), contractHolder(holder) {}

double CharterFlight::calculateBaseFare() {
    return baseFare * 1.5;
}

void CharterFlight::displayDetails() {
    cout << "[Charter Flight] No: " << flightNumber << " | " << origin << " -> " << destination 
         << " | Seats: " << availableSeats << "/" << totalSeats << " | Fare: $" << calculateBaseFare() 
         << " | Holder: " << contractHolder << endl;
}