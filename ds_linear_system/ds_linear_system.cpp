
#include "ds_linear_system.h"

linear_system_data* create_linear_system(int num_rows, int num_cols){
	linear_system_data* new_ls = new linear_system_data;
	new_ls->A = new double[num_rows * num_cols];
	new_ls->b = new double[num_rows];
	new_ls->num_row = num_rows;
	new_ls->num_col = num_cols;
	return new_ls;
}
