#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <fstream>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"

using namespace std;

template <typename T>
int genericSearch(const vector<T>& list, string key) {
    for (size_t i = 0; i < list.size(); ++i) {
        if (list[i]->getFlightNumber() == key) {
            return i;
        }
    }
    return -1;
}

class Airline {
private:
    vector<Flight*> flights;
    vector<Passenger*> passengers;
    vector<Ticket*> tickets;

public:
    ~Airline();

    void addFlight(Flight* f);
    void registerPassenger(Passenger* p);
    void listFlights();
    void viewPassengerHistory(string pID);
    
    void bookTicket(string tID, string pID, string fNo);
    void cancelAndRefund(string tID);
    
    void generateReports();
    void saveData(string filename);
    void loadData(string filename);
};

#endif