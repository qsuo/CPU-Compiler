
#ifndef __STACK_H__
#define __STACK_H__

#include <string.h>

typedef double Type;


enum StackError
{
    OK,
    BADSTACK = -1,
    BADALLOC = 1,
    BADDATA,
    OVERFLOW,
    UNDERFLOW
};

struct Stack
{
    Type *data;
    size_t count;
    size_t size;
};

typedef struct Stack Stack;

int stackConstruct(Stack* stack, size_t size);

int stackDestruct(Stack* stack);

int stackOk(Stack* stack);

int stackDump(Stack* stack);

int stackResize(Stack* stack);

int stackPush(Stack* stack, Type value);

Type stackPop(Stack* stack);

int stackEmpty(Stack* stack);


#endif
