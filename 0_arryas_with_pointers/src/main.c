#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#include "marrays.h"

int main(){
    size_t* sizes = 0;
    size_t rows = 0;
    int64_t* min = 0;
    int64_t** marray = marray_read( &rows, &sizes );
    if (rows){
        min = marray_int_min( marray, sizes, rows );
    }
    if (min) {
        marray_normalize( marray, sizes, rows, *min);
    }
    marray_print(marray, sizes, rows);
    marray_free(marray, rows);
    if (sizes) {
        free(sizes);
    }
    return 0;
}
