
#include "ds_linear_system.h"

void setup() {

	Serial.begin(9600);
	Serial.println("Test Datastruct Linear System");

	linear_system_data* ls = create_linear_system(2, 2);

	set_coefficient(ls, 0, 0, 1);
	set_coefficient(ls, 0, 1, 2);
	set_coefficient(ls, 1, 0, 3);
	set_coefficient(ls, 1, 1, 4);

	set_constant(ls, 0, 5);
	set_constant(ls, 1, 6);

	Serial.println("Linear system Created!");

	Serial.print("A[0,0] = ");
	Serial.println( get_coefficient(ls, 0, 0) );

	Serial.print("A[0,0] = ");
	Serial.println( get_coefficient(ls, 0, 1) );

	Serial.print("A[0,0] = ");
	Serial.println( get_coefficient(ls, 1, 0) );

	Serial.print("A[0,0] = ");
	Serial.println( get_coefficient(ls, 1, 1) );



	Serial.print("b[0] = ");
	Serial.println( get_constant(ls, 0) );

	Serial.print("b[0] = ");
	Serial.println( get_constant(ls, 1) );
  
}

void loop() {

}