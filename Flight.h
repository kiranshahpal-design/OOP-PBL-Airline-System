#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class FlightFullException : public exception {
public:
    const char* what() const throw() {
        return "Error: Flight is completely full!";
    }
};

class Flight {
protected:
    string flightNumber;
    string origin;
    string destination;
    int totalSeats;
    int availableSeats;
    double baseFare;

public:
    Flight(string fNo, string orig, string dest, int seats, double fare);
    virtual ~Flight() {}

    virtual double calculateBaseFare() = 0;
    virtual void displayDetails() = 0;

    string getFlightNumber() const;
    string getOrigin() const;
    string getDestination() const;
    int getAvailableSeats() const;
    void bookSeat();
    void releaseSeat();

    friend ostream& operator<<(ostream& os, Flight& f);
};

class DomesticFlight : public Flight {
public:
    DomesticFlight(string fNo, string orig, string dest, int seats, double fare);
    double calculateBaseFare() override;
    void displayDetails() override;
};

class InternationalFlight : public Flight {
private:
    bool visaRequired;
public:
    InternationalFlight(string fNo, string orig, string dest, int seats, double fare, bool visaReq);
    double calculateBaseFare() override;
    void displayDetails() override;
};

class CharterFlight : public Flight {
private:
    string contractHolder;
public:
    CharterFlight(string fNo, string orig, string dest, int seats, double fare, string holder);
    double calculateBaseFare() override;
    void displayDetails() override;
};

#endif