#include "suite.h"
#include "stack.h"

void st_pop(CuTest * tc)
{
    struct st * stack = st_new(10,sizeof(int));
    for(int i =0; i < 10; i++){
        stack->push(stack,&i);
        printf("push %d\n", i);
    }
    int i;
    while(stack->top != 0) {
        //int top = stack->top;
        stack->pop(stack, &i);
        printf("pop %d\n", i);
        //CuAssertIntEquals(tc,top, *i);
    }
    
    st_delete(stack);
}


int main(void) { return execute(st_pop);}