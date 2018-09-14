#ifndef __STACK_H
#define __STACK_H

struct stack {
    void (*push)(struct stack* self, void * elem);
    void (*pop)(struct stack* self, void * elem);
    int _capacity;
    int _elemsize;
    int top;
    void * _array;
};

struct stack * stack_new(int capacity, int elemsize);
void stack_delete(struct stack * self);

#endif