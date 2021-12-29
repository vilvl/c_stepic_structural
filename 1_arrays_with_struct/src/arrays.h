#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdlib.h>

#include "io.h"
#include "maybe_int64.h"

struct array_int{
	size_t size;
	int64_t *data;
};

void array_int_fill( int64_t* array, size_t sz );

struct array_int array_int_create( size_t size );

struct array_int array_int_read();

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get( struct array_int a, size_t i ) ;

// возвращает false если индекс за пределами массива
bool array_int_set( struct array_int a, size_t i, int64_t value ) ;

void array_int_print( struct array_int array ) ;

struct maybe_int64 array_int_min( struct array_int array );

void array_int_free( struct array_int a ) ;

void array_int_normalize(struct array_int array, int64_t m);

#endif
