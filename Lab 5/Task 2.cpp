////////////////////////////////////////////////////////////////////////
// L5: User-defined types and file streams
////////////////////////////////////////////////////////////////////////
//
// Andrey Perunov
// st81049
// Variation 5
//
////////////////////////////////////////////////////////////////////////
// Task formulation
////////////////////////////////////////////////////////////////////////
//
// Declare a structure Computer with data members type, production year, price.
// 
// Design a menu with items for adding objects, printing a list of objects,
// performing a task: 
// [Get the type from the user.
// Determine the lowest price for a computer of the given type.]
// , reading data in, writing data out and quitting.
//
////////////////////////////////////////////////////////////////////////
// Algorithm: Data input
////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: Task
////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

const string FILENAME = "computers.txt";

struct Computer {
    char type[100];
    int production_year;
    float price;
};

ostream& operator << (ostream& os, Computer c) {
    return os << "\033[34m[type]:\033[0m "
        << c.type << endl
        << "\033[34m[production year]:\033[0m "
        << c.production_year << endl
        << "\033[34m[price]:\033[0m "
        << c.price << endl;
};

string colored(string text, string color) {
    if (color == "black") return "\033[1;30m" + text + "\033[0m";
    if (color == "red") return "\033[1;31m" + text + "\033[0m";
    if (color == "green") return "\033[1;32m" + text + "\033[0m";
    if (color == "yellow") return "\033[1;33m" + text + "\033[0m";
    if (color == "blue") return "\033[1;34m" + text + "\033[0m";
    if (color == "magenta") return "\033[1;35m" + text + "\033[0m";
    if (color == "cyan") return "\033[1;36m" + text + "\033[0m";
    if (color == "white") return "\033[1;37m" + text + "\033[0m";
    return "Invalid color name!";
}

void hi(string task) {
    cout << endl
        << "\033[1;36m"
        << "-------------------------------------------------------------------"
        << endl;
    cout << task
        << endl;
    cout << "-------------------------------------------------------------------"
        << "\033[0m"
        << endl << endl;
}

void printMenu() {
    cout << "+---+------------------------------------------+" << endl
        << "| " << colored("A", "green") << " | "
        << colored("Add new COMPUTER", "green") << "                         |" << endl
        << "+---+------------------------------------------+" << endl
        << "| " << colored("P", "yellow") << " | "
        << colored("Print all COMPUTER", "yellow") << "                       |" << endl
        << "+---+------------------------------------------+" << endl
        << "| " << colored("O", "blue") << " | "
        << colored("Find the cheapest COMPUTER by given type", "blue")
        << " |" << endl
        << "+---+------------------------------------------+" << endl
        << "| " << colored("W", "magenta") << " | "
        << colored("Write data out", "magenta") << "                           |" << endl
        << "+---+------------------------------------------+" << endl
        << "| " << colored("R", "cyan") << " | "
        << colored("Read data in", "cyan") << "                             |" << endl
        << "+---+------------------------------------------+" << endl
        << "| " << colored("Q", "red") << " | "
        << colored("Quit", "red") << "                                     |" << endl
        << "+---+------------------------------------------+" << endl << endl;
}

void addNewComputer(vector<Computer>& computers) {
    Computer computer;

    cout << "+---+----------------------------+" << endl
        << "| " << colored("A", "green") << " | "
        << colored("Add new COMPUTER", "green") << "           |" << endl
        << "+---+----------------------------+" << endl;
    cout << colored("Please don't use spaces!", "yellow") << endl;
    cout << "--------------------------------------------------------------"
        << endl;

    cout << "\033[34m[type]:\033[0m ";
    cin >> computer.type;
    cout << "\033[34m[production year]:\033[0m ";
    cin >> computer.production_year;
    cout << "\033[34m[price]:\033[0m ";
    cin >> computer.price;

    computers.push_back(computer);

    cout << "--------------------------------------------------------------"
        << endl;
    cout << "+---+----------------------------+" << endl
        << colored("Computer " + string{ computer.type } + " was added.", "green")
        << endl
        << "+---+----------------------------+" << endl << endl;
}

void printAllComputers(vector<Computer> computers) {
    int count = 0;

    cout << "+---+----------------------------+" << endl
        << "| " << colored("P", "yellow") << " | "
        << colored("Print all COMPUTER", "yellow") << "         |" << endl
        << "+---+----------------------------+" << endl;

    if (computers.size() == 0) {
        cout << colored("There is no computers!", "red") << endl << endl;
        return;
    }

    for (Computer computer : computers) {
        cout << "------------------------------------------------------------"
            << endl;
        cout << "Computer number [" << colored(to_string(count), "green") << "]:"
            << endl
            << endl;

        cout << computer;

        count++;
    }
    cout << "------------------------------------------------------------"
        << endl;
    cout << "+---+----------------------------+" << endl
        << colored(to_string(count) + " computers were printed.", "yellow")
        << endl
        << "+---+----------------------------+" << endl << endl;
}

bool computerWithTypeExists(vector<Computer> computers, char type[100]) {
    for (Computer computer : computers) {
        if (strcmp(computer.type, type) == 0) {
            return true;
        }
    }
    return false;
}

