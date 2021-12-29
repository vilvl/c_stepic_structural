#include "arrays.h"

int64_t** marray_read( size_t* rows, size_t** sizes ) {

    size_t rw = read_size();
    *rows = rw;

    int64_t** marray = (int64_t**)malloc( sizeof( int64_t* ) * rw );
    *sizes = (size_t*)malloc( sizeof( size_t ) * rw );

    for ( size_t i = 0; i < rw; i = i + 1 ){
        marray[i] = array_int_read( &(*sizes)[i] );
    }

    return marray;
}


void marray_print(int64_t** marray, size_t* sizes, size_t rows) {
    for( size_t i = 0; i < rows; i = i + 1 ) {
        array_int_print( marray[i], sizes[i] );
        print_newline();
    }
}

int64_t* int64_ptr_min(int64_t* x, int64_t* y) {
  if (!x) { return y; }
  if (!y) { return x; }
  if ( *y < *x ){ return y; }
  else { return x; }
}

int64_t* marray_int_min( int64_t** marray, size_t* sizes, size_t rows ) {
    int64_t* min = 0;
    for ( size_t i = 0; i < rows; i++){
       min = int64_ptr_min(min, array_int_min(marray[i], sizes[i]));
    }
    return min;
}

void marray_normalize( int64_t** marray, size_t sizes[], size_t rows, int64_t min ) {
    for( size_t i = 0; i < rows; i++ ) {
        for( size_t j = 0; j < sizes[i]; j++ ) {
            marray[i][j] = marray[i][j] - min;
        }
    }
}


void marray_free( int64_t** marray, size_t rows ) {
    for( size_t i = 0; i < rows; i = i + 1 ) {
        free( marray[i] );
    }
    free( marray );
}
