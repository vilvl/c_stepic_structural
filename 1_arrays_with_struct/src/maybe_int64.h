#ifndef MBINT64_H
#define MBINT64_H

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

struct maybe_int64 {
  bool valid;
  int64_t value;
};

extern const struct maybe_int64 none_int64;

struct maybe_int64 some_int64( int64_t i );

// упакованное число 42 выводится как "Some 42"
// Ошибка выводится как None
void maybe_int64_print( struct maybe_int64 i );

struct maybe_int64 maybe_read_int64();

// Если обе упаковки содержат ошибку, то результат ошибка
// Если ровно одна упаковка содержит ошибку, то результат -- вторая
// Если обе упаковки содержат число, то результат это минимум из двух чисел.
struct maybe_int64 maybe_int64_min(struct maybe_int64 a, struct maybe_int64 b);

#endif