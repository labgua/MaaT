#include <quadratic_regression.h>

void setup() {

  Serial.begin(9600);
  
  // y = 2x^2 + x
  double X[] = {1,2,3,4,5};
  double Y[] = {3,10,21,36,55};
  
  double a, b, c;

  quadratic_regression(X, Y, 5, &a, &b, &c);
  
  Serial.println("Quadratic Regression Test");
  Serial.print(a);
  Serial.print("x^2 + ");
  Serial.print(b);
  Serial.print("x + ");
  Serial.print(c);
  
}

void loop() {

}