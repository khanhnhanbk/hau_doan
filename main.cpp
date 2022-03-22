// library
#include <bits/stdc++.h>
using namespace std;

// constants

const int MAX_SIZE = 300;

// struct
struct Plane;
struct DateTime;
struct Ticket;
struct Flight
{
    string flight_number;
    DateTime *departure_time;
    string arrivalAirport;
    Plane *plane;

    Ticket *tickets[MAX_SIZE];
    // int maxTickets;
};
struct Passenger;

// myBST for passenger info
struct PassengerNode;
struct myBST;

// implementation
struct Plane
{
    string id;
    string type;
    int capacity;

    Flight *flights[MAX_SIZE];
    int numFlights;

    Plane(string id, string type, int capacity)
    {
        this->id = id;
        this->type = type;
        this->capacity = capacity;
        numFlights = 0;
    }
};

struct Ticket
{
    int id;
    Passenger *passenger;
    Flight *flight;

    Ticket(int id, Passenger *passenger, Flight *flight)
    {
        this->id = id;
        this->passenger = passenger;
        this->flight = flight;
    }
};

struct Passenger
{
    string id;
    string firstName;
    string lastName;
    string gender;

    Passenger(string id, string firstName, string lastName, string gender)
    {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        this->numTickets = 0;
    }
    Ticket *tickets[MAX_SIZE];
    int numTickets;
};

struct DateTime
{
    int year, month, day, hour, minus;
    DateTime()
    {
    }
    string toString()
    {
        stringstream ss;
        ss << year << "-" << month << "-" << day << " " << hour << ":" << minus;
        return ss.str();
    }
    bool isLeap()
    {
        // Return true if year
        // is a multiple of 4 and
        // not multiple of 100.
        // OR year is multiple of 400.
        return (((year % 4 == 0) &&
                 (year % 100 != 0)) ||
                (year % 400 == 0));
    }

    bool isValidDate()
    {
        if (month < 1 || month > 12)
            return false;
        if (day < 1 || day > 31)
            return false;

        // Handle February month
        // with leap year
        if (month == 2)
        {
            if (isLeap())
                return (day <= 29);
            else
                return (day <= 28);
        }

        // Months of April, June,
        // Sept and Nov must have
        // number of days less than
        // or equal to 30.
        if (month == 4 || month == 6 ||
            month == 9 || month == 11)
            return (day <= 30);

        return true;
    }
};
struct PassengerNode
{
    PassengerNode *left;
    PassengerNode *right;
    PassengerNode *parent;
    Passenger *passenger;
};

struct myBST
{
    PassengerNode *root;
    int size;

