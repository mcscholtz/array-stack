#include "suite.h"
#include "stack.h"

void st_push_pop(CuTest * tc)
{
    struct st * stack = st_new(100,sizeof(int));
    int j;
    for(int i =0; i < 100; i++){
        stack->push(stack,&i);
    }
    
    while(stack->top != 50) {
        stack->pop(stack, &j);
    }

    for(int i =0; i < 50; i++){
        stack->push(stack,&i);
    }

    while(stack->top != 0) {
        stack->pop(stack, &j);
    }
    CuAssertIntEquals(tc, 0, stack->top);
    st_delete(stack);
}


int main(void) { return execute(st_push_pop);}