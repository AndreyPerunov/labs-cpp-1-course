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
// Change the case (upper to lower and vice-versa) of all the letters in it
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
// Input: str
// 
// for i ∈ [0, str.length ) do
//   if str[i] is uppercase do
//     str[i] <- str[i] + 32
//   else if str[i] is lowercase do
//     str[i] <- str[i] - 32
//     
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void flipCase(string *s) {
  for (int i = 0; i < (*s).length(); i++) {
    if(isupper((*s)[i]))
      (*s)[i] += 32;
    else if(islower((*s)[i]))
      (*s)[i] -= 32;
  }
}

int main() {
  vector<string> sentences;
  string s;    

   cout << endl
       << "\033[1;36m"
       << "--------------------------------------------------------------"
       << "\033[0m"
       << endl;
  cout << "\033[1;36m"
       << "This program change the case of all the letters in it"
       << "\033[0m"
       << endl;
  cout << "\033[1;36m"
       << "--------------------------------------------------------------"
       << "\033[0m"
       << endl << endl;

  cout << "Enter some strings (enter '\033[31mquit\033[0m' to end input): "
       << endl << endl ;

  int count = 0;
  while (s != "quit") {
    cout << "[" << count << "]: ";
    getline(cin, s);
    if (s != "quit") 
      sentences.push_back(s);
    count++;
  }

  cout << endl << "\033[1;36mFlipped:\033[0m " << endl << endl;

  count = 0;
  for (auto sentence : sentences) {
    flipCase(&sentence);
    cout << "[" << count << "]: ";
    cout << sentence << endl;
    count++;
  }

  cout << endl;  
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: Correct input
//   Input: HellO
//          World 
//          Sky is Blue
//          DANGER
//          hi
//          What's Up
//          HaHaHaHa
//   Output: hELLo
//           wORLD
//           sKY IS bLUE
//           danger
//           HI
//           wHAT'S uP
//           hAhAhAhA
//   Expected: hELLo
//             wORLD
//             sKY IS bLUE
//             danger
//             HI
//             wHAT'S uP
//             hAhAhAhA
//   Result: PASS
//
// Case 2: empty input
//   Input: 
//   Output: 
//   Expected: 
//   Result: PASS
//
// Case 3: numbers
//   Input: 123
//          456
//          789
//   Output: 123
//           456
//           789
//   Expected: 123
//             456
//             789
//   Result: PASS
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
// 
//  The program is working correctly 
//
////////////////////////////////////////////////////////////////////////