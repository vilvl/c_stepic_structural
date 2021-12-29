#ifndef MARRAYS_H
#define MARRAYS_H

#include "maybe_arrays.h"

struct array_array_int{
	struct array_int *data;
	size_t size;
};

struct maybe_array_int array_array_int_get_row(struct array_array_int a, size_t i);

bool array_array_int_set_row(struct array_array_int a, size_t i, struct array_int value);

/*  --- get/set ---  */

struct maybe_int64 array_array_int_get(struct array_array_int a, size_t i, size_t j);

bool array_array_int_set(struct array_array_int a, size_t i, size_t j, int64_t value);

/*  --- read/print ---  */

struct array_array_int array_array_int_read();

void array_array_int_print(struct array_array_int array);

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min(struct array_array_int array);

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize(struct array_array_int array, int64_t m);

void array_array_int_free(struct array_array_int array);

#endif