
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

void quadratic_regression( double* X, double* Y, int m, double* a, double* b, double* c ){

	double s0 = m+1;
	double s1 = 0, s2 = 0, s3 = 0, s4 = 0, t0 = 0, t1 = 0, t2 = 0;
	double d, da, db, dc;

	double tmp_pow_xi;

	for( int i = 0; i < m; i++ ){

		tmp_pow_xi = X[i];

		t0 = t0 + Y[i];

		s1 = s1 + X[i];
		t1 = t1 + X[i] * Y[i];

		tmp_pow_xi = tmp_pow_xi * X[i];

		s2 = s2 + tmp_pow_xi;
		t2 = t2 + tmp_pow_xi * Y[i];

		tmp_pow_xi = tmp_pow_xi * X[i];

		s3 = s3 + tmp_pow_xi;

		tmp_pow_xi = tmp_pow_xi * X[i];

		s4 = s4 + tmp_pow_xi;

	}

	d  = s4*( s2*s0 - s1*s1 ) - s3*( s3*s0 - s1*s2 ) + s2*( s3*s1 - s2*s2 );
	da = t2*( s2*s0 - s1*s1 ) - s3*( t1*s0 - s1*t0 ) + s2*( t1*s1 - s2*t0 );
	db = s4*( t1*s0 - s1*t0 ) - t2*( s3*s0 - s1*s2 ) + s2*( s3*t0 - t1*s2 );
	dc = s4*( s2*t0 - t1*s1 ) - s3*( s3*t0 - t1*s2 ) + t2*( s3*s1 - s2*s2 );

	*a = da/d;
	*b = db/d;
	*c = dc/d;

}
