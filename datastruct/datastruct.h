/*
 * datastruct.h
 *
 *  Created on: 05 giu 2019
 *      Author: sergio
 */

#ifndef DATASTRUCT_H_
#define DATASTRUCT_H_

/**
 * linear_system_data è una struttura data che gestisce
 * la matrice dei coefficienti e dei temini noti.
 * La matrice dei coefficienti è gestita come un vettore di array
 */
typedef struct linear_system_data{
	double* A;
	double* b;
	double* x;
	double* y;
}linear_system_data;

/**
 * window_sample_data è una finestra di coppie (x,y) implementata
 * medinate l'ausilio di due array paralleli circolari.
 * size definisce la grandezza della finestra mentre next_free
 * rappresenta l'indice della prossima posizione libera.
 */
typedef struct window_sample_data{

	int next_free; //prossimo spazio libero

	int size;

	double* X;
	double* Y;

} window_sample_data;


/**
 * linear_predictor è la struttura dati che permette la realizzazione
 * di un predittore lineare, mediante l'algoritmo di regressione lineare
 */
typedef struct linear_predictor{
	window_sample_data window;

	// coefficienti della retta di regressione
	//  y = ax + b
	double a;
	double b;

	// variabili di calcolo della retta di regressione
	double s0, s1, s2, t0, t1;

} linear_predictor;


/**
 * quadratic_predictor è la struttura dati che permette la realizzazione
 * di un predittore quadratico (y = ax^2 + bx + c), mediante
 * l'algoritmo di regressione quadratico
 */
typedef struct quadratic_predictor{

	window_sample_data window;

	// coefficienti del polinomio di regressione
	//  y = ax^2 + bx + c
	double a;
	double b;
	double c;

	double s0, s1, s2, s3, s4;
	double t0, t1, t2;
	double d, da, db, dc;

} quadratic_predictor;



#endif /* DATASTRUCT_H_ */
