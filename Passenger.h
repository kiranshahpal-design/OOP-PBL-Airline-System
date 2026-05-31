#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passenger {
protected:
    string passengerID;
    string name;
    vector<string> bookingHistory;

public:
    Passenger(string pID, string pName);
    virtual ~Passenger() {}

    virtual double getRefundPercentage() = 0;
    virtual void displayPassengerInfo() = 0;

    string getPassengerID() const;
    string getName() const;
    void addBooking(string ticketID);
    vector<string> getBookingHistory() const;
};

class EconomyPassenger : public Passenger {
public:
    EconomyPassenger(string pID, string pName);
    double getRefundPercentage() override;
    void displayPassengerInfo() override;
};

class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string pID, string pName);
    double getRefundPercentage() override;
    void displayPassengerInfo() override;
};

class FirstClassPassenger : public Passenger {
public:
    FirstClassPassenger(string pID, string pName);
    double getRefundPercentage() override;
    void displayPassengerInfo() override;
};

#endif