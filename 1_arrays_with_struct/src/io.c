#include <stdio.h>
#include <inttypes.h>

#ifdef _WIN32
#ifdef _WIN64
#define PRI_SIZET PRIu64
#else
#define PRI_SIZET PRIu32
#endif
#else
#define PRI_SIZET "zu"
#endif


int64_t read_int64(){
    int64_t x = 0;
    scanf("%" SCNd64, &x);
    return x;
}

void print_int64( int64_t x){
    printf("%" PRId64, x);
}

size_t read_size(){
    size_t sz = 0;
    scanf("%" PRI_SIZET, &sz);
    return sz;
}

void intptr_print( int64_t* x ) {
    printf(" %" PRId64, *x);
}

void print_newline() {
    printf("\n");
}
