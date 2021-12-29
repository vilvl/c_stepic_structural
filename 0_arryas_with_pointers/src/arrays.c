#include "io.h"

void array_int_fill( int64_t* array, size_t sz ) {
  for ( size_t i = 0; i < sz; i++){
        array[i] = read_int64();
    }
}

int64_t* array_int_read( size_t* size ) {
    *size = read_size();
    int64_t* array = malloc( sizeof( int64_t ) * *size );
    if (array){
        array_int_fill(array, *size);
        return array;
    }
    return 0;
}

int64_t* array_int_min( int64_t* array, size_t size ) {
    if (size == 0) {
        return 0;
    }
    int64_t* min = array;
    for ( size_t i = 0; i < size; i++ ){
        if ( array[i] < *min ){
            min = &array[i];
        }
    }
    return min;
}

void array_int_print( int64_t* array, size_t size ){
    for ( size_t i = 0; i < size; i++ ){
        intptr_print( &array[i] );
    }
}
