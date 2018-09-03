#ifndef __ST_H
#define __ST_H

struct st {
    void (*push)(struct st* self, void * elem);
    void (*pop)(struct st* self, void * elem);
    void * (*pop_a)(struct st* self);
    int _capacity;
    int _elemsize;
    int top;
    void * _array;
};

struct st * st_new(int capacity, int elemsize);
void st_delete(struct st * self);

#endif