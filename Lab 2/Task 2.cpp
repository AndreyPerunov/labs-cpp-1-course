////////////////////////////////////////////////////////////////////////
// L2: Iteration statements
////////////////////////////////////////////////////////////////////////
//
// Andrejs Ivans Perunovs
// st81049
// Variation 5
//
////////////////////////////////////////////////////////////////////////
// Task formulation
////////////////////////////////////////////////////////////////////////
//
// Get a natural number x from the user.
// Print out the number y you get by discarding all the digits in x to
// the left of the rightmost 1. For example, if x is 212312, y will be 12.
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
//  Input: x
//  Output: y[]
//  
//  create y empty vector            
//  
//  get x
//  while x > 0 do
//      if x % 10 ≠ 1
//          put (x % 10) in the end of y[]
//          x = x / 10
//      else
//          put (1) in the end of y[]
//          breakFromLoop
//  
//  for i ∈ [y.size(), 0] do
//      print y[i]
//   
//  
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

int main() {
    unsigned int x;
    std::vector<int> y;
    
    std::cout << "Input integer number: ";
    std::cin >> x;


    while (x > 0) {
        if (x % 10 != 1) {
            y.push_back(x % 10);
            x /= 10;
        } else {
            y.push_back(1);
            break;
        }
    }

    for (int i = y.size()-1; i>=0; i--) 
        std::cout << y[i];
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: 1 at the start
//   Input: 1234567890
//   Output: 1234567890
//   Expected: 1234567890
//   Result: PASS
//
// Case 2: 1 in the end
//   Input: 987654321
//   Output: 1
//   Expected: 1
//   Result: PASS
//
// Case 3: 1 in the middle
//   Input: 987612345
//   Output: 12345
//   Expected: 12345
//   Result: PASS
//
// Case 4: no 1
//   Input: 29384756
//   Output: 29384756
//   Expected: 29384756
//   Result: PASS
//
// Case 5: x = 0
//   Input: 0
//   Output: no output
//   Expected: 0
//   Result: fail
//
// Case 6: x < 0
//   Input: -32123
//   Output: 173
//   Expected: fail
//   Result: fail
//
// Case 7: Non-numeric input
//   Input: Hi!
//   Output: no output
//   Expected: fail
//   Result: fail
//
// Case 8: Overflow
//   Input: 9999999999999999999999999
//   Output: 4294967295
//   Expected: fail
//   Result: fail
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
// 
// The program is working correctly for correct inputs.
// In case of an overflow, the input is truncated to the maximal integer and
// the result is 4294967295, which is not very user-friendly.
// Non-numeric input is not acceptred.
// That's why non-numeric input doesn't leads to any results from the
// perspective of the end user.
// Some error handling may be profitable for better user experience.
//
////////////////////////////////////////////////////////////////////////