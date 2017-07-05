
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>


int stackConstruct(Stack* stack, size_t size)
{
    if(stack == NULL)
        return BADSTACK;

    stack->data = (Type*) calloc(size, sizeof(Type));
    
    if(stack->data == NULL)
        return BADALLOC;

    stack->size = size;
    stack->count = 0;

    return OK;
}

int stackDestruct(Stack* stack)
{
    if(stack == NULL)
        return BADSTACK;

    free(stack->data);
    stack->size = 0;
    stack->count = 0;

    return OK;
}

int stackOk(Stack* stack)
{
    if(stack == NULL)
        return BADSTACK;

    if(stack->data == NULL)
        return BADDATA;

    return OK;
    
}

int stackDump(Stack* stack)
{
    printf("Stack");
    if(stackOk(stack) != OK)
        printf(" (ERROR)  ");
    else
        printf(" (OK)  ");

	printf("[0x%p]\n{\n", stack);

	printf("  data [%lu] = 0x%p\n  {\n", stack->size, stack->data);

	for(int i = 0; i < stack->size; i++)
	{
        if(i < stack->count)
            printf("    [%d] = %lg\n", i, stack->data[i]);
        else
            printf("    [%d] = POISON\n", i);
	}
	printf("  }\n"
	"}\n\n");    
}

int stackResize(Stack* stack)
{
    if(stack == NULL)
        return BADSTACK;
    
    size_t newSize = stack->size * 2;
    Type* data = (Type*) realloc(stack->data, newSize * sizeof(Type));

    if(data == NULL)
        return BADALLOC;

    memcpy(data, stack->data, stack->size * sizeof(Type));

    free(stack->data);
    stack->data = data;
    stack->size = newSize;
    
    return OK;

}

int stackEmpty(Stack* stack)
{
    if(stack == NULL)
        return BADSTACK;

    if(stack->count == 0)
        return 1;
    else
        return 0;
}

int stackPush(Stack *stack, Type value)
{
    if(stack == NULL)
        return BADSTACK;

    if(stack->count == stack->size)
    {
        int error = stackResize(stack);
    
        if(error != OK)
            return OVERFLOW;
    }

    stack->data[stack->count++] = value;
    return OK;
}

Type stackPop(Stack* stack)
{
    if(stack == NULL)
        return BADSTACK;

    if(stackEmpty(stack))
        return UNDERFLOW;

    return stack->data[--stack->count];
}







