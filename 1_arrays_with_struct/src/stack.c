#include <inttypes.h>
#include "maybe_int64.h"
#include "arrays.h"
#include "io.h"

struct stack {
  size_t count;
  struct array_int data;
};

// Количество элементов в стеке
size_t stack_count( const struct stack* s ){
    return s->count;
    };

// Создаем и деинициализируем стек
struct stack stack_create( size_t size ){
    return (struct stack ) {.count = 0, .data = array_int_create( size ) };
}

void stack_destroy( struct stack* s ){
    array_int_free( s->data );
}

// Стек полный
bool stack_is_full( const struct stack * s){
    return (s->count >= s->data.size);
};
// Стек пустой
bool stack_is_empty( const struct stack * s){
    return (s->count == 0);
};

// Поместить значение в стек
bool stack_push( struct stack* s, int64_t value ){
    if (stack_is_full(s)) {return false;}
    //s->count = s->count + 1;
    return array_int_set(s->data, s->count++, value);
}

// Вынуть значение с вершины стека. Может вернуть none_int64
struct maybe_int64 stack_pop( struct stack* s ){
    if (stack_is_empty(s)) { return none_int64; }
    s->count = s->count - 1;
    return array_int_get(s->data, s->count);
}

void stack_print( const struct stack* s ) {
  for (size_t i = 0; i < stack_count( s ); i = i + 1 ) {
    print_int64( array_int_get( s->data, i).value );
    printf(" ");
  }
}