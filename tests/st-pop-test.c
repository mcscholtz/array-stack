#include "suite.h"
#include "stack.h"

void st_pop(CuTest * tc)
{
    struct stack * stack = stack_new(10,sizeof(int));
    for(int i =0; i < 10; i++){
        stack->push(stack,&i);
    }
    int i;
    while(stack->top != 0) {
        stack->pop(stack, &i);
    }
    CuAssertIntEquals(tc, 0, stack->top);
    stack_delete(stack);
}


int main(void) { return execute(st_pop);}