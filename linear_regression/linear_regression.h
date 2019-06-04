/*
 * linear_regression.h
 *
 *  Created on: 03 giu 2019
 *      Author: sergio
 */

#ifndef LINEAR_REGRESSION_H_
#define LINEAR_REGRESSION_H_

/**
 * Esegue l'algoritmo di regressione lineare per calcolare la retta y=ax+b
 * passante per i punti (x, y). il metodo calcola i coefficienti in maniera
 * statica, codificando la soluzione del sistema delle derivate parziali.
 * Questa funzione scrive il risultato in a e b.
 *
 * X: vettore contenenti le ordinate xi delle coppie (xi, yi)
 * Y: vettore contenenti le ordinate yi delle coppie (xi, yi)
 * m: numero di punti
 * a: coefficiente di regressione, o di regressione (scrive su a)
 * b: costante della retta (scrive su b)
 */
void linear_regression( double* X, double* Y, int m, double* a, double* b);


#endif /* LINEAR_REGRESSION_H_ */
