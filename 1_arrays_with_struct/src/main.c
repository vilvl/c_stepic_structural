#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>

#include "marrays.h"

int perform_marray(){
    struct array_array_int a = array_array_int_read();
	struct maybe_int64 mb_min = array_array_int_min(a);
    if (mb_min.valid) {
        array_array_int_normalize( a, mb_min.value );
    }
	array_array_int_print(a);
	array_array_int_free(a);
	
    return 0;
}


int main() {
	perform_marray();
}