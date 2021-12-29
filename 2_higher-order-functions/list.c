#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "maybe_int.h"
#include "io.h"

void list_print(const struct list *list)
{
    while (list)
    {
        printf("%" PRId64 " ", list->value);
        list = list->next;
    }
}

struct list *node_create(int64_t value)
{
    struct list *node = malloc(sizeof *node);
    if (node)
    {
        node->next = 0;
        node->value = value;
    }
    return node;
}

void list_add_front(struct list **list, int64_t value)
{
    struct list *new_frst = node_create(value);
    if (!new_frst)
        return;
    new_frst->next = *list;
    *list = new_frst;
}

size_t list_length(const struct list *list)
{
    size_t size = 0;
    while (list)
    {
        size = size + 1;
        list = list->next;
    }
    return size;
}

struct list *list_last(struct list *list)
{
    if (!list)
    {
        return 0;
    }
    while (list->next)
    {
        list = list->next;
    }
    return list;
}

void list_destroy(struct list *list)
{
    if (list)
    {
        list_destroy(list->next);
        free(list);
    }
}

void list_add_back(struct list **list, int64_t value)
{
    if (!*list)
    {
        *list = node_create(value);
        return;
    }
    struct list *last_node = list_last(*list);
    last_node->next = node_create(value);
}

int64_t list_sum(const struct list *list)
{
    int64_t sum = 0;
    while (list)
    {
        sum = sum + list->value;
        list = list->next;
    }
    return sum;
}

struct list *list_node_at(struct list *list, size_t index)
{
    size_t counter = 0;
    while (list)
    {
        if (counter == index)
        {
            return list->value;
        }
        counter = counter + 1;
        list = list->next;
    }
    return 0;
}

struct maybe_int64 list_at(struct list *list, size_t index)
{
    size_t counter = 0;
    struct list *node = list_node_at(list, index);
    if (node)
        return some_int64(node->value);
    return none_int64;
}

// создать перевернутую копию списка
struct list *list_reverse(const struct list *list)
{
    struct list *r_list = 0;
    while (list)
    {
        list_add_front(&r_list, list->value);
        list = list->next;
    }
    return r_list;
}

struct list *list_read()
{

    struct maybe_int64 mb_value = read_int64();
    if (!mb_value.valid)
    {
        return 0;
    }
    struct list *head = node_create(mb_value.value);
    struct list *node = head;

    while (true)
    {
        struct maybe_int64 mb_value = read_int64();
        if (!mb_value.valid)
        {
            return head;
        }
        node->next = node_create(mb_value.value);
        node = node->next;
    }
}
