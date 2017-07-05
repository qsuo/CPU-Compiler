#include <stdio.h>
#include "../stack.h"

#define TEST_SIZE 2

int main()
{
    printf("# Testing Stack\n");

    Stack stack;
    stackConstruct(&stack, TEST_SIZE);

    stackDump(&stack);
    
    stackPush(&stack, 10);
    stackPush(&stack, 25);


    stackDump(&stack);

    stackPush(&stack, 30);

    stackDump(&stack);

    Type check = stackPop(&stack);

    stackDump(&stack);

    printf("Poped value = %lg\n", check); 


    return 0;
}
