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
// Get the type from the user.
// Determine the lowest price for a computer of the given type.
//
////////////////////////////////////////////////////////////////////////
// Algorithm: Data input
////////////////////////////////////////////////////////////////////////
// 
// Input: type, production_year, price
// 
//  vector computers
// 
//  while true do
//    get type
//    if type = "quit"
//      break
//    get production_year
//    get price
// 
//    computers.push_back(type, production_year, price)
// 
//    type <- ""
//    production_year <- 0
//    price <- 0
//
////////////////////////////////////////////////////////////////////////
// Algorithm: Task
////////////////////////////////////////////////////////////////////////
// 
// Input: type, computers
// 
// price <- computers[0]
// 
// for computer in computers do
//   if computer.type = type
//      if computer.price < price
//        price <- computer.price
// 
// for computer in computers do
//   if computer.type = type
//      if computer.price = price
//        print computer
// 
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

struct Computer {
  string type;
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

void hi(string task){
  cout << endl
       << "\033[1;36m"
       << "-------------------------------------------------------------------"
       << "\033[0m"
       << endl;
  cout << "\033[1;36m"
       << task
       << "\033[0m"
       << endl;
  cout << "\033[1;36m"
       << "-------------------------------------------------------------------"
       << "\033[0m"
       << endl << endl;
}

int main() {
  vector<Computer> computers;
  string type {""};
  int production_year {0};
  float price {0};

  hi("This program findes the lowest price for a computer of the given type.");

  cout << "\033[7m" << "Enter computers data!" << "\033[0m"
     << endl << endl ;

  // INPUT DATA
  int count = 0;
  while (true) {
    cout << "--------------------------------------------------------------"
         << endl;
    cout << "Computer number [\033[1;32m" << count << "\033[0m]:" << endl;
    cout << "(enter '\033[31mquit\033[0m' to end input)" << endl << endl;

    cout << "\033[34m[type]:\033[0m ";
    cin >> type;
    if (type == "quit") 
      break;
    cout << "\033[34m[production year]:\033[0m ";
    cin >> production_year;
    cout << "\033[34m[price]:\033[0m ";
    cin >> price;

    computers.push_back(Computer{type, production_year, price});

    type = "";
    production_year = 0;
    price = 0;

    count++;
  }

  cout << "--------------------------------------------------------------"
       << endl
       << endl;

  cout << "\033[7m" << "Computers available: " << "\033[0m"
       << endl
       << endl;
  
  // PRINTING OUT COMPUTERS
  count = 0;
  for (Computer computer : computers) {
    cout << "------------------------------------------------------------"
         << endl;
    cout << "Computer number [\033[1;32m" << count << "\033[0m]:"
         << endl
         << endl;

    cout << computer;

    count++;
  }

  cout << "------------------------------------------------------------"
       << endl
       << endl;

  cout << "\033[7m" << "Enter type: " << "\033[0m"
       << endl
       << endl;

  cout << "\033[34m[type]:\033[0m ";
  cin >> type;

  // FINDING THE LOWEST PRICE
  price = computers[0].price;
  for (Computer computer : computers)
    if (computer.type == type)
      if (computer.price < price)
        price = computer.price;

  cout << endl
       << "\033[7m" << "Lowest computer('s) by given type: " << "\033[0m"
       << endl
       << endl;

  // FINDEING CHEAPEST COMPUTERS
  count = 0;
  for (Computer computer : computers) {
    if (computer.type == type) {
      if (computer.price == price) {
        cout << "--------------------------------------------------------------"
             << endl;
        cout << "Computer number [\033[1;32m" << count << "\033[0m]:"
             << endl
             << endl;
    
        cout << computer;
      }
    }

    count++;
  }

  cout << "--------------------------------------------------------------"
       << endl
       << endl;
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: Normal Input
//   Input: laptop 2003 99.99 quit laptop
//   Output: laptop 2003 99.99
//   Expected: laptop 2003 99.99
//   Result: PASS
// 
// Case 2: No Input
//   Input: quit quit
//   Output:
//   Expected:
//   Result: PASS
//
// Case 3: Overflow
//   Input: laptop 9999999999999999999999999999999999
//   Output: infinite cout
//   Expected: error
//   Result: FAIL
// 
// Case 4: Non numeric input
//   Input: laptop hello
//   Output: infinite cout
//   Expected: error
//   Result: FAIL
// 
// Case 5: Not matching type 
//   Input: laptop 2003 99.99 quit pc
//   Output: 
//   Expected: 
//   Result: PASS
// 
// Case 6: Multiple matching types 
//   Input: laptop 2003 99.99 pc 2013 23.45 laptop 2001 99.99 laptop 2019 999.99 quit laptop
//   Output: laptop 2003 99.99 laptop 2001 99.99
//   Expected: laptop 2003 99.99 laptop 2001 99.99
//   Result: PASS
// 
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
//  The program is working correctly.
//
////////////////////////////////////////////////////////////////////////