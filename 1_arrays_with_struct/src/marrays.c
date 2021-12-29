#include "maybe_int64.h"
#include "maybe_arrays.h"

struct array_array_int{
	struct array_int *data;
	size_t size;
};

struct maybe_array_int array_array_int_get_row(struct array_array_int a, size_t i){
	if (i < a.size) {
        return some_array_int(a.data[i]);
    }
	else return none_array_int;
}

bool array_array_int_set_row(struct array_array_int a, size_t i, struct array_int value){
	if (i < a.size){
		a.data[i] = value;
		return true;
	}
	else return false;
}

/*  --- get/set ---  */

struct maybe_int64 array_array_int_get(struct array_array_int a, size_t i, size_t j)
{
	struct maybe_array_int in_a = array_array_int_get_row(a, i);
	if (!in_a.valid) {
		return none_int64;
	}
	return array_int_get(in_a.value, j);
}

bool array_array_int_set(struct array_array_int a, size_t i, size_t j, int64_t value){
	struct maybe_array_int in_a = array_array_int_get_row(a, i);
	if (!in_a.valid) { return false; }
	return array_int_set(in_a.value, j, value);
}

/*  --- read/print ---  */

struct array_array_int array_array_int_read(){
	size_t rows = read_size();
	struct array_int *data = malloc(sizeof *data * rows);
	for (size_t i = 0; i < rows; i++) {
        data[i] = array_int_read();
	}
	return (struct array_array_int){.data = data, .size = rows};
}

void array_array_int_print(struct array_array_int array){
	for (size_t i = 0; i < array.size; i++)	{
		const struct maybe_array_int in_a = array_array_int_get_row(array, i);
		if (in_a.valid)	{
			array_int_print(in_a.value);
		}
		print_newline();
	}
}

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min(struct array_array_int array){
	struct maybe_int64 min = none_int64;
	for (size_t i = 0; i < array.size; i++)	{
		const struct maybe_array_int in_a = array_array_int_get_row(array, i);
		if (in_a.valid)	{
			min = maybe_int64_min(min, array_int_min(in_a.value));
		}
	}
	return min;
}

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize(struct array_array_int array, int64_t m){
	for (size_t i = 0; i < array.size; i = i + 1) {
		const struct maybe_array_int cur_row = array_array_int_get_row(array, i);
		if (cur_row.valid)	{
			array_int_normalize(cur_row.value, m);
		}
	}
}

void array_array_int_free(struct array_array_int array){
	for (size_t i = 0; i < array.size; i++)	{
		struct maybe_array_int in_a = array_array_int_get_row(array, i);
		if (in_a.valid)	{
			array_int_free(in_a.value);
		}
	}
	free(array.data);

}