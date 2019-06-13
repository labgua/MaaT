
#include "ds_window.h"
#include "linear_predictor.h"


linear_predictor* create_predictor(int size_window){

	linear_predictor* new_pd = new linear_predictor;
	new_pd->window = create_sample_window(size_window);

	return new_pd;
}

void add_point(linear_predictor* pd, double x, double y){

	add_sample(pd->window, x, y);
}

void add_point_with_linear_update(linear_predictor* pd, double x, double y){

	int next = pd->window->next_free;

	//instant update regression model
	// 1 - remove last point
	pd->s1 = pd->s1 - pd->window->X[next];
	pd->s2 = pd->s2 - pd->window->X[next] * pd->window->X[next];
	pd->t0 = pd->t0 - pd->window->Y[next];
	pd->t1 = pd->t1 - pd->window->X[next] * pd->window->Y[next];

	pd->window->X[next] = x;
	pd->window->Y[next] = y;

	//instant update regression model
	// 2 - add last point
	pd->s1 = pd->s1 + pd->window->X[next];
	pd->s2 = pd->s2 + pd->window->X[next] * pd->window->X[next];
	pd->t0 = pd->t0 + pd->window->Y[next];
	pd->t1 = pd->t1 + pd->window->X[next] * pd->window->Y[next];

	//instant update regression model
	// 3 - update a and b of linear regression
	double denom = (pd->s2 * pd->s0) - (pd->s1 * pd->s1);

	pd->a = ((pd->s0 * pd->t1) - (pd->s1 * pd->t0)) / denom;
	pd->b = ((pd->s2 * pd->t0) - (pd->s1 * pd->t1)) / denom;


	pd->window->next_free = (next + 1)% pd->window->size;
}

double prevision(linear_predictor* pd, double x){
	return pd->a * x + pd->b;
}

double prevision_offset(linear_predictor* pd, double offset){
	int last_x_index = (pd->window->next_free + pd->window->size - 1) % pd->window->size;
	double last_x = pd->window->X[last_x_index];

	return prevision(pd, last_x + offset);
}

void linear_regression_update(linear_predictor* pd){

	pd->s0 = pd->window->size + 1;
	pd->s1 = 0, pd->s2 = 0, pd->t0 = 0, pd->t1 = 0;

	for( int i = 0; i < pd->window->size; i++ ){
		pd->s1 = pd->s1 + pd->window->X[i];
		pd->s2 = pd->s2 + pd->window->X[i] * pd->window->X[i];
		pd->t0 = pd->t0 + pd->window->Y[i];
		pd->t1 = pd->t1 + pd->window->X[i] * pd->window->Y[i];
	}

	double denom = (pd->s2 * pd->s0) - (pd->s1 * pd->s1);

	pd->a = ((pd->s0 * pd->t1) - (pd->s1 * pd->t0)) / denom;
	pd->b = ((pd->s2 * pd->t0) - (pd->s1 * pd->t1)) / denom;

}

