////////////////////////////////////////////////////////////////////////
// L4: Strings
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
// Reverse each line character-wise and concatenate them into a new string
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
// Input: str
// 
// for i ∈ [0, str.length / 2 ) do
//   swap(str[i], str[str.length - i - 1])
// 
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

void reverseStr(string& str)
{
    for (int i = 0; i < str.length() / 2; i++)
        swap(str[i], str[str.length() - i - 1]);
}
     
int main() {
  string s1, s2;
  
  cout << endl
       << "\033[1;36m"
       << "--------------------------------------------------------------"
       << "\033[0m"
       << endl;
  cout << "\033[1;36m"
       << "This program reverse two lines and join them in a new string."
       << "\033[0m"
       << endl;
  cout << "\033[1;36m"
       << "--------------------------------------------------------------"
       << "\033[0m"
       << endl << endl;

  cout << "Enter two strings: " << endl << endl ;

  cout << "[1]: ";
  getline(cin, s1);
  cout << "[2]: ";
  getline(cin, s2);
  cout << endl;

  reverseStr(s1);
  reverseStr(s2);

  string s1s2reversed = s2 + s1;

  cout << "Reversed: " << s1s2reversed
       << endl << endl; 
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: two strings odd
//   Input: Hello
//          World
//   Output: dlroWolleH
//   Expected: dlroWolleH
//   Result: PASS
//
// Case 2: two string even
//   Input: Good
//          Work
//   Output: kroWdooG
//   Expected: kroWdooG
//   Result: PASS
//
// Case 3: empty input
//   Input: 
//   Output: 
//   Expected: 
//   Result: PASS
//
// Case 4: using space
//   Input: Hello
//           World
//   Output:  dlroW olleH
//   Expected: dlroW olleH
//   Result: PASS
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
// 
//  The program is working correctly
//
////////////////////////////////////////////////////////////////////////