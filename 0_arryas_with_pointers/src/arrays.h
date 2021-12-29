#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdlib.h>
#include <inttypes.h>
#include "io.h"

void array_int_fill( int64_t* array, size_t sz );

int64_t* array_int_read( size_t* size );

int64_t* array_int_min( int64_t* array, size_t size );

void array_int_print( int64_t* array, size_t size );

#endif
