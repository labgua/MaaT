
#include <iostream>
#include "../linear_regression.h"
using namespace std;


int main(int argc, char **argv) {

	cout << "Linear Regression" << endl; // prints

	// y = 2x
	double X[] = {1,2,3,4,5};
	double Y[] = {2,4,6,8,10};

	double a, b;

	linear_regression(X, Y, 5, &a, &b);

	cout << "la retta di regressione per le coppie di punti e'" << endl;
	cout << a << "X + " << b << endl;

}
