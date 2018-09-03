[![Build Status](https://travis-ci.org/mcscholtz/cst.svg?branch=master)](https://travis-ci.org/mcscholtz/cst)
# A basic stack implemented in C
## Build
```bash
git clone --recurse-submodules https://github.com/mcscholtz/cst.git
cd cll
cmake .
make
ctest
```
## Use in your Code
```c
#include "stack.h"

struct st * stack = st_new(10,sizeof(int)); //Create stack that can hold 10 int values
int somedata = 1;
stack->push(stack, &somedata);
stack->push(stack, &somedata);

int ret;
stack->pop(stack, &ret); //pop the top element into the ret int

int * ret2 = stack->pop_a(list);
assert(ret == *(int *)ret2); 
free(ret2);
```

For more examples look at the [tests](https://github.com/mcscholtz/cst/tree/master/tests/)
