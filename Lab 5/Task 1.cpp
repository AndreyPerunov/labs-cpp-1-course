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

    if (type != "quit") 
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
  
  count = 0;
  for (Computer computer : computers) {
    cout << "--------------------------------------------------------------"
         << endl;
    cout << "Computer number [\033[1;32m" << count << "\033[0m]:"
         << endl
         << endl;

    cout << computer;

    count++;
  }

  cout << "--------------------------------------------------------------"
       << endl
       << endl;

  cout << "\033[7m" << "Enter type: " << "\033[0m"
       << endl
       << endl;

  cout << "\033[34m[type]:\033[0m ";
  cin >> type;

  price = computers[0].price;
  for (Computer computer : computers)
    if (computer.type == type)
      if (computer.price < price)
        price = computer.price;

  cout << endl
       << "\033[7m" << "Lowest computer('s) by given type: " << "\033[0m"
       << endl
       << endl;

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