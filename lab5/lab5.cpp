#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class TicketOffice {

protected:
    string DateOfDispatch;
    string ArrivalTime;
    string PointName;
    int hours;
    int minutes;
    float PriceOfTicket;
    int NumberOfTicket;
    string Database = "C:\\Users\\dimas\\OneDrive\\Робочий стіл\\Database.txt";
    TicketOffice* ticket;

public:
   
    
    void SetTicketsInDatabse() {
        int n = 0;
        cout << "Enter number of tickets -> ";
        cin >> n;

        ticket = new TicketOffice[n];

        ofstream databaseW(Database, ios::app | ios::out);

        for (int i = 0; i < n; i++) {
            cout << "Enter details for ticket:  " << i + 1 << ":\n";
            cout << "Enter number of ticket: ";
            cin >> ticket[i].NumberOfTicket;
            cout << "Enter point name: ";
            cin >> ticket[i].PointName;
            cout << "Enter Hour: ";
            cin >> ticket[i].hours;
            cout << "Enter minutes: ";
            cin >> ticket[i].minutes;
            cout << "Enter arrival time: ";
            cin >> ticket[i].ArrivalTime;
            cout << "Enter date of dispatch: ";
            cin >> ticket[i].DateOfDispatch;
            cout << "Entter price of ticket: ";
            cin >> ticket[i].PriceOfTicket;
            cout << '\n';
            databaseW << ticket[i].NumberOfTicket << ' ' << ticket[i].PointName << ' ' << ticket[i].hours << ' ' << ticket[i].minutes << ' ' << ticket[i].ArrivalTime << ' ' << ticket[i].DateOfDispatch << ' ' << ticket[i].PriceOfTicket << '\n';
           
        }
        databaseW.close();
    }
};

class MetodsForDatabase : public TicketOffice {

public:
    void DisplayTickets() {
        ifstream check(Database);
        

        cout << "Available Tickets:\n";
        
      
        while (check >> NumberOfTicket >> PointName >> hours >> minutes >> ArrivalTime >> DateOfDispatch >> PriceOfTicket) {
            cout << "Number: " << NumberOfTicket << ", Point: " << PointName << ", Time: " << hours << ":" << minutes << ", Arrival: " << ArrivalTime << ", Dispatch: " << DateOfDispatch << ", Price: " << PriceOfTicket << endl;
        }

    }

};


int main()
{
    MetodsForDatabase ticket;


    int choise = 0;
    do {
        cout << " -> Manage DATABASE <- " << '\n';
        cout << " 1 -> Add Tickets <- " << '\n';
        cout << " 2 -> Display Avaible Tickets <- " << '\n';
        cout << " 3 -> Exit <- " << '\n';
        cout << "Your choise -> ";
        cin >> choise;
        cout << '\n';

        switch (choise)
        {
        case 1: {
            ticket.SetTicketsInDatabse();
            break;
        }
        case 2: {
            ticket.DisplayTickets();
            break;
        }
        case 3: {
            return 0;
            break;
        }
       
        default:
            cout << "Please enter num from 1 to 3!!!"  << '\n';
            break;
        }
    } while (1);

}