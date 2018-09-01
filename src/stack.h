#ifndef __SOURCE_H
#define __SOURCE_H

struct st {
    void (*push)(struct st* stack, void * elem);
    void (*pop)(struct st* stack, void * elem);
    void * (*pop_a)(struct st* stack);
    int _capacity;
    int _elemsize;
    int top;
    void * _array;
};

struct st * st_new(int capacity, int elemsize);
void st_delete(struct st * stack);

#endif