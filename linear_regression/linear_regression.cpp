
#include "linear_regression.h"


void linear_regression( double* X, double* Y, int m, double* a, double* b){

	double s0 = m+1;
	double s1 = 0, s2 = 0, t0 = 0, t1 = 0;

	for( int i = 0; i < m; i++ ){
		s1 = s1 + X[i];
		s2 = s2 + X[i] * X[i];
		t0 = t0 + Y[i];
		t1 = t1 + X[i] * Y[i];
	}

	double denom = (s2 * s0) - (s1 * s1);

	*a = ((s0 * t1) - (s1 * t0)) / denom;
	*b = ((s2 * t0) - (s1 * t1)) / denom;

}