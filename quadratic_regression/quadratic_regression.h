/*
 * quadratic_regression.h
 *
 *  Created on: 04 giu 2019
 *      Author: sergio
 */

#ifndef QUADRATIC_REGRESSION_H_
#define QUADRATIC_REGRESSION_H_

/**
 * Esegue l'algoritmo di regressione quadratica (polinomio di 2 grado) passante
 * per i punti (x, y). il metodo calcola i coefficienti del polinomio y=ax^2 + bx + c
 * utilizzando formule sviscerate dalla risoluzione del sistema delle derivate parziali
 * mediante il metodo di cramer.
 *
 * X: vettore contenenti le ordinate xi delle coppie (xi, yi)
 * Y: vettore contenenti le ordinate yi delle coppie (xi, yi)
 * m: numero di punti
 * a: coefficiente di y=ax^2 + bx + c (scrive su a)
 * b: coefficiente di y=ax^2 + bx + c (scrive su b)
 * c: coefficiente di y=ax^2 + bx + c (scrive su c)
 */
void quadratic_regression( double* X, double* Y, int m, double* a, double* b, double* c );

#endif /* QUADRATIC_REGRESSION_H_ */
