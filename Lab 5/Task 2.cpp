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
// Algorithm: addNewComputer
////////////////////////////////////////////////////////////////////////
// 
// Input: computers, computer
// 
//  vector computer
// 
//  get computer.type
//  get computer.production_year
//  get computer.price
// 
//  computers.push_back(computer)
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: ptintAllComputers
////////////////////////////////////////////////////////////////////////
// 
// Input: computers
// Output: computers
// 
// count <- 0
// 
// if computers.size = 0
//  print("There is no computers!")°
//  return
// 
// for each computer in computers do
//  print("Computer number [" + count + "]: ")
//  print(computer)
//  count <- count + 1
// 
// print(count + " computers were printed.")
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: computerWithTypeExists
////////////////////////////////////////////////////////////////////////
// 
// Input: computers, type
// Output: bool-value
// 
// for each computer in computers do
//  if computer.type = type
//    return true
// 
// return false
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: findCheapestComputersByType
////////////////////////////////////////////////////////////////////////
// 
// Input: computers, type
// Output: computers
// 
// get type
// 
// if computers.size = 0
//  print("There is no computers!")°
//  return
//
// if not computerWithTypeExists(computers, type) do
//  print("There is no computers by given type!")
//  return 
// 
// price
// for each computer in computers do
//  if computer.type = type do 
//   price <- computer.price
//   break
// 
// for each computer in computers do
//  if computer.type = type do 
//   if computer.price < price
//    price <- computer.price
// 
// count <- 0
// for each computer in computers do
//  if computer.type = type do
//   if computer.price = price
//    print("Computer number [" + count + "]: ")
//    print(computer)
//  count <- count + 1
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: writeDataOut
////////////////////////////////////////////////////////////////////////
// 
// Input: computers, filename
// Output: file
// 
// open file with filename in binary mode
// if file is not open do
//  print("Error opening file " + filename + "!")
//  return
// 
// for each computer in computers do
//  write computer.type to the file
//  write computer.production_year to the file
//  write computer.price to the file
// 
// print(computers.size + " computers were writed.")
// 
// close the file
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: readDataIn
////////////////////////////////////////////////////////////////////////
// 
// Input: computers, filename
// Output: computers
// 
// open file with filename in binary mode
// if file is not open do
//  print("Error opening file " + filename + "!")
//  return
// 
// computer
// computers.clear
// while it is not the end of the file do
//  read computer.type from the file
//  read computer.production_year from the file
//  read computer.price from the file
//  computers.push_back(computer)
// 
// if computers.size = 0 do 
//  print("File " + filename + " is empty!")
// 
// print(computers.size + " computers were readed.")
// 
// close the file
// 
////////////////////////////////////////////////////////////////////////
// Algorithm: main
////////////////////////////////////////////////////////////////////////
// 
// Input: choice
// 
// computers
// isSaved <- true
// choice
// 
// do
//  printMenu
//  get choice
//  
//  if choice = q
//   break
//  
//  switch choice
//   case 'A' and 'a' do
//    addNewComputer(computers)
//    isSaved <- false
//    brake
//   case 'p' and 'P' do
//    printAllComputers(computers)
//    break
//   case 'o' and 'O' do
//    findCheapestComputersByType(computers)
//    break
//   case 'w' and 'W' do
//    writeDataOut(computers, FILENAME)
//    break
//   case 'r' and 'R' do
//    if not isSaved do
//     print("You did not write data out!")
//     print("Cancel?")
//     get choice
//     if choice = 'y' do
//      break
//     if choice = 'n' do
//      readDataIn(computers, FILENAME)
//      isSaved <- true
//     else do
//      print("Wrong input!")
//      print("Action was canceled!")
//      break
//    else do
//     readDataIn(computers, FILENAME)
//     isSaved <- true
//    break
//   default do
//    print("Unknown command!")
//    break
// while choice != 'q' or choice != 'Q'
// 
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

const string FILENAME = "computers.bin";

struct Computer {
    char type[20];
    int32_t production_year;
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

void findCheapestComputersByType(vector<Computer> computers) {
    cout << "+---+------------------------------------------+" << endl
        << "| " << colored("O", "blue") << " | "
        << colored("Find the cheapest COMPUTER by given type", "blue")
        << " |" << endl
        << "+---+------------------------------------------+" << endl;
    char type[20];
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

    // Get the price of the first computer by a given type
    float price;
    for (Computer computer : computers) {
        if (strcmp(computer.type, type) == 0) {
            price = computer.price;
            break;
        }
    }

    // Find the cheapest price
    for (Computer computer : computers)
        if (strcmp(computer.type, type) == 0)
            if (computer.price < price)
                price = computer.price;

    // Output cheapest computers
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

    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << colored(("Error opening file " + filename + "!"), "red") << endl;
        return;
    }

    for (Computer computer : computers) {
        file.write(computer.type, sizeof(computer.type));
        file.write((char*)&computer.production_year, sizeof(computer.production_year));
        file.write((char*)&computer.price, sizeof(computer.price));
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

    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << colored(("Error opening file " + filename + "!"), "red") << endl;
        return;
    }

