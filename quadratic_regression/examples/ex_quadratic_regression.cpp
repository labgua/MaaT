#include <iostream>
#include "../quadratic_regression.h"
using namespace std;


int main(int argc, char **argv) {

	cout << "Quadratic Regression" << endl; // prints

	// y = 2x^2 + x
	double X[] = {1,2,3,4,5};
	double Y[] = {3,10,21,36,55};

	double a, b, c;

	quadratic_regression(X, Y, 5, &a, &b, &c);

	cout << "la retta di regressione per le coppie di punti e'" << endl;
	cout << a << "X^2 + " << b << "X + " << c << endl;

}
