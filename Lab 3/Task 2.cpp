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
// Calculate the average for the skew diagonal of the array.
// Assert that nr = nc.
//
////////////////////////////////////////////////////////////////////////
// Algorithm
////////////////////////////////////////////////////////////////////////
//
//  Input: nr, nc
//  Output: avg
//  
// 
// nr
// nc
// sum = 0
// avg    
//? Initialize random seed
//
// get nr
// get nc
//
// if nr != nc
//     throw an error
//
//? create array arr with size of nc
//
// for i ∈ [0, nc) do
//?      arr[i] <- create array with size of nr
//
// for i ∈ [0, nc) do
//     for j ∈ [0, nr) do
//?         arr[i][j] <- random number in range [1, 10]
//
// for i ∈ [0, nc) do
//     for j ∈ [0, nr) do
//         print arr[i][j] 
//?     print endl
//
// j <- nr - 1
// for i ∈ [0, nc) do
//     sum <- sum + arr[i][j]
//     j <- j - 1
//
// avg <- sum / nc
//
// print avg
//  
////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
    int nr;         // Rows
    int nc;         // Columns
    double sum = 0;     // Sum of skew diagonal
    double avg;         // Sum of skew diagonal
    srand (time(NULL)); // Initialize random seed

    // Input the size of an array and handeling error 
    cout << endl;
    cout << "Enter number of rows and columns of matrix: ";
    cin >> nr >> nc;
    if (nr != nc)
        throw runtime_error("Number of rows and columns must be equal!");
    cout << endl;

    // Allocate a two-dimensional dynamic array
    unsigned** arr = new unsigned*[nc];
    for (int i = 0; i < nc; i++)
        arr[i] = new unsigned[nr];

    // Fill the array with random values
    for (int i = 0; i < nc; i++) 
        for (int j = 0; j < nr; j++)
            arr[i][j] = rand() % 10 + 1;

    // Print out the matrix
    cout << "Matrix: " << endl;
    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nr; j++) {
            cout << arr[i][j] << " ";
            if (arr[i][j] < 10) 
                cout << " "; 
        }
        cout << endl;
    }
    cout << endl;

    // Find sum of Skew diagonal
    int j = nr - 1;
    for (int i = 0; i < nc; i++) {
        sum += arr[i][j];
        j--;
    }

    // Find average of Skew diagonal
    avg = sum / nc;

    // Print out the results
    cout << "Average of Skew diagonal: " << avg;
    cout << endl;
}

////////////////////////////////////////////////////////////////////////
// Testing
////////////////////////////////////////////////////////////////////////
//
// Case 1: nr != nc
//   Input: 1 2
//   Output: Number of rows and columns must be equal!
//   Expected: Number of rows and columns must be equal!
//   Result: PASS
//
// Case 2: nr and nc = 0
//   Input: 0 0
//   Output: nan
//   Expected: nothing
//   Result: FAIL
//
// Case 3: nr = nc = 1
//   Input: 1 1
//   Output: 1
//   Expected: 1
//   Result: PASS
//
// Case 4: nr = nc = 2
//   Input: 2 2
//   Output: 9.5
//   Expected: 9.5
//   Result: PASS
//
// Case 5: nr and nc < 0
//   Input: -1 -1
//   Output: std::bad_array_new_length
//   Expected: error
//   Result: PASS
//
// Case 6: non-numerical input
//   Input: k k
//   Output: Number of rows and columns must be equal!
//   Expected: error
//   Result: FAIL
//
// Case 7: overflow
//   Input: 99999999999999999999999999999999999999999999999
//   Output: Number of rows and columns must be equal!
//   Expected: error
//   Result: FAIL
//
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
// The program is working correctly for correct inputs.
// Overflow and non-numeric input leads to strange results.
// That's why result is "Number of rows and columns must be equal!".
// Some error handling may be profitable for better user experience.
//
////////////////////////////////////////////////////////////////////////