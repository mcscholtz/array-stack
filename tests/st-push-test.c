#include "suite.h"
#include "stack.h"

void st_push(CuTest * tc)
{
    struct stack * stack = stack_new(10,sizeof(int));
    for(int i =0; i < 10; i++){
        stack->push(stack,&i);
    }
    CuAssertIntEquals(tc,10, stack->top);
    
    stack_delete(stack);
}


int main(void) { return execute(st_push);}