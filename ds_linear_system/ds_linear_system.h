/*
 * ds_linear_system.h
 *
 *  Created on: 13 giu 2019
 *      Author: sergio
 */

#ifndef DS_LINEAR_SYSTEM_H_
#define DS_LINEAR_SYSTEM_H_

/**
 * linear_system_data è una struttura data che gestisce
 * la matrice dei coefficienti e dei temini noti.
 * La matrice dei coefficienti è gestita come un vettore
 */
typedef struct linear_system_data{
	int num_row;
	int num_col;
	double* A;
	double* b;
} linear_system_data;



/**
 * Crea una struttura per il sistema lineare
 * Prende in input il numero di righe e colonne del sistema
 */
linear_system_data* create_linear_system(int num_rom, int num_col);

/**
 * Imposta un coefficiente del sistema
 * ls: puntatore a linear_system_struct
 * i: indice riga
 * j: indice colonna
 * v: valore da inserire (double)
 */
#define set_coefficient(ls, i, j, v)  do{ ls->A[ (i * ls->num_row) + j  ] = v; } while(0)

/**
 * accede ad un coefficiente del sistema
 * restituisce il coefficiente presente in posizione A[i][j] (resituisce double)
 */
#define get_coefficient(ls, i, j)	  ( ls->A[ (i * ls->num_row) + j ] )

/**
 * Imposta una costante (termine noto) del sistema
 * ls: puntatore a linear_system_struct
 * i: indice della costante (o dell'eq. associata)
 * v: valore da inserire (double)
 */
#define set_constant(ls, i, v)		  do{ ls->b[i] = v; } while(0)

/**
 * Accede ad un termine noto del sistema
 * restituisce il termine noto i-esimo (restituisce un double)
 */
#define get_constant(ls, i)			  ( ls->b[i] )


#endif /* DS_LINEAR_SYSTEM_H_ */