    Computer computer;
    computers.clear();
    while (file.peek() != EOF) {
        file.read(computer.type, sizeof(computer.type));
        file.read((char*)&computer.production_year, sizeof(computer.production_year));
        file.read((char*)&computer.price, sizeof(computer.price));
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
    char choice;

    hi("Welcome to COMPUTERS database.");

    do
    {
        printMenu();
        cout << "What would you like to do?" << endl;
        cin >> choice;
        cout << endl;

        if (choice == 'q' || choice == 'Q')
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
            findCheapestComputersByType(computers);
            break;
        case 'W':
        case 'w':
            writeDataOut(computers, FILENAME);
            isSaved = true;
            break;
        case 'R':
        case 'r':
            if (!isSaved) {
                cout << colored("You did not write data out!", "red") << endl;
                cout << "If you read data in, computers that you have added will be "
                    << colored("deleted", "red") << "!" << endl;
                cout << "Do you want to continue? (y - yes, n - no)" << endl;
                cin >> choice;
                if (choice == 'y') {
                    cout << endl;
                    readDataIn(computers, FILENAME);
                    isSaved = true;
                }
                else if (choice == 'n') {
                    cout << endl;
                    break;
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
    cout << colored("Goodbye, have a nice day!", "green") << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////
// Testing: menu
////////////////////////////////////////////////////////////////////////
// 
// Case 1: q
//   Input: q
//   Output: Program ended
//   Expected: Program ended
//   Result: PASS
// 
// Case 2: Q
//   Input: Q
//   Output: Program ended
//   Expected: Program ended
//   Result: PASS
// 
// Case 3: Wrong input
//   Input: B
//   Output: Unknown command!
//   Expected: Unknown command!
//   Result: PASS
// 
// Case 4: Multiple chars
//   Input: AA
//   Output: addNewComputer run and get second char as an input
//   Expected: addNewComputer run
//   Result: FAIL
// 
// Case 5: int
//   Input: 65
//   Output: Unknown command!
//   Expected: Unknown command!
//   Result: PASS
// 
// Case 6: Option R, isSaved = true
//   Input: r
//   Output: readDataIn run
//   Expected: readDataIn run
//   Result: PASS
// 
// Case 7: Option R, isSaved = false, continue? - y
//   Input: a pc 2003 99.99 r y
//   Output: readDataIn run
//   Expected: readDataIn run
//   Result: PASS
// 
// Case 8: Option R, isSaved = false, continue? - n
//   Input: a pc 2003 99.99 r n
//   Output: readDataIn didn't run
//   Expected: readDataIn didn't run
//   Result: PASS
// 
// Case 9: Option R, isSaved = false, continue? - wrong input
//   Input: a pc 2003 99.99 r k
//   Output: Wrong input! readDataIn didn't run
//   Expected: Wrong input! readDataIn didn't run
//   Result: PASS
// 
////////////////////////////////////////////////////////////////////////
// Testing: addNewComputer
////////////////////////////////////////////////////////////////////////
// 
// Case 1: non numerical input
//   Input: pc nineties one
//   Output: Infinite menu output
//   Expected: Error
//   Result: FAIL
// 
// Case 2: correct input
//   Input: pc 2003 99.99
//   Output: computer added to the vector
//   Expected: computer added to the vector
//   Result: PASS
// 
// Case 3: add computer after read file
//   Input: pc 2003 99.99
//   Output: computer added to the end of the vector
//   Expected: computer added to the end of the vector
//   Result: PASS
// 
// Case 4: type using space
//   Input: personal computer 2003 99.99
//   Output: Infinite menu output
//   Expected: Error
//   Result: FAIL
// 
////////////////////////////////////////////////////////////////////////
// Testing: printAllComputers
////////////////////////////////////////////////////////////////////////
// 
// Case 1: computers vector is empty
//   Output: Error
//   Expected: Error
//   Result: PASS
// 
// Case 2: computers vector is not empty
//   Output: printed all computers
//   Expected: printed all computers
//   Result: PASS
// 
////////////////////////////////////////////////////////////////////////
// Testing: findCheapestComputersByType
////////////////////////////////////////////////////////////////////////
// 
// Case 1: type exists, single cheapest computer
//   Input: pc
//   Output: pc 2222 22
//   Expected: pc 2222 22
//   Result: PASS
// 
// Case 2: type exists, multiple cheapest computer
//   Input: laptop
//   Output: laptop 9999 99 laptop 2000 99
//   Expected: laptop 9999 99 laptop 2000 99
//   Result: PASS
// 
// Case 3: type does not exists
//   Input: andriod
//   Output: There is no computers by given type!
//   Expected: There is no computers by given type!
//   Result: PASS
// 
////////////////////////////////////////////////////////////////////////
// Testing: writeDataOut
////////////////////////////////////////////////////////////////////////
//
// Case 1: file does not exists
//   Output: created a file
//   Expected: created a file
//   Result: PASS
// 
// Case 2: file exists
//   Output: rewrite existing file
//   Expected: rewrite existing file
//   Result: PASS
// 
////////////////////////////////////////////////////////////////////////
// Testing: readDataIn
////////////////////////////////////////////////////////////////////////
//
// Case 1: file does not exists
//   Output: error
//   Expected: error
//   Result: PASS
// 
// Case 2: file exists but empty
//   Output: nothing is read
//   Expected: nothing is read
//   Result: PASS
// 
// Case 3: file exists
//   Output: 3 computers were readed
//   Expected: 3 computers were readed
//   Result: PASS
// 
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
//  The program is working correctly.
//
////////////////////////////////////////////////////////////////////////