////////////////////////////////////////////////////////////////////////
// L6: Standard template library
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
// Create an empty std::vector of [double]s.
// Fill the vector with [25] random values from the interval [–1, 1].
// Write a function (or overload operator<< of std::ostream if you wish)
// that would get a vector by const reference and print it out using[iterators] to access elements.
// Use the function from the previous step to print out your vector.
// Use STL algorithms to:
//   (1) insert 0 after each negative element;
//   (2) calculate the average of the elements;
//   (3) sort the vector in descending order.
// Print out the results (calculated property or the modified vector) for each of the tasks.
//
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
using namespace std;

// Write a function (or overload operator<< of std::ostream if you wish)
// that would get a vector by const reference and print it out using[iterators] to access elements.
ostream& operator << (ostream& os, const vector<double>& randomValues) {
	for (auto it = randomValues.begin(); it != randomValues.end(); ++it) {
		os << *it << " ";
	}
	os << endl;
	return os;
};

// [task]
// return average of a vector and transforms vector
double task(vector<double>& randomValues) {

	// (1) insert 0 after each negative element;
	for (vector<double>::iterator it = randomValues.begin(); it != randomValues.end();) {
		it = find_if(it, randomValues.end(), [](double n) {return n < 0; });
		if (it == randomValues.end()) // Do i need this?
			break;
		it = randomValues.insert(++it, 0);
	}

	// (2) calculate the average of the elements;
	double sum = accumulate(randomValues.begin(), randomValues.end(), 0.0);
	double avg = sum / randomValues.size();
	
	// (3) sort the vector in descending order.
	sort(randomValues.begin(), randomValues.end(), greater<double>());

	return avg;
}

int main() {
	// Create an empty std::vector of [double]s.
	vector<double> randomValues;
	srand(time(NULL));

	// Fill the vector with [25] random values from the interval [–1, 1].
	for (int i = 0; i < 25; i++) {
		double randomValue = (double)rand() / RAND_MAX * 2 - 1;
		randomValues.push_back(randomValue);
	}

	// Use the function from the previous step to print out your vector. 
	cout << "\033[34m" << "randomValues: " << randomValues << endl;

	// Use STL algorithms to [tasks].
	double average = task(randomValues);

	// Print out the results (calculated property or the modified vector) for each of the tasks.
	cout << "\033[32m" << "Sorted randomValues: " << randomValues << endl;
	cout << "Average: " << average << "\033[0m" << endl;

	return 0;
}
////////////////////////////////////////////////////////////////////////
// Output
////////////////////////////////////////////////////////////////////////
// 
// randomValues: -0.370281 0.975768 -0.461165 0.404462 0.0673544 -0.475204
// -0.862606 -0.624683 -0.656484 0.665395 0.202918 0.533189 -0.64275 0.509812
// -0.0301828 0.461043 0.501389 0.454939 -0.478256 -0.915403 0.468184 0.0146184
// -0.455184 -0.336894 0.528062 
// 
// Sorted randomValues: 0.975768 0.665395 0.533189 0.528062 0.509812 0.501389
// 0.468184 0.461043 0.454939 0.404462 0.202918 0.0673544 0.0146184 0 0 0 0 0
// 0 0 0 0 0 0 0 -0.0301828 -0.336894 -0.370281 -0.455184 -0.461165 -0.475204
// -0.478256 -0.624683 -0.64275 -0.656484 -0.862606 -0.915403 
// 
// Average: -0.014107
// 
////////////////////////////////////////////////////////////////////////
// Concluding remarks
////////////////////////////////////////////////////////////////////////
//
//  The program is working correctly.
//
////////////////////////////////////////////////////////////////////////