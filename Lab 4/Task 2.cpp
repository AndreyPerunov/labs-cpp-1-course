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
// return the shortest word in it (in sense of \w and \b regex classes)	
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
// 
// 
//  
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <regex>

using namespace std;

void getShortestWord(string s) {
  regex wordRule("[\\w]+"); 
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), wordRule);
  auto words_end = std::sregex_iterator();
  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
      std::smatch match = *i;                                                 
      std::string match_str = match.str(); 
      std::cout << match_str << '\n';
  }    
}

int main() {
  vector<string> sentences;
  string s;    

  cout << endl << "\033[1;36m-----------------------------------------------------------\033[0m" << endl;
  cout << "\033[1;36mThis program finds the shortest words in the given strings.\033[0m" << endl;
  cout << "\033[1;36m-----------------------------------------------------------\033[0m" << endl << endl;

  cout << "Enter some strings (enter '\033[31mquit\033[0m' to end input): " << endl << endl ;

  int count = 0;
  while (s != "quit") {
    cout << "[" << count << "]: ";
    getline(cin, s);
    sentences.push_back(s);
    count++;
  }

  // ? That's cool program

  getShortestWord(sentences[0]);
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1:
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 2: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 3: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 4: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 5: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 6: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 7: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 8: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
// Case 9: 
//   Input: 
//   Output: 
//   Expected: 
//   Result: 
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 
// 
// 
//
////////////////////////////////////////////////////////////////////////