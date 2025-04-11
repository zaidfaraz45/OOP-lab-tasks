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
            cout << "Destination: " << destination << endl;
        }

        virtual ~Ticket() {}
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
            Ticket::displayTicketInfo();
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
            cout << "Reserving a seat for " << passengerName << " on Train #" << trainNumber << "(" << coachType << ")!" << endl;
        }

        void displayTicketInfo() override
        {
            Ticket::displayTicketInfo();
            cout << "Train number: " << trainNumber << endl;
            cout << "Coach type: " << coachType << endl;
            cout << "Departure time: " << departureTime << endl << endl;
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
            cout << "Cancelling bus ticket for " << passengerName << "! Refund issued for last-minute cancellation!" << endl;
        }

        void displayTicketInfo() override
        {
            Ticket::displayTicketInfo();
            cout << "Bus company: " << busCompany << endl;
            cout << "Seat number: " << seatNumber << endl << endl;
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

        void displayTicketInfo() override
        {
            cout << "Ticket ID: " << ticketID << endl;
            cout << "Passenger name: " << passengerName << endl;
            cout << "Price: " << price << endl;
            cout << "Date: " << date << endl;
            cout << "Venue: " << venue << endl;
            cout << "Artist: " << artistName << endl;
            cout << "Seat type: " << seatType << endl << endl;
        }
};

int main()
{
    Ticket* t1 = new FlightTicket("FT001", "Ali", 1500.0, "2025-05-10", "Dubai", "Emirates", 717, "Business");
    Ticket* t2 = new TrainTicket("TT002", "Sara", 800.0, "2025-04-20", "Lahore", 35, "AC", "09:00 AM");
    Ticket* t3 = new BusTicket("BT003", "Ahmed", 500.0, "2025-04-22", "Islamabad", "SkyWays", 12);
    Ticket* t4 = new ConcertTicket("CT004", "Zainab", 3000.0, "2025-06-15", "Karachi", "Atif Aslam", "Expo Center", "Front Row");

    t1->reserve();
    t1->displayTicketInfo();

    t2->reserve(); 
    t2->displayTicketInfo();

    t3->cancel(); 
    t3->displayTicketInfo();

    t4->displayTicketInfo(); 

    delete t1;
    delete t2;
    delete t3;
    delete t4;

    return 0;
}
