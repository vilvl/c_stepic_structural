#include <stdlib.h>

#include "io.h"
#include "maybe_int64.h"

struct array_int{
	size_t size;
	int64_t *data;
};

void array_int_fill( int64_t* array, size_t sz ) {
  for( size_t i = 0; i < sz; i = i + 1 ) {
    array[i] = read_int64();
  }
}

struct array_int array_int_create( size_t size ) {
    int64_t* array = malloc( sizeof *array * size);
    array_int_fill( array, size );
    return (struct array_int) { .data = array, .size = size };
}

struct array_int array_int_read() {
  const size_t size = read_size();
  if (size > 0) {
    return array_int_create( size );
  }
  else return (struct array_int) {0};
}

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get( struct array_int a, size_t i ) {
    if ( i >= a.size ) { return (struct maybe_int64) {0}; }
    return (struct maybe_int64) { .valid = true, .value = a.data[i] };
}

// возвращает false если индекс за пределами массива
bool array_int_set( struct array_int a, size_t i, int64_t value ) {
    if ( i >= a.size ) { return false; }
    a.data[i] = value;
    return true;
}

void array_int_print( struct array_int array ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    printf("%" PRId64 " " , array_int_get( array, i).value);
  }
}

struct maybe_int64 array_int_min( struct array_int array ) {
    if (array.size == 0) return (struct maybe_int64) {0};
    int64_t min = array.data[0];
    for (size_t ii = 0; ii < array.size; ii++ ) {
        if (array.data[ii] < min){
            min = array.data[ii] ;
            }
    }
    return (struct maybe_int64) { .valid = true, .value = min } ;
}

void array_int_free( struct array_int a ) { 
    if ( a.size > 0 ) {
        free(a.data); 
        a.size = 0;
    } 
}

void array_int_normalize(struct array_int array, int64_t m)
{
	for (size_t i = 0; i < array.size; i = i + 1) {
        array.data[i] = array.data[i] - m;
	}
}
