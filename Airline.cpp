#include "Airline.h"

using namespace std;

Airline::~Airline() {
    for (auto f : flights) delete f;
    for (auto p : passengers) delete p;
    for (auto t : tickets) delete t;
}

void Airline::addFlight(Flight* f) {
    flights.push_back(f);
}

void Airline::registerPassenger(Passenger* p) {
    passengers.push_back(p);
}

void Airline::listFlights() {
    for (auto f : flights) {
        cout << *f;
    }
}

void Airline::viewPassengerHistory(string pID) {
    for (auto p : passengers) {
        if (p->getPassengerID() == pID) {
            p->displayPassengerInfo();
            cout << "Booking History (Ticket IDs): " << endl;
            for (auto tID : p->getBookingHistory()) {
                cout << " - " << tID << endl;
            }
            return;
        }
    }
    cout << "Passenger not found!" << endl;
}

void Airline::bookTicket(string tID, string pID, string fNo) {
    Flight* targetFlight = nullptr;
    Passenger* targetPassenger = nullptr;

    for (auto f : flights) {
        if (f->getFlightNumber() == fNo) {
            targetFlight = f;
            break;
        }
    }
    for (auto p : passengers) {
        if (p->getPassengerID() == pID) {
            targetPassenger = p;
            break;
        }
    }

    if (!targetFlight || !targetPassenger) {
        cout << "Invalid Flight or Passenger ID!" << endl;
        return;
    }

    try {
        targetFlight->bookSeat();
        double fare = targetFlight->calculateBaseFare();
        Ticket* t = new Ticket(tID, pID, fNo, fare);
        tickets.push_back(t);
        targetPassenger->addBooking(tID);
        cout << "Booking Successful! " << *t << endl;
    }
    catch (const FlightFullException& e) {
        cout << e.what() << endl;
    }
}

void Airline::cancelAndRefund(string tID) {
    for (auto t : tickets) {
        if (t->getTicketID() == tID) {
            try {
                t->cancelTicket();
                for (auto f : flights) {
                    if (f->getFlightNumber() == t->getFlightNumber()) {
                        f->releaseSeat();
                        break;
                    }
                }
                double refund = t->getFarePaid();
                for (auto p : passengers) {
                    if (p->getPassengerID() == t->getPassengerID()) {
                        refund *= p->getRefundPercentage();
                        break;
                    }
                }
                cout << "Cancellation Successful! Refund Processed: $" << refund << endl;
            }
            catch (const InvalidCancellationException& e) {
                cout << e.what() << endl;
            }
            return;
        }
    }
    cout << "Ticket ID not found!" << endl;
}

void Airline::generateReports() {
    cout << "\n--- SYSTEM REPORTS ---" << endl;
    cout << "1. Today's Departures (All Scheduled Flights):" << endl;
    listFlights();
    cout << "\n2. Occupancy Percentage per Flight:" << endl;
    for (auto f : flights) {
        cout << "Flight " << f->getFlightNumber() << " Occupancy: " << f->getAvailableSeats() << " seats remaining." << endl;
    }
}

void Airline::saveData(string filename) {
    ofstream outFile(filename);
    if (!outFile) return;
    for (auto t : tickets) {
        outFile << t->getTicketID() << " " << t->getPassengerID() << " " 
                << t->getFlightNumber() << " " << t->getFarePaid() << " " << t->getStatus() << "\n";
    }
    outFile.close();
}

void Airline::loadData(string filename) {
    ifstream inFile(filename);
    if (!inFile) return;
    string tID, pID, fNo, status;
    double fare;
    while (inFile >> tID >> pID >> fNo >> fare >> status) {
        Ticket* t = new Ticket(tID, pID, fNo, fare);
        if (status == "Cancelled") {
            try { t->cancelTicket(); } catch(...) {}
        }
        tickets.push_back(t);
    }
    inFile.close();
}