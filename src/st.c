#include "st.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void st_push(struct st * self, void * elem);
static void st_pop(struct st * self, void * elem);
static void * st_pop_alloc(struct st * self);

struct st * st_new(int capacity, int elemsize)
{
    struct st * self = malloc(sizeof(struct st));
    assert(self != NULL && "Out of memory");
    self->_elemsize = elemsize;
    self->_capacity = capacity;
    self->_array = malloc(capacity*elemsize);
    assert(self->_array != NULL && "Out of memory");
    self->top = 0;

    self->push = st_push;
    self->pop = st_pop;
    self->pop_a = st_pop_alloc;
    return self;
}

void st_delete(struct st * self)
{
    assert(self != NULL && "The self is NULL");
    assert(self->_array != NULL && "The self has no memory allocated");

    free(self->_array);
    free(self);
}

static void st_push(struct st * self, void * elem)
{
    assert(self->top <= self->_capacity-1);
    int index = (self->top)*self->_elemsize;
    memcpy((char*)self->_array + index,elem, self->_elemsize);
    self->top++;
}

void * st_pop_alloc(struct st * self)
{
    assert(self->top > 0);
    self->top--;
    void * elem = malloc(self->_elemsize);
    assert(elem != NULL && "Out of memory");
    memcpy(elem ,(char*)self->_array + self->top*self->_elemsize , self->_elemsize);
    return elem;
}

void st_pop(struct st * self, void * elem)
{
    assert(self->top > 0);
    self->top--;
    memcpy(elem ,(char*)self->_array + self->top*self->_elemsize , self->_elemsize);
}