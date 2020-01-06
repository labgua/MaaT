/*
 * ds_linear_resolution.h
 *
 *  Created on: 07 gen 2019
 *      Author: sergio

	Questa libreria permette la risoluzione di sistemi lineari
	con due possibili approcci: metodo iterativo ('iter') e non ('solve').

	Per entrambi i casi bisogna indicare il risolutore da utilizzare.
	Esso è quindi una funzione tipicamente di tipo void che prende
	come unico input il sistema 'linear_system_data'

	void (*f)(linear_system_data*)

	L'astrazione è quindi gestita dal preprocessore e 
	gli opportuni include dei risolutori

 */

#ifndef LINEAR_SYSTEM_RESOLUTION_H_
#define LINEAR_SYSTEM_RESOLUTION_H_


#define iter(ls, iterf)  do{ iterf(ls); } while(0)

#define solve(ls, solvef) ( solvef(ls) )


#endif /* LINEAR_SYSTEM_RESOLUTION_H_ */
