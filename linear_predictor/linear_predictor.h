/*
 * linear_predictor.h
 *
 *  Created on: 03 giu 2019
 *      Author: sergio
 *
 *  Questa libreria crea una finestra di punti su cui fare
 */

#ifndef LINEAR_PREDICTOR_H_
#define LINEAR_PREDICTOR_H_

#include <ds_window/ds_window.h>

/**
 * linear_predictor è la struttura dati che permette la realizzazione
 * di un predittore lineare, mediante l'algoritmo di regressione lineare
 */
typedef struct linear_predictor{
	window_sample_data* window;

	// coefficienti della retta di regressione
	//  y = ax + b
	double a;
	double b;

	// variabili di calcolo della retta di regressione
	double s0, s1, s2, t0, t1;

} linear_predictor;


linear_predictor* create_predictor(int size_window);

void add_point(linear_predictor *pd, double x, double y);

void add_point_with_linear_update(linear_predictor *pd, double x, double y);

double prevision(linear_predictor *pd, double x);

double prevision_offset(linear_predictor *pd, double offset);

void linear_regression_update(linear_predictor *pd);


#endif /* LINEAR_PREDICTOR_H_ */
