#include <iostream>
using namespace std;

class Ticket
{
    protected:
        string ticketID;
        string passengerName;
        double price;
        string date;
        string destination;
    
    public:
        Ticket(string id, string name, double p, string d, string dest): ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

        virtual void reserve()
        {
            cout << "Reserving a ticket for " << passengerName << "!" << endl;
        }

        virtual void cancel()
        {
            cout << "Cancelling a ticket for " << passengerName << "!" << endl;
        }

        virtual void displayTicketInfo()
        {
            cout << "Ticket ID: " << ticketID << endl;
            cout << "Passenger name: " << passengerName << endl;
            cout << "Price: " << price << endl;
            cout << "Date: " << date << endl;
            cout << "Destination" << destination << endl << endl;
        }
};

class FlightTicket: public Ticket
{
    protected:
        string airlineName;
        int flightNumber;
        string seatClass;

    public:
        FlightTicket(string id, string name, double p, string d, string dest, string airName, int num, string sC): Ticket(id, name, p, d, dest), airlineName(airName), flightNumber(num), seatClass(sC) {}

        void displayTicketInfo() override
        {
            cout << "Ticket ID: " << ticketID << endl;
            cout << "Passenger name: " << passengerName << endl;
            cout << "Price: " << price << endl;
            cout << "Date: " << date << endl;
            cout << "Destination" << destination << endl;
            cout << "Airline name: " << airlineName << endl;
            cout << "Flight number: " << flightNumber << endl;
            cout << "Seat class: " << seatClass << endl << endl;
        }
};

class TrainTicket: public Ticket
{
    protected:
        int trainNumber;
        string coachType;
        string departureTime;

    public:
        TrainTicket(string id, string name, double p, string d, string dest, int tN, string cT, string dT): Ticket(id, name, p, d, dest), trainNumber(tN), coachType(cT), departureTime(dT) {}

        void reserve() override
        {

        }
};

class BusTicket: public Ticket
{
    protected:
        string busCompany;
        int seatNumber;

    public:
        BusTicket(string id, string name, double p, string d, string dest, string bC, int sN): Ticket(id, name, p, d, dest), busCompany(bC), seatNumber(sN) {}

        void cancel() override
        {

        }
};

class ConcertTicket: public Ticket
{
    protected:
        string artistName;
        string venue;
        string seatType;

    public:
        ConcertTicket(string id, string name, double p, string d, string dest, string aN, string ven, string sT): Ticket(id, name, p, d, dest), artistName(aN), venue(ven), seatType(sT) {}

        void
};

int main()
{


    return 0;
}