
#include <ds_window.h>

window_sample_data create_sample_window(int size_window){

	window_sample_data new_window = new window_sample_data;

	new_window.X = new double[size_window];
	new_window.Y = new double[size_window];
	new_window.size = size_window;
	new_window.next_free = 0;

	return new_window;
}

void add_sample(window_sample_data* window, double x, double y){

	int next = window->next_free;

	window->X[next] = x;
	window->Y[next] = y;

	window->next_free = (next + 1)% window->size;

}
