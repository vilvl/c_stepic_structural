#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "maybe_int64.h"

struct list {
  int64_t value;
  struct list* next;
};

struct list* list_read();

void list_print(const struct list* list);

struct list* node_create( int64_t value );

void list_destroy( struct list* list );

void list_add_front( struct list** list, int64_t value );

void list_add_back( struct list** list, int64_t value );

struct list* list_last( struct list * list );

struct maybe_int64 list_at( const struct list* list, size_t index );

size_t list_length( const struct list* list );

int64_t list_sum( const struct list* list );

// создать перевернутую копию списка
struct list* list_reverse( const struct list* list );

#endif