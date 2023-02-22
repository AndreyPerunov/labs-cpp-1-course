////////////////////////////////////////////////////////////////////////
// L3: Arrays
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
// Calculate the average of the elements of the array located before
// the largest element. Note that the average may not be an integer.
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
//  Input: array_size, array
//  Output: avg
//  
//  array_size <- 0
//  temp_int
//  largest <- 0
//  sum <- 0
//  avg <- 0
//  
//  
//  get array_size
//  if array_size < 0
//      throw an error
//  create array with the size of array_size
//  
//  for i ∈ [0, array_size) do
//      get temp_int
//      array[i] <- temp_int
//  
//  for i ∈ [0, array_size) do
//      print array[i] 
//  
//  for i ∈ [0, array_size) do
//      if array[i]>largest
//          largest <- array[i]
//  
//  i <- 0
//  if array_size > 0
//      while array[i] ≠ largest
//          sum = sum + array[i]
//          i = i + 1
//   
// if i > 0
//     avg = sum / (i)
//
//  print avg
//  
////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
    int array_size = 0;     // Size of an array.
    int temp_int;           // Temporary intager for input.
    int largest = 0;        // Largest number in array.
    double sum = 0;         // Sum (to calculate the average)
    double avg = 0;         // Average of the elements of the array located before the largest element.
    

    // Input the size of an array and handeling error 
    cout << "Enter size of an array: ";
    cin >> array_size;
    if (array_size<0)   
        throw runtime_error("Size must be positive!");
    int* array = new int[array_size];

    // Input initial array
    cout << "Enter elements of an array: ";
    for (int i = 0; i<array_size; i++) {
        cin >> temp_int;
        array[i] = temp_int;
    }

    // Outupt initial array
    cout << "Array: ";
    for (int i = 0; i<array_size; i++)
        cout << array[i] << " ";
    cout << '\n';

    // Find the largest number in array
    for (int i = 0; i<array_size; i++)
        if (array[i]>largest)
            largest = array[i];
    
    // Find an sum of the elements of the array located before the largest element.
    int i = 0;
    if (array_size>0)
    {
        while (array[i] != largest) {
            sum += array[i];
            i++;
        }
    }
    
    // Calculate average
    if (i>0)
        avg = sum/(i);

    // Outupt result
    cout << "Average: " << avg;
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: array_size > 0, largest number is last
//   Input: 5  1 2 3 4 5
//   Output: 2.5
//   Expected: 2.5
//   Result: PASS
//
// Case 2: array_size = 0
//   Input: 0
//   Output: 0
//   Expected: 0
//   Result: PASS
//
// Case 3: array_size < 0
//   Input: -3
//   Output: Size must be positive!
//   Expected: Size must be positive!
//   Result: PASS
//
// Case 4: array_size = 5.3
//   Input: 5.3
//   Output: 0
//   Expected: error
//   Result: fail
//
// Case 5: Non-numeric input
//   Input: Hello world!
//   Output: 0
//   Expected: error
//   Result: fail
//
// Case 6: array_size > 0, largest number is in the middle
//   Input: 5  1 2 5 3 4
//   Output: 1.5
//   Expected: 1.5
//   Result: PASS
//
// Case 7: array_size > 0, largest number is in the start
//   Input: 5  5 4 3 2 1
//   Output: 0
//   Expected: 0
//   Result: PASS
//
// Case 8: array_size > 0, Non-numeric input
//   Input: 5  1 2 test 3 4
//   Output: 1
//   Expected: error
//   Result: fail
//
// Case 9: Overflow
//   Input: 999999999999999999999999999
//   Output: infinite output of 24
//   Expected: error
//   Result: fail
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
// The program is working correctly for correct inputs.
// Overflow leads to strange results. Non-numeric input is not accepted.
// That's why non-numeric input result is 0.
// Some error handling may be profitable for better user experience.
//
////////////////////////////////////////////////////////////////////////