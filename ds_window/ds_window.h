/*
 * ds_window.h
 *
 *  Created on: 05 giu 2019
 *      Author: sergio
 */

#ifndef DS_WINDOW_H_
#define DS_WINDOW_H_

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


#define get_last_sample_window(window, index)  window->X[ (window->next_free + window->size - 1) % window->size ]

window_sample_data* create_sample_window(int size_window);

void add_sample(window_sample_data* window, double x, double y);




#endif /* DS_WINDOW_H_ */
