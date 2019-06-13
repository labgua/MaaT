#include "linear_predictor.h"

void setup() {

  Serial.begin(9600);
  
  linear_predictor* lp = create_predictor(5);

  add_point(lp, 1, 2);
  add_point(lp, 2, 4);
  add_point(lp, 3, 6);
  add_point(lp, 4, 8);
  add_point(lp, 5, 10);

  // y = 2X
  linear_regression_update(lp);

  double result = prevision(lp, 15);

  cout << "prevision for 15 : " << result << endl;
  
  Serial.println("Linear Predictor Test");
  Serial.print("prevision for 15 : ");
  Serial.println(result);
  
}

void loop() {

}
