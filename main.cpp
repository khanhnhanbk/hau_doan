// library
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

// constants

const int MAX_SIZE = 100;

// struct
struct Plane;
struct Flight;
struct Ticket;
struct Passenger;
struct DateTime;

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

struct FLight
{
    string id;
    string arrivalAirport;
    Plane *plane;
    DateTime *departureTime;

    Ticket *tickets[MAX_SIZE];
    int numTickets;
};

struct Ticket
{
    string id;
    Passenger *passenger;
    Flight *flight;
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
            cout << current->passenger->id << " ";
            displayRec(current->right);
        }
    }
    void display()
    {
        displayRec(root);
    }

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

Plane *planes[MAX_SIZE];
int numPlanes;

Flight *flights[MAX_SIZE];
int numFlights;

struct myBST passengerInfoTree;

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

// function for menu
void showMainMenu();
void showPlaneMenu();
void showFlightMenu();
void showPassengerMenu();
void showTicketMenu();

// body
int main()
{
    // initialize
    numPlanes = 0;
    loadFromFilePlane();
    numFlights = 0;

    passengerInfoTree.root = NULL;
    loadFromFilePassenger();
    // menu
    showMainMenu();
    return 0;
}
// function for menu
void showPlaneMenu()
{
    int choice;
    do
    {
        cout << "1. Add Plane" << endl;
        cout << "2. Delete Plane" << endl;
        cout << "3. Modify Plane" << endl;
        cout << "4. Display Plane" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "7. Back" << endl;
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
        case 5:
            saveToFilePlane();
            break;
        case 6:
            loadFromFilePlane();
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 7);
}
void showFlightMenu(){};
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
}
void showMainMenu()
{
    int choice;
    do
    {
        cout << "1. Plane" << endl;
        cout << "2. Flight" << endl;
        cout << "3. Passenger" << endl;
        cout << "4. Ticket" << endl;
        cout << "5. Exit" << endl;
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
        case 5:
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
    cout << "Enter plane type: ";
    cin >> type;
    cout << "Enter plane capacity: ";
    cin >> capacity;
    planes[numPlanes] = new Plane(id, type, capacity);
    numPlanes++;
}
void displayPlane()
{
    cout << "Plane list: " << endl;
    cout << "ID\tType\tCapacity" << endl;
    for (int i = 0; i < numPlanes; i++)
    {
        cout << planes[i]->id << "\t" << planes[i]->type << "\t" << planes[i]->capacity << endl;
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
    for (int i = 0; i < numPlanes; i++)
    {
        if (planes[i]->id == id)
        {
            cout << "Enter new plane type: ";
            cin >> type;
            cout << "Enter new plane capacity: ";
            cin >> capacity;
            planes[i]->type = type;
            planes[i]->capacity = capacity;
            return;
        }
    }
    cout << "Plane not found" << endl;
}

void addFlight()
{
}

void addPassenger()
{
    string id;
    string firstname;
    string lastname;
    string gender;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter firstname";
    cin >> firstname;
    cout << "Enter lastname";
    cin >> lastname;
    cout << "Enter gender";
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
}
void loadFromFilePassenger()
{
}
void deletePassenger()
{
}
void modifyPassenger()
{
}