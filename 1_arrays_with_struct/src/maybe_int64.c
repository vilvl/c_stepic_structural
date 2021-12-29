#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

struct maybe_int64 {
  bool valid;
  int64_t value;
};

struct maybe_int64 some_int64( int64_t i ) {
  return (struct maybe_int64) { .value = i, .valid = true };
}

const struct maybe_int64 none_int64 = { 0 };

// упакованное число 42 выводится как "Some 42"
// Ошибка выводится как None
void maybe_int64_print( struct maybe_int64 i ) {
    if ( !i.valid ){ printf("None"); }
    else { printf("Some %" PRId64 ,  i.value); }
}

struct maybe_int64 maybe_read_int64() {
    struct maybe_int64 x = none_int64;
    x.valid = (scanf("%" SCNd64, &x.value) != -1);
    return x;
}

// Если обе упаковки содержат ошибку, то результат ошибка
// Если ровно одна упаковка содержит ошибку, то результат -- вторая
// Если обе упаковки содержат число, то результат это минимум из двух чисел.
struct maybe_int64 maybe_int64_min(struct maybe_int64 a, struct maybe_int64 b) {
    if ( !a.valid ) { return b; }
    if ( !b.valid ) { return a; }
    if ( a.value < b.value ){ return a;} 
    return b;
}

