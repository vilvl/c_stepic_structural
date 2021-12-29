#ifndef MBARRAYS_H
#define MBARRAYS_H

#include "arrays.h"

struct maybe_array_int{
	struct array_int value;
	bool valid;
};

extern const struct maybe_array_int none_array_int;

struct maybe_array_int some_array_int(struct array_int array);

#endif