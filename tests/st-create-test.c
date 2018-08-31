#include "suite.h"
#include "stack.h"

void st_create(CuTest * tc)
{
    struct st * stack = st_new(5,sizeof(int));
    CuAssertIntEquals(tc, 0, stack->top);
    CuAssertIntEquals(tc, sizeof(int), stack->elemsize);
    CuAssertIntEquals(tc, 5, stack->capacity);
    
    st_delete(stack);
}


int main(void) { return execute(st_create);}