void findCheapestComputersByType(vector<Computer> computers, char type[100]) {
    cout << "+---+------------------------------------------+" << endl
        << "| " << colored("O", "blue") << " | "
        << colored("Find the cheapest COMPUTER by given type", "blue")
        << " |" << endl
        << "+---+------------------------------------------+" << endl;
    cout << colored("[type]: ", "blue");
    cin >> type;
    cout << "----------------------------------------------------------"
        << endl;

    if (computers.size() == 0) {
        cout << colored("There is no computers!", "red") << endl << endl;
        return;
    }

    if (!computerWithTypeExists(computers, type)) {
        cout << colored("There is no computers by given type!", "red")
            << endl << endl;
        return;
    }

    float price = computers[0].price;
    for (Computer computer : computers)
        if (strcmp(computer.type, type) == 0)
            if (computer.price < price)
                price = computer.price;

    int count = 0;
    for (Computer computer : computers) {
        if (strcmp(computer.type, type) == 0) {
            if (computer.price == price) {
                cout << "Computer number [\033[1;32m" << count << "\033[0m]:"
                    << endl
                    << endl;
                cout << computer;
                cout << "----------------------------------------------------------"
                    << endl;
            }
        }
        count++;
    }
    cout << endl;
}

void writeDataOut(vector<Computer> computers, string filename) {
    cout << "+---+------------------------------------------+" << endl
        << "| " << colored("W", "magenta") << " | "
        << colored("Write data out", "magenta") << "                           |" << endl
        << "+---+------------------------------------------+" << endl;

    ofstream file(filename);
    if (!file.is_open()) {
        cout << colored(("Error opening file " + filename + "!"), "red") << endl;
        return;
    }

    for (Computer computer : computers) {
        file << computer.type << " "
            << computer.production_year << " "
            << computer.price << endl;
    }

    cout << "+---+----------------------------+" << endl
        << colored(to_string(computers.size()) + " computers were writed.", "magenta")
        << endl
        << "+---+----------------------------+" << endl << endl;


    file.close();
}

void readDataIn(vector<Computer>& computers, string filename) {
    cout << "+---+------------------------------------------+" << endl
        << "| " << colored("R", "cyan") << " | "
        << colored("Read data in", "cyan") << "                             |" << endl
        << "+---+------------------------------------------+" << endl;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << colored(("Error opening file " + filename + "!"), "red") << endl;
        return;
    }

    Computer computer;
    computers.clear();
    while (file >> computer.type
        >> computer.production_year
        >> computer.price) {
        computers.push_back(computer);
    }
    if (computers.size() == 0)
        cout << colored(("File " + filename + " is empty!"), "red") << endl << endl;

    cout << "+---+----------------------------+" << endl
        << colored(to_string(computers.size()) + " computers were readed.", "cyan")
        << endl
        << "+---+----------------------------+" << endl << endl;

    file.close();
}

int main() {
    vector<Computer> computers;
    bool isSaved = true;
    char type[100];
    char choice;

    hi("Welcome to COMPUTERS database.");

    do
    {
        printMenu();
        cout << "What woud you like to do?" << endl;
        cin >> choice;
        cout << endl;


        if (choice == 'q')
            break;

        switch (choice)
        {
        case 'A':
        case 'a':
            addNewComputer(computers);
            isSaved = false;
            break;
        case 'p':
        case 'P':
            printAllComputers(computers);
            break;
        case 'O':
        case 'o':
            findCheapestComputersByType(computers, type);
            break;
        case 'W':
        case 'w':
            writeDataOut(computers, "computers.txt");
            isSaved = true;
            break;
        case 'R':
        case 'r':
            if (!isSaved) {
                cout << colored("You did not write data out!", "red") << endl;
                cout << "If you read data in, computers that you have added will be "
                    << colored("deleted", "red") << "!" << endl;
                cout << "Do you want cancel this action? (y - yes, n - no)" << endl;
                cin >> choice;
                if (choice == 'y') {
                    cout << endl;
                    break;
                }
                if (choice == 'n') {
                    cout << endl;
                    readDataIn(computers, FILENAME);
                    isSaved = true;
                }
                else {
                    cout << colored("Wrong input!", "red") << endl;
                    cout << "Action was canceled!" << endl;
                    cout << endl;
                    break;
                }
            }
            else {
                readDataIn(computers, FILENAME);
                isSaved = true;
            }
            break;
        default:
            cout << colored("Unknown command!", "red") << endl << endl;
            break;
        }
    } while (choice != 'q' || choice != 'Q');
    return 0;
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//?
//? Case 1: Normal Input
//?   Input: laptop 2003 99.99 quit laptop
//?   Output: laptop 2003 99.99
//?   Expected: laptop 2003 99.99
//?   Result: PASS
//? 
//? Case 2: No Input
//?   Input: quit quit
//?   Output:
//?   Expected:
//?   Result: PASS
//?
//? Case 3: Overflow
//?   Input: laptop 9999999999999999999999999999999999
//?   Output: infinite cout
//?   Expected: error
//?   Result: FAIL
//? 
//? Case 4: Non numeric input
//?   Input: laptop hello
//?   Output: infinite cout
//?   Expected: error
//?   Result: FAIL
//? 
//? Case 5: Not matching type 
//?   Input: laptop 2003 99.99 quit pc
//?   Output: 
//?   Expected: 
//?   Result: PASS
//? 
//? Case 6: Multiple matching types 
//?   Input: laptop 2003 99.99 pc 2013 23.45 laptop 2001 99.99 laptop 2019 999.99 quit laptop
//?   Output: laptop 2003 99.99 laptop 2001 99.99
//?   Expected: laptop 2003 99.99 laptop 2001 99.99
//?   Result: PASS
//? 
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
//  The program is working correctly.
//
////////////////////////////////////////////////////////////////////////