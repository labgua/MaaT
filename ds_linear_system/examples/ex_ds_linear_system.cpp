/*
 * ex_ds_linear_system.cpp
 *
 *  Created on: 14 giu 2019
 *      Author: sergio
 */

#include <iostream>
#include "ds_linear_system.h"
using namespace std;

int main(int argc, char **argv) {

	cout << "Test Datastruct Linear System" << endl; // prints

	linear_system_data* ls = create_linear_system(2, 2);

	set_coefficient(ls, 0, 0, 1);
	set_coefficient(ls, 0, 1, 2);
	set_coefficient(ls, 1, 0, 3);
	set_coefficient(ls, 1, 1, 4);

	set_constant(ls, 0, 5);
	set_constant(ls, 1, 6);

	cout << "Linear system Created!" << endl;

	cout << "A[0,0] = " << get_coefficient(ls, 0, 0) << endl;
	cout << "A[0,1] = " << get_coefficient(ls, 0, 1) << endl;
	cout << "A[1,0] = " << get_coefficient(ls, 1, 0) << endl;
	cout << "A[1,1] = " << get_coefficient(ls, 1, 1) << endl;

	cout << "b[0] = " << get_constant(ls, 0) << endl;
	cout << "b[1] = " << get_constant(ls, 1) << endl;


}
