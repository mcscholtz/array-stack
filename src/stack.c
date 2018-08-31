#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void st_push(struct st * stack, void * elem);
static void st_pop(struct st * stack, void * elem);
static void * st_pop_alloc(struct st * stack);

struct st * st_new(int capacity, int elemsize)
{
    struct st * stack = malloc(sizeof(struct st));
    assert(stack != NULL && "Out of memory");
    stack->elemsize = elemsize;
    stack->capacity = capacity;
    stack->array = malloc(capacity*elemsize);
    assert(stack->array != NULL && "Out of memory");
    stack->top = 0;

    stack->push = st_push;
    stack->pop = st_pop;
    stack->pop_a = st_pop_alloc;
    return stack;
}

void st_delete(struct st * stack)
{
    assert(stack != NULL && "The stack is NULL");
    assert(stack->array != NULL && "The stack has no memory allocated");

    free(stack->array);
    free(stack);
}

static void st_push(struct st * stack, void * elem)
{
    assert(stack->top <= stack->capacity-1);
    int index = (stack->top)*stack->elemsize;
    memcpy(stack->array + index,elem, stack->elemsize);
    stack->top++;
}

void * st_pop_alloc(struct st * stack)
{
    assert(stack->top > 0);
    stack->top--;
    void * elem = malloc(stack->elemsize);
    assert(elem != NULL && "Out of memory");
    memcpy(elem ,stack->array + stack->top*stack->elemsize , stack->elemsize);
    return elem;
}

void st_pop(struct st * stack, void * elem)
{
    assert(stack->top > 0);
    stack->top--;
    memcpy(elem ,stack->array + stack->top*stack->elemsize , stack->elemsize);
}