    // myBST()
    // {
    //  root = NULL;
    // size = 0;
    // }
    void add(Passenger *passenger)
    {
        if (root == NULL)
        {
            root = new PassengerNode;
            root->passenger = passenger;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
            size++;
        }
        else
        {
            PassengerNode *current = root;
            while (current != NULL)
            {
                if (current->passenger->id == passenger->id)
                {
                    cout << "Passenger already exists" << endl;
                    return;
                }
                else if (current->passenger->id > passenger->id)
                {
                    if (current->left == NULL)
                    {
                        current->left = new PassengerNode;
                        current->left->passenger = passenger;
                        current->left->left = NULL;
                        current->left->right = NULL;
                        current->left->parent = current;
                        size++;
                        return;
                    }
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if (current->right == NULL)
                    {
                        current->right = new PassengerNode;
                        current->right->passenger = passenger;
                        current->right->left = NULL;
                        current->right->right = NULL;
                        current->right->parent = current;
                        size++;
                        return;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    }
    void remove(Passenger *passenger)
    {
        PassengerNode *current = root;
        while (current != NULL)
        {
            if (current->passenger->id == passenger->id)
            {
                if (current->left == NULL && current->right == NULL)
                {
                    if (current->parent->left == current)
                    {
                        current->parent->left = NULL;
                    }
                    else
                    {
                        current->parent->right = NULL;
                    }
                    delete current;
                    size--;
                    return;
                }
                else if (current->left == NULL)
                {
                    if (current->parent->left == current)
                    {
                        current->parent->left = current->right;
                        current->right->parent = current->parent;
                    }
                    else
                    {
                        current->parent->right = current->right;
                        current->right->parent = current->parent;
                    }
                    delete current;
                    size--;
                    return;
                }
                else if (current->right == NULL)
                {
                    if (current->parent->left == current)
                    {
                        current->parent->left = current->left;
                        current->left->parent = current->parent;
                    }
                    else
                    {
                        current->parent->right = current->left;
                        current->left->parent = current->parent;
                    }
                    delete current;
                    size--;
                    return;
                }
                else
                {
                    PassengerNode *temp = current->right;
                    while (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    current->passenger = temp->passenger;
                    if (temp->parent->left == temp)
                    {
                        temp->parent->left = temp->right;
                    }
                    else
                    {
                        temp->parent->right = temp->right;
                    }
                    delete temp;
                    size--;
                    return;
                }
            }
            else if (current->passenger->id > passenger->id)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    void removeById(string id)
    {
        PassengerNode *current = root;
        while (current != NULL)
        {
            if (current->passenger->id == id)
            {
                if (current->left == NULL && current->right == NULL)
                {
                    if (current->parent->left == current)
                    {
                        current->parent->left = NULL;
                    }
                    else
                    {
                        current->parent->right = NULL;
                    }
                    delete current;
                    size--;
                    return;
                }
                else if (current->left == NULL)
                {
                    if (current->parent->left == current)
                    {
                        current->parent->left = current->right;
                        current->right->parent = current->parent;
                    }
                    else
                    {
                        current->parent->right = current->right;
                        current->right->parent = current->parent;
                    }
                    delete current;
                    size--;
                    return;
                }
                else if (current->right == NULL)
                {
                    if (current->parent->left == current)
                    {
                        current->parent->left = current->left;
                        current->left->parent = current->parent;
                    }
                    else
                    {
                        current->parent->right = current->left;
                        current->left->parent = current->parent;
                    }
                    delete current;
                    size--;
                    return;
                }
                else
                {
                    PassengerNode *temp = current->right;
                    while (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    current->passenger = temp->passenger;
                    if (temp->parent->left == temp)
                    {
                        temp->parent->left = temp->right;
                    }
                    else
                    {
                        temp->parent->right = temp->right;
                    }
                    delete temp;
                    size--;
                    return;
                }
            }
            else if (current->passenger->id > id)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    Passenger *find(string id)
    {
        PassengerNode *current = root;
        while (current != NULL)
        {
            if (current->passenger->id == id)
            {
                return current->passenger;
            }
            else if (current->passenger->id > id)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return NULL;
    }

    void displayRec(PassengerNode *current)
    {
        if (current != NULL)
        {
            displayRec(current->left);
            cout << current->passenger->id << '\t' << current->passenger->firstName << '\t' << current->passenger->lastName << '\t' << current->passenger->gender << endl;
            displayRec(current->right);
        }
    }
    void display()
    {
        cout << "Passenger List: " << endl;
        cout << "ID\tfirsName\tlastName\tgender\n";
        displayRec(root);
    }
    void save(string filename)
    {
        ofstream outfile;
        outfile.open(filename);
        saveRec(root, outfile);
        outfile.close();
    }
    void saveRec(PassengerNode *current, ofstream &outfile)
    {
        if (current != NULL)
        {
            saveRec(current->left, outfile);
            outfile << current->passenger->id << endl;
            outfile << current->passenger->firstName << endl;
            outfile << current->passenger->lastName << endl;
            outfile << current->passenger->gender << endl;
            saveRec(current->right, outfile);
        }
    }
    // void load(string filename)
    // {

    // }

    ~myBST()
    {
        PassengerNode *current = root;
        while (current != NULL)
        {
            if (current->left == NULL && current->right == NULL)
            {
                delete current;
                current = NULL;
            }
            else if (current->left == NULL)
            {
                PassengerNode *temp = current->right;
                delete current;
                current = temp;
            }
            else if (current->right == NULL)
            {
                PassengerNode *temp = current->left;
                delete current;
                current = temp;
            }
            else
            {
                PassengerNode *temp = current->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                current->passenger = temp->passenger;
                if (temp->parent->left == temp)
                {
                    temp->parent->left = temp->right;
                }
                else
                {
                    temp->parent->right = temp->right;
                }
                delete temp;
            }
        }
    }
};
// global variables

Plane *planes[MAX_SIZE]; // array of pointers to planes
int numPlanes;

Flight *flights[MAX_SIZE]; // array of pointers to flights
int numFlights;

Ticket *tickets[MAX_SIZE]; // array of pointers to tickets
int numTickets;
struct myBST passengerInfoTree; // tree of passenger info

string airports[22];

const char separator = ' ';
const int planesIdWidth = 12;
const int planesTypeWidth = 12;
const int planesCapacityWidth = 5;

// Flight number\tDeparture time\tArrival airport\tPlane id
const int flightsIdWidth = 12;
const int flightsDepartureTimeWidth = 20;
const int flightsArrivalAirportWidth = 25;
const int flightsPlaneIdWidth = 12;
// function

// function for plane
void addPlane();
void deletePlane();
void modifyPlane();
void displayPlane();
void saveToFilePlane();
void loadFromFilePlane();
// function for flight
void addFlight();
void deleteFlight();
void displayFlight();
void modifyFlight();
void saveToFileFlight();
void loadFromFileFlight();

// function for passenger
void addPassenger();
void deletePassenger();
void displayPassenger();
void modifyPassenger();
void saveToFilePassenger();
void loadFromFilePassenger();

// function for ticket
void addTicket();
void deleteTicket();
void displayTicket();
void modifyTicket();
void saveToFileTicket();
void loadFromFileTicket();
// FINDING
Passenger *findPassenger();
Flight *findFlight(string id);
Ticket *findTicket();
Plane *findPlane(string id);

// function for menu
void showMainMenu();
void showPlaneMenu();
void showFlightMenu();
void showPassengerMenu();
void showTicketMenu();

// load airport
void loadAirport()
{
    ifstream infile;
    infile.open("airport.txt");
    string line;
    int i = 0;
    while (getline(infile, line))
    {
        airports[i] = line;
        i++;
    }
    infile.close();
}
void displayAirport()
{
    for (int i = 0; i < 22; i++)
    {
        cout << left << setw(3) << i + 1 << setw(30) << airports[i];
        if ((i + 1) % 3 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
// body
int main()
{
    // // initialize
    loadAirport();
    // displayAirport();
    numPlanes = 0;
    loadFromFilePlane();
    numFlights = 0;
    loadFromFileFlight();
    passengerInfoTree.root = NULL;
    loadFromFilePassenger();
    numTickets = 0;
    loadFromFileTicket();
    // // menu
    showMainMenu();
    // addFlight();
    saveToFileFlight();
    saveToFilePlane();
    saveToFilePassenger();
    saveToFileTicket();
    return 0;
}
// function for menu
void showPlaneMenu()
{
    int choice;
    do
    {
        cout << "------------------" << endl;
        cout << "1. Add Plane" << endl;
        cout << "2. Delete Plane" << endl;
        cout << "3. Modify Plane" << endl;
        cout << "4. Display Plane" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "------------------" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addPlane();
            break;
        case 2:
            deletePlane();
            break;
        case 3:
            modifyPlane();
            break;
        case 4:
            displayPlane();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);
}
void showFlightMenu()
{
    int choice;
    do
    {
        cout << "------------------" << endl;
        cout << "1. Add new flight" << endl;
        cout << "2. Delete flight" << endl;
        cout << "3. Modify flight" << endl;
        cout << "4. Display all flight" << endl;
        cout << "0. Back to main menu." << endl;
        cout << "------------------" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addFlight();
            break;
        case 2:
            deleteFlight();
            break;
        case 3:
            modifyFlight();
            break;
        case 4:
            displayFlight();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);
};
void showPassengerMenu()
{
    int choice;
    do
    {
        cout << "1. Add Passenger" << endl;
        cout << "2. Delete Passenger" << endl;
        cout << "3. Modify Passenger" << endl;
        cout << "4. Display Passenger" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "7. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addPassenger();
            break;
        case 2:
            deletePassenger();
            break;
        case 3:
            modifyPassenger();
            break;
        case 4:
            displayPassenger();
            break;
        case 5:
            saveToFilePassenger();
            break;
        case 6:
            loadFromFilePassenger();
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 7); // end of do-while
}
void showTicketMenu()
{
    int choice;
    do
    {
        cout << "1. Add Ticket" << endl;
        cout << "2. Delete Ticket" << endl;
        cout << "3. Modify Ticket" << endl;
        cout << "4. Display Ticket" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "7. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addTicket();
            break;
        case 2:
            deleteTicket();
            break;
        case 3:
            modifyTicket();
            break;
        case 4:
            displayTicket();
            break;
        case 5:
            saveToFileTicket();
            break;
        case 6:
            loadFromFileTicket();
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 7); // end of do-while
}
void showMainMenu()
{
    int choice;
    do
    {
        cout << "------------------" << endl;
        cout << "1. Update list of planes." << endl;
        cout << "2. Update flights." << endl;
        cout << "3. Passenger" << endl;
        cout << "4. Ticket" << endl;
        cout << "0. Save and exit" << endl;
        cout << "------------------" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            showPlaneMenu();
            break;
        case 2:
            showFlightMenu();
            break;
        case 3:
            showPassengerMenu();
            break;
        case 4:
            showTicketMenu();
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);
    showMainMenu();
}

void addPlane()
{
    string id;
    string type;
    int capacity;
    cout << "Enter plane id: ";
    cin >> id;

    if (findPlane(id) != NULL)
    {
        cout << "Plane already exists!" << endl;
        return;
    }

    cout << "Enter plane type: ";
    cin >> type;
    cout << "Enter plane capacity: ";
    cin >> capacity;
    if (capacity < 20)
    {
        cout << "Plane capacity must be greater than 20!" << endl;
        return;
    }
    planes[numPlanes] = new Plane(id, type, capacity);
    numPlanes++;
}
void displayPlane()
{
    cout << "Plane list: " << endl;
    cout << left << setw(planesIdWidth) << "ID" << setw(planesTypeWidth) << "Type" << setw(planesCapacityWidth) << "Capacity" << endl;
    for (int i = 0; i < numPlanes; i++)
    {
        cout << left << setw(planesIdWidth) << planes[i]->id << setw(planesTypeWidth) << planes[i]->type << setw(planesCapacityWidth) << planes[i]->capacity << endl;
    }
}
void deletePlane()
{
    displayPlane();
    string id;
    cout << "Enter plane id: ";
    cin >> id;
    for (int i = 0; i < numPlanes; i++)
    {
        if (planes[i]->id == id)
        {
            delete planes[i];
            for (int j = i; j < numPlanes - 1; j++)
            {
                planes[j] = planes[j + 1];
            }
            numPlanes--;
            return;
        }
    }
    cout << "Plane not found" << endl;
}
void saveToFilePlane()
{
    ofstream fout;
    fout.open("plane.txt");
    for (int i = 0; i < numPlanes; i++)
    {
        fout << planes[i]->id << endl;
        fout << planes[i]->type << endl;
        fout << planes[i]->capacity << endl;
    }
    fout.close();
}
void loadFromFilePlane()
{
    ifstream fin("plane.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            string id;
            string type;
            int capacity;
            fin >> id;
            fin >> type;
            fin >> capacity;
            if (id == "")
            {
                break;
            }
            planes[numPlanes] = new Plane(id, type, capacity);
            numPlanes++;
        }
        fin.close();
    }
}
void modifyPlane()
{
    string id;
    string type;
    int capacity;
    displayPlane();
    cout << "Enter plane id: ";
    cin >> id;
    Plane *plane = findPlane(id);
    if (plane == NULL)
    {
        cout << "Plane not found!" << endl;
        return;
    }
    cout << "Enter new plane type: ";
    cin >> type;
    cout << "Enter new plane capacity: ";
    cin >> capacity;
    if (capacity < 20)
    {
        cout << "Plane capacity must be greater than 20!" << endl;
        return;
    }
    plane->type = type;
    plane->capacity = capacity;
}

void addFlight()
{
    Flight *f = new Flight();
    f->departure_time = new DateTime();
    string planeId;
    cout << "Enter flight number: ";
    cin >> f->flight_number;
    // check if flight number already exists
    {
        Flight *flight = findFlight(f->flight_number);
        if (flight != NULL)
        {
            cout << "Flight already exists!" << endl;
            return;
        }
    }
    cout << "Enter departure time:\n";
    cout << "Enter year: ";
    cin >> f->departure_time->year;
    cout << "Enter month: ";
    cin >> f->departure_time->month;
    cout << "Enter day: ";
    cin >> f->departure_time->day;
    // check is valid date
    if (!f->departure_time->isValidDate())
    {
        cout << "Invalid date!" << endl;
        return;
    }
    cout << "Enter hour: ";
    cin >> f->departure_time->hour;
    cout << "Enter minute: ";
    cin >> f->departure_time->minus;
    cout << "Choose arrival airport: (1 -> 22)" << endl;
    ;
    displayAirport();
    cout << "Enter airport id: ";
    int airportId;
    cin >> airportId;
    if (airportId < 1 || airportId > 22)
    {
        cout << "Invalid airport id!" << endl;
        return;
    }
    f->arrivalAirport = airports[airportId - 1];
    cout << "Choose plane: ";
    displayPlane();
    cout << "Enter plane id: ";
    cin >> planeId;
    for (int i = 0; i < numPlanes; i++)
    {
        if (planes[i]->id == planeId)
        {
            f->plane = planes[i];
            planes[i]->flights[planes[i]->numFlights] = f;
            planes[i]->numFlights++;
            break;
        }
    }
    if (f->plane == NULL)
    {
        cout << "Plane not found" << endl;
        return;
    }
    flights[numFlights] = f;
    numFlights++;
}
void modifyFlight()
{
    displayFlight();
    string flightNumber;
    cout << "Enter flight number: ";
    cin >> flightNumber;
    // edit time
    for (int i = 0; i < numFlights; i++)
    {
        if (flights[i]->flight_number == flightNumber)
        {
            cout << "Enter new departure time:\n";
            cout << "Enter year: ";
            cin >> flights[i]->departure_time->year;
            cout << "Enter month: ";
            cin >> flights[i]->departure_time->month;
            cout << "Enter day: ";
            cin >> flights[i]->departure_time->day;
            cout << "Enter hour: ";
            cin >> flights[i]->departure_time->hour;
            cout << "Enter minute: ";
            cin >> flights[i]->departure_time->minus;
            return;
        }
    }
}
void deleteFlight()
{
    displayFlight();
    string flightNumber;
    cout << "Enter flight number: ";
    cin >> flightNumber;
    for (int i = 0; i < numFlights; i++)
    {
        if (flights[i]->flight_number == flightNumber)
        {
            delete flights[i];
            for (int j = i; j < numFlights - 1; j++)
            {
                flights[j] = flights[j + 1];
            }
            numFlights--;
            return;
        }
    }
    cout << "Flight not found" << endl;
}
void displayFlight()
{
    cout << "Flight list: " << endl;
    cout << left << setw(flightsIdWidth) << "Flight id" << setw(flightsDepartureTimeWidth) << "Departure time" << setw(flightsArrivalAirportWidth) << "Arrival" << setw(flightsPlaneIdWidth) << "Plane id" << endl;
    for (int i = 0; i < numFlights; i++)
    {
        cout << left << setw(flightsIdWidth) << flights[i]->flight_number << setw(flightsDepartureTimeWidth) << flights[i]->departure_time->toString() << setw(flightsArrivalAirportWidth) << flights[i]->arrivalAirport << setw(flightsPlaneIdWidth) << flights[i]->plane->id << endl;
    }
}
void saveToFileFlight()
{
    ofstream fout;
    fout.open("flight.txt");
    for (int i = 0; i < numFlights - 1; i++)
    {
        fout << flights[i]->flight_number << endl;
        fout << flights[i]->departure_time->year << endl;
        fout << flights[i]->departure_time->month << endl;
        fout << flights[i]->departure_time->day << endl;
        fout << flights[i]->departure_time->hour << endl;
        fout << flights[i]->departure_time->minus << endl;
        fout << flights[i]->arrivalAirport << endl;
        fout << flights[i]->plane->id << endl;
    }
    // save last flight
    fout << flights[numFlights - 1]->flight_number << endl;
    fout << flights[numFlights - 1]->departure_time->year << endl;
    fout << flights[numFlights - 1]->departure_time->month << endl;
    fout << flights[numFlights - 1]->departure_time->day << endl;
    fout << flights[numFlights - 1]->departure_time->hour << endl;
    fout << flights[numFlights - 1]->departure_time->minus << endl;
    fout << flights[numFlights - 1]->arrivalAirport << endl;
    fout << flights[numFlights - 1]->plane->id;
    fout.close();
}
void loadFromFileFlight()
{
    ifstream fin("flight.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            Flight *f = new Flight();
            f->departure_time = new DateTime();
            string planeId;
            fin >> f->flight_number;
            fin >> f->departure_time->year;
            fin >> f->departure_time->month;
            fin >> f->departure_time->day;
            fin >> f->departure_time->hour;
            fin >> f->departure_time->minus;
            fin >> f->arrivalAirport;
            fin >> planeId;
            for (int i = 0; i < numPlanes; i++)
            {
                if (planes[i]->id == planeId)
                {
                    f->plane = planes[i];
                    planes[i]->flights[planes[i]->numFlights] = f;
                    planes[i]->numFlights++;
                    break;
                }
            }
            flights[numFlights] = f;
            numFlights++;
        }
        fin.close();
    }
}

void addPassenger()
{
    string id;
    string firstname;
    string lastname;
    string gender;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter firstname: ";
    cin >> firstname;
    cout << "Enter lastname: ";
    cin >> lastname;
    cout << "Enter gender: ";
    cin >> gender;

    Passenger *pas = new Passenger(id, firstname, lastname, gender);
    passengerInfoTree.add(pas);
}
void displayPassenger()
{
    passengerInfoTree.display();
}
void saveToFilePassenger()
{
    passengerInfoTree.save("passenger.txt");
}
void loadFromFilePassenger()
{
    // load passenger
    ifstream fin("passenger.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            string id;
            string firstname;
            string lastname;
            string gender;

            getline(fin, id);
            if (id == "")
                return;
            getline(fin, firstname);
            getline(fin, lastname);
            getline(fin, gender);

            Passenger *pas = new Passenger(id, firstname, lastname, gender);
            passengerInfoTree.add(pas);
        }
        fin.close();
    }
}
void deletePassenger()
{
    string id;
    cout << "Enter id: ";
    cin >> id;
    passengerInfoTree.removeById(id);
}
void modifyPassenger()
{
    string id;
    cout << "Enter id: ";
    cin >> id;
    Passenger *pas = passengerInfoTree.find(id);
    if (pas == NULL)
    {
        cout << "Passenger not found" << endl;
        return;
    }
    cout << "Enter new firstname: ";
    cin >> pas->firstName;
    cout << "Enter new lastname: ";
    cin >> pas->lastName;
    cout << "Enter new gender: ";
    cin >> pas->gender;
}

void addTicket()
{
    cout << "passengerId: ";
    string pasId;
    cin >> pasId;
    Passenger *pas = passengerInfoTree.find(pasId);
    if (pas == NULL)
    {
        string firstname;
        string lastname;
        string gender;
        cout << "Enter firstname: ";
        cin >> firstname;
        cout << "Enter lastname: ";
        cin >> lastname;
        cout << "Enter gender: ";
        cin >> gender;

        pas = new Passenger(pasId, firstname, lastname, gender);
        passengerInfoTree.add(pas);
    }
    cout << "flightNumber:";
    string flightNumber;
    cin >> flightNumber;
    Flight *flight = findFlight(flightNumber);
    if (flight == NULL)
    {
        cout << "Flight not found" << endl;
        return;
    }

    int seatNumber;

    while (true)
    {
        cout << "seatNumber:";
        cin >> seatNumber;
        if (seatNumber < 0 || seatNumber > flight->plane->capacity)
        {
            cout << "Invalid seat number" << endl;
            continue;
        }
        if (flight->tickets[seatNumber] != NULL)
        {
            cout << "Seat is not empty" << endl;
            continue;
        }
        break;
    }

    Ticket *ticket = new Ticket(seatNumber, pas, flight);

    tickets[numTickets] = ticket;
    numTickets++;

    flight->tickets[seatNumber] = ticket;

    pas->tickets[pas->numTickets] = ticket;
    pas->numTickets++;
}
void deleteTicket()
{
    cout << "Input passengerId: ";
    string pasId;
    cin >> pasId;
    Passenger *pas = passengerInfoTree.find(pasId);
    if (pas == NULL)
    {
        cout << "Passenger not found" << endl;
        return;
    }
    cout << "List ticket: " << endl;
    for (int i = 0; i < pas->numTickets; i++)
    {
        cout << pas->tickets[i]->flight->flight_number << " " << pas->tickets[i]->id << endl;
    }
    cout << "Input ticketId: ";
    int ticketId;
    cin >> ticketId;
    for (int i = 0; i < pas->numTickets; i++)
    {
        if (pas->tickets[i]->id == ticketId)
        {
            pas->tickets[i]->flight->tickets[pas->tickets[i]->id] = NULL;
            // delete pas->tickets[i];
            delete pas->tickets[i];
            pas->tickets[i] = NULL;

            pas->tickets[i] = pas->tickets[pas->numTickets - 1];
            pas->tickets[pas->numTickets - 1] = NULL;
            pas->numTickets--;
            break;
        }
    }
}
void displayTicket()
{
    cout << "Input passengerId: ";
    string pasId;
    cin >> pasId;
    Passenger *pas = passengerInfoTree.find(pasId);
    if (pas == NULL)
    {
        cout << "Passenger not found" << endl;
        return;
    }
    cout << "List ticket: " << endl;
    for (int i = 0; i < pas->numTickets; i++)
    {
        cout << pas->tickets[i]->flight->flight_number << " " << pas->tickets[i]->id << endl;
    }
}
void modifyTicket()
{
    cout << "Input passengerId: ";
    string pasId;
    cin >> pasId;
    Passenger *pas = passengerInfoTree.find(pasId);
    if (pas == NULL)
    {
        cout << "Passenger not found" << endl;
        return;
    }
    cout << "List ticket: " << endl;
    for (int i = 0; i < pas->numTickets; i++)
    {
        cout << pas->tickets[i]->flight->flight_number << " " << pas->tickets[i]->id << endl;
    }
    cout << "Input ticketId: ";
    int ticketId;
    cin >> ticketId;
    for (int i = 0; i < pas->numTickets; i++)
    {
        if (pas->tickets[i]->id == ticketId)
        {
            cout << "Enter new seatNumber: ";
            int seatNumber;
            cin >> seatNumber;
            pas->tickets[i]->id = seatNumber;
            break;
        }
    }
}
void saveToFileTicket()
{
    ofstream fout("ticket.txt");
    if (fout.is_open())
    {
        for (int i = 0; i < numTickets; i++)
        {
            fout << tickets[i]->id << endl;
            // fout << tickets[i]->seatNumber << endl;
            fout << tickets[i]->passenger->id << endl;
            fout << tickets[i]->flight->flight_number << endl;
        }
        fout.close();
    }
}
void loadFromFileTicket()
{
    ifstream fin("ticket.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            int id;
            fin >> id;
            // int seatNumber;
            // fin >> seatNumber;
            string pasId;
            fin >> pasId;
            string flightNumber;
            fin >> flightNumber;
            Passenger *pas = passengerInfoTree.find(pasId);
            if (pas == NULL)
            {
                cout << "Passenger not found" << endl;
                return;
            }
            Flight *flight = findFlight(flightNumber);
            if (flight == NULL)
            {
                cout << "Flight not found" << endl;
                return;
            }
            Ticket *ticket = new Ticket(id, pas, flight);
            tickets[numTickets] = ticket;
            numTickets++;

            flight->tickets[id] = ticket;

            pas->tickets[pas->numTickets] = ticket;
            pas->numTickets++;
        }
        fin.close();
    }
}

Flight *findFlight(string flightNumber)
{
    for (int i = 0; i < numFlights; i++)
    {
        if (flights[i]->flight_number == flightNumber)
        {
            return flights[i];
        }
    }
    return NULL;
}
Plane *findPlane(string id)
{
    for (int i = 0; i < numPlanes; i++)
    {
        if (planes[i]->id == id)
        {
            return planes[i];
        }
    }
    return NULL;
}