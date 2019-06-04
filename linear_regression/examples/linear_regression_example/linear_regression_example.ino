#include <linear_regression.h>

void setup() {

  Serial.begin(9600);
  
  // y = 2x
  double X[] = {1,2,3,4,5};
  double Y[] = {2,4,6,8,10};
  
  double a, b;

  linear_regression(X, Y, 5, &a, &b);
  
  Serial.println("Linear Regression Test");
  Serial.print(a);
  Serial.print("x + ");
  Serial.println(b);
  
}

void loop() {

}