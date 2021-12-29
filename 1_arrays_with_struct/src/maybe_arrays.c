#include "maybe_int64.h"
#include "arrays.h"

struct maybe_array_int{
	struct array_int value;
	bool valid;
};

struct maybe_array_int some_array_int(struct array_int array){
	return (struct maybe_array_int){array, true};
}

const struct maybe_array_int none_array_int = {{0, 0}, false};
