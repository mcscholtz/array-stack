#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void stack_push(struct stack * self, void * elem);
static void stack_pop(struct stack * self, void * elem);
static void * stack_pop_alloc(struct stack * self);

struct stack * stack_new(int capacity, int elemsize)
{
    struct stack * self = malloc(sizeof(struct stack));
    assert(self != NULL && "Out of memory");
    self->_elemsize = elemsize;
    self->_capacity = capacity;
    self->_array = malloc(capacity*elemsize);
    assert(self->_array != NULL && "Out of memory");
    self->top = 0;

    self->push = stack_push;
    self->pop = stack_pop;
    return self;
}

void stack_delete(struct stack * self)
{
    assert(self != NULL && "The self is NULL");
    assert(self->_array != NULL && "The self has no memory allocated");

    free(self->_array);
    free(self);
}

static void stack_push(struct stack * self, void * elem)
{
    assert(self->top <= self->_capacity-1);
    int index = (self->top)*self->_elemsize;
    memcpy((char*)self->_array + index,elem, self->_elemsize);
    self->top++;
}

void stack_pop(struct stack * self, void * elem)
{
    assert(self->top > 0);
    self->top--;
    memcpy(elem ,(char*)self->_array + self->top*self->_elemsize , self->_elemsize);
}