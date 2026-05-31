#include <iostream>
#include "Airline.h"

using namespace std;

int main() {
    Airline myAirline;

    myAirline.addFlight(new DomesticFlight("PK301", "KHI", "ISB", 2, 100.0));
    myAirline.addFlight(new InternationalFlight("EK602", "KHI", "DXB", 150, 300.0, true));
    myAirline.addFlight(new CharterFlight("CH700", "LHE", "LND", 10, 500.0, "Al-Maktoum Corp"));

    myAirline.registerPassenger(new EconomyPassenger("P101", "Ali"));
    myAirline.registerPassenger(new BusinessPassenger("P102", "Zainab"));

    myAirline.loadData("airline_data.txt");

    int choice;
    string tID, pID, fNo;

    do {
        cout << "\n=== SkyLink Airways Console Menu ===" << endl;
        cout << "1. List All Flights" << endl;
        cout << "2. Book a Ticket" << endl;
        cout << "3. Cancel a Ticket & Refund" << endl;
        cout << "4. View Passenger Booking History" << endl;
        cout << "5. Generate Management Reports" << endl;
        cout << "6. Exit & Save System State" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n--- Available Flights ---" << endl;
                myAirline.listFlights();
                break;
            case 2:
                cout << "Enter unique Ticket ID: "; cin >> tID;
                cout << "Enter Passenger ID: "; cin >> pID;
                cout << "Enter Flight Number: "; cin >> fNo;
                myAirline.bookTicket(tID, pID, fNo);
                break;
            case 3:
                cout << "Enter Ticket ID to cancel: "; cin >> tID;
                myAirline.cancelAndRefund(tID);
                break;
            case 4:
                cout << "Enter Passenger ID: "; cin >> pID;
                myAirline.viewPassengerHistory(pID);
                break;
            case 5:
                myAirline.generateReports();
                break;
            case 6:
                myAirline.saveData("airline_data.txt");
                cout << "Data saved successfully. Exiting system..." << endl;
                break;
            default:
                cout << "Invalid input! Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}