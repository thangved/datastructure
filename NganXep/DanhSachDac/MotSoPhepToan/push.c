#include "define.h"
#include "fullStack.c"

void push(ElementType x, Stack *pS)
{
    if (fullStack(*pS))
    {
        printf("Loi! Ngan xep day");
        return;
    }
    pS->Top_idx--;
    pS->Elements[pS->Top_idx] = x;
}