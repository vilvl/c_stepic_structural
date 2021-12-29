#ifndef STACK_H
#define STACK_H

#include <inttypes.h>
#include "maybe_int64.h"
#include "arrays.h"
#include "io.h"

struct stack {
  size_t count;
  struct array_int data;
};

// Количество элементов в стеке
size_t stack_count( const struct stack* s );

// Создаем и деинициализируем стек
struct stack stack_create( size_t size );

void stack_destroy( struct stack* s );

// Стек полный
bool stack_is_full( const struct stack * s);
// Стек пустой
bool stack_is_empty( const struct stack * s);

// Поместить значение в стек
bool stack_push( struct stack* s, int64_t value );

// Вынуть значение с вершины стека. Может вернуть none_int64
struct maybe_int64 stack_pop( struct stack* s );

void stack_print( const struct stack* s );

#endif