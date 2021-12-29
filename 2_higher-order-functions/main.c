#pragma GCC diagnostic error "-Wall"
#pragma GCC diagnostic error "-Wdiscarded-qualifiers"
#pragma GCC diagnostic error "-Wincompatible-pointer-types"
#pragma GCC diagnostic error "-Wint-conversion"

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <inttypes.h>
#include <stdint.h>
#include "io.h"
#include "list.h"

// --- начало решения на Stepik ---

typedef int64_t folding(int64_t, int64_t);

/* Запустить функцию f на каждом элементе списка  */
void list_foreach(const struct list *list, void(f)(int64_t))
{
  while (list)
  {
    f(list->value);
    list = list->next;
  }
}

/* Изменить каждый элемент списка с помощью функции f  */
void list_map_mut(struct list *list, int64_t(f)(int64_t))
{
  while (list)
  {
    list->value = f(list->value);
    list = list->next;
  }
}

/*  Создать новый список, в котором каждый элемент получен из соответствующего
 элемента списка l путём применения функции f */
struct list *list_map(const struct list *list, int64_t(f)(int64_t))
{
  if (!list)
    return 0;
  struct list *head = node_create(f(list->value));
  struct list *new_list = head;
  while (list->next)
  {
    list = list->next;
    new_list->next = node_create(f(list->value));
    new_list = new_list->next;
  }
  return head;
}

/* Свернуть список l с помощью функции f. */
int64_t list_fold(const struct list *list, int64_t init, folding f)
{
  while (list)
  {
    init = f(init, list->value);
    list = list->next;
  }
  return init;
}

/*  Сгенерировать список длины sz с помощью значения init и функции f
 Результат: init, f(init), f(f(init)), ... */
struct list *list_iterate(int64_t init, size_t sz, int64_t(f)(int64_t))
{
  if (!sz)
    return 0;
  struct list *head = node_create(init);
  struct list *node = head;
  for (size_t i = 1; i < sz; i++)
  {
    node->next = node_create(f(node->value));
    node = node->next;
  }
  return head;
}

// --- конец решения на Stepik ---

void print_int64_space(int64_t i)
{
  print_int64(i);
  printf(" ");
}

static int64_t triple(int64_t x) { return x * 3; }
static int64_t square(int64_t x) { return x * x; }
static int64_t sum(int64_t x, int64_t y) { return x + y; }

struct list *c(int64_t value, struct list *tail)
{
  struct list *l = node_create(value);
  l->next = tail;
  return l;
}

int main()
{
  typedef struct list list;
  list *l1 = c(1, c(2, c(3, c(9, NULL))));
  list const *l1c = l1;

  list_foreach(l1c, print_int64_space);
  print_newline();

  list *l2 = list_map(l1c, triple);
  list_map_mut(l2, square);
  list const *l2c = l2;

  list_foreach(l2c, print_int64_space);
  print_newline();

  print_int64(list_fold(l2c, 0, sum));
  print_newline();

  list *l3 = list_iterate(7, 10, triple);
  list const *l3c = l3;
  list_foreach(l3c, print_int64_space);
  print_newline();

  list_destroy(l1);
  list_destroy(l2);
  list_destroy(l3);

  return 0;
}
