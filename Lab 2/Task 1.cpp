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
// Get two integers, a and b, from the user.
// Count even numbers in the range [a, b].
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
//   Input: a, b
//   Output: count
//
//   count <- 0
//   get a, b
//   for i ∈ [a, b] do
//      if i % 2 = 0
//          count <- count + 1
//   print count
//
////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
    int a;
    int b;
    int count = 0;
    
    std::cout << "Input two integer numbers: ";
    std::cin >> a >> b;

    for (int i = a; i <= b; i++)
        if (i % 2 == 0)
            count++;

    std::cout << "Number of even numbers in range [ " << a << ", " << b << " ] is " << count << '\n';
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: a < b
//   Input: 12 24
//   Output: Number of even numbers in range [ 12, 24 ] is 7
//   Expected: Number of even numbers in range [ 12, 24 ] is 7
//   Result: PASS
//
// Case 2: a = b
//   Input: 30 30
//   Output: Number of even numbers in range [ 30, 30 ] is 1
//   Expected: Number of even numbers in range [ 30, 30 ] is 1
//   Result: PASS
//
// Case 3: a > b
//   Input: 12 7
//   Output: Number of even numbers in range [ 12, 7 ] is 0
//   Expected: fail
//   Result: FAIL
//
// Case 4: Overflow
//   Input: 9999999999999999999999999999999999999999999999999999999999999999999
//          9999999999999999999999999999999999999999999999999999999999999999999
//   Output: Number of even numbers in range [ 2147483647, -1207821888 ] is 0
//   Expected: fail
//   Result: FAIL
//
// Case 5: Non-numeric input
//   Input: Hello World!
//   Output: Number of even numbers in range [ 0, 1315838400 ] is 657919201
//   Expected: fail
//   Result: Fail
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
// The program is working correctly for correct inputs.
// In case of an overflow, the input is truncated to the maximal integer
// and the result is 0, which is not very user-friendly.
// Non-numeric input is interpreted as zero for variable a.
// Variable b is not prompt so it stores garbage.
// That's why non-numeric input leads to strange results
// from the perspective of the end user.
// Some error handling may be profitable for better user experience.
//
////////////////////////////////////////////////////////////////////////