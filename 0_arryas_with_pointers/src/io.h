#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <inttypes.h>

#ifdef _WIN32
#  ifdef _WIN64
#    define PRI_SIZET PRIu64
#  else
#    define PRI_SIZET PRIu32
#  endif
#else
#  define PRI_SIZET "zu"
#endif

int64_t read_int64();

size_t read_size();

void intptr_print( int64_t* x );

void print_newline();

#endif
