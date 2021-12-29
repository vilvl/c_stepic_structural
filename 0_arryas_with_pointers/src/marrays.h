#ifndef MARRAYS_H
#define MARRAYS_H

#include <inttypes.h>
#include <stdlib.h>
#include "arrays.h"

int64_t** marray_read( size_t* rows, size_t** sizes );

void marray_print(int64_t** marray, size_t* sizes, size_t rows);

int64_t* marray_int_min( int64_t** marray, size_t* sizes, size_t rows );

void marray_normalize( int64_t** marray, size_t sizes[], size_t rows, int64_t min );

void marray_free( int64_t** marray, size_t rows );

#endif
