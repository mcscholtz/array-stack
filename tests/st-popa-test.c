#include "suite.h"
#include "st.h"

void st_popa(CuTest * tc)
{
    struct st * stack = st_new(10,sizeof(int));
    for(int i =0; i < 10; i++){
        stack->push(stack,&i);
    }

    while(stack->top != 0) {
        int * i = stack->pop_a(stack);
        free(i);
    }

    CuAssertIntEquals(tc, 0, stack->top);

    st_delete(stack);
}


int main(void) { return execute(st_popa);}