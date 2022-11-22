#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;
void admin_menu();
class Administration
{
private:
    string uid = "admin1";
    string pwd = "adminpassword";
    int status = 0;

public:
    int tickets;
    Administration()
    {
        tickets = 0;
    }
    void operator++(int)
    {
        tickets++;
    }
    void increaseticket()
    {
        tickets++;
    }
    void authenticate()
    {
        string id, pass;
        cout << "enter user id: " << endl;
        cin >> id;
        cout << "enter password: " << endl;
        cin >> pass;
        try
        {
            if (id == uid && pass == pwd)
            {
                cout << "Logged In Successfully" << endl;
                admin_menu();
            }
            else
            {
                throw(1);
            }
        }
        catch (int c)
        {
            cout << "Invalid credentials" << endl;
        }
    }
    friend void showstatus();
    friend void updatestatus();
} a;

void showstatus()
{
    if (a.status == 0)
    {
        cout << "Occuppancy not updated!" << endl;
    }
    else
    {
        cout << "Occuppancy: " << a.status << endl;
    }
    if (a.tickets == 0)
    {
        cout << "Ticket count not updated!" << endl;
    }
    else
    {
        cout << "Tickets Sold: " << a.tickets << endl;
    }
}

void updatestatus()
{
    cout << "Enter current Occuppancy: " << endl;
    cin >> a.status;
    cout << "Enter tickets sold: " << endl;
    cin >> a.tickets;
}

void addfilm()
{   
    int n;
    ofstream ofile;
    ofile.open("movies.txt",ios::out | ios::app);
    cout << "enter no. of films to add" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string movies;
        cout << "enter movies" << endl;
        cin >> movies;
        ofile << movies << endl;
    }
    ofile.close();
    
}

void showfilms()
{
    fstream ifile;
    ifile.open("movies.txt", ios::in);
    if (ifile.is_open())
    {
        string film;
        while (getline(ifile, film))
        {
            cout << film << "" << endl;
        }
        ifile.close();
    }
    ifile.close();
}

void admin_menu()
{
    int w;
    while (true)
    {
        cout << "1. Add films" << endl;
        cout << "2. Show films" << endl;
        cout << "3. Check Status" << endl;
        cout << "4. Update Status" << endl;
        cout << "5. Exit" << endl;
        cout << "choose:" << endl;
        cin >> w;
        switch (w)
        {
        case 1:
        {
            addfilm();
            break;
        }
        case 2:
            showfilms();
            break;
        case 3:
            showstatus();
            break;
        case 4:
            updatestatus();
            break;
        case 5:
            exit(0);
        }
    }
}

class Ticket
{
public:
    string name;
    int number;
    int seattype;
    int time;

    Ticket(string a, int b, int c)
    {
        name = a;
        number = b;
        time = c;
    };
    friend void Ticketdisplay();
};

void display()
{
    int b, c, x, time, number, amount;
    char ans;
    string name;

    cout << "The Timings for the show are: " << endl;
    cout << "\n1. 08:00";
    cout << "\n2. 13:00";
    cout << "\n3. 14:50";
    cout << "\n4. 18:00";
    cout << "\n5. 21:00";
    cout << "\n6. 01:00 \n"; 
    cout << "\nPlease select the timing: ";
    cin >> time;
    cout << "\nEnter your name: ";
    cin >> name;
    cout << "\nEnter your contact number: ";
    cin >> number;
    Ticket t(name, number, time);
    cout << "\nSelect the seats: ";
    cout << "\n1.Basic($100 per seat)   2.Premium($200 per seat)" << endl;
    cin >> c;
    cout << "\nEnter the number of tickets you want to purchase: ";
    cin >> x;
    if (c == 1)
    {
        amount = x * 100;
    }
    else if (c == 2)
    {
        amount = x * 200;
    }
    else
    {
        cout << "Invalid input" << endl;
    }
    cout << "\n Amount to be paid: " << amount;
    cout << "\n Payment Successful!" << endl;
    for (int i = 0; i < x; i++)
    {
        a.increaseticket();
    }
    cout<<"---------------------------------------"<<endl;
    cout << "\n\nYour ticket is here: ";
    cout << endl;
    cout << "\n--------TICKET-------\n"
         << endl;
    cout << "\nName 		:" << name;
    cout << "\nContact No	:" << number;
    cout << "\nSeats        :";
    if (c == 1)
    {
        cout << "\tbasic";
    }
    else
    {
        cout << "\tpremium";
    }
    cout << "\nShow timing 	:";
    switch (time)
    {
    case 1:
        cout << "08:00";
        break;
    case 2:
        cout << "13:00";
        break;
    case 3:
        cout << "14:50";
        break;
    case 4:
        cout << "18:00";
        break;
    case 5:
        cout << "21:00";
        break;
    case 6:
        cout << "01:00";
        break;
    }
}

void customerMenu()
{
    int ch;
    cout << "||--------------------------------------------------||" << endl;
    cout << "||              TICKET BOOKING SYSTEM               ||" << endl;
    cout << "||--------------------------------------------------||" << endl;
    cout << "||               Welcome customer!                  ||" << endl;
    cout << "||----The Shows are: ----                           ||" << endl;
    cout << "||   Screen 1. Black Panther                        ||" << endl;
    cout << "||   Screen 2. The Batman                           ||" << endl;
    cout << "||   Screen 3. Days of Future Past                  ||" << endl;
    cout << "||   Screen 4. Hellaro                              ||" << endl;
    cout << "||   Screen 5. Daman                                ||" << endl;
    cout << "||   press 6 : Exit                                 ||" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "     Enter your movie choice                           " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "----Screen 1----" << endl;
        system("CLS");
        display();
        break;
    case 2:
        cout << "----Screen 2----" << endl;
        system("CLS");
        display();
        break;
    case 3:
        cout << "----Screen 3----" << endl;
        system("CLS");
        display();
        break;
    case 4:
        cout << "----Screen 4----" << endl;
        system("CLS");
        display();
        break;
    case 5:
        cout << "----Screen 5----" << endl;
        system("CLS");
        display();
        break;
    case 6:
        exit(0);
        break;
    default:
        "Please enter a valid screen Number";
    }
}

int main()
{
    while (true)
    {
        int r;
        cout<<endl;
        cout<<"\n------Welcome to the ticket booking system!------\n"<<endl;
        cout << "\nYou are : " << endl;
        cout << "\n1. Administration 2. Customer 3. Exit\n";
        cin >> r;
        if (r == 1)
        {
            a.authenticate();
        }
        else if (r == 2)
        {
            customerMenu();
        }
        else if (r == 3)
        {
            exit(0);
        }
        else
        {
            cout << "Please enter valid option";
        }
    }
}
