#include <define.h>
#include "emptyStack.c"

ElementType top(Stack S)
{
    if (!emptyStack(S))
        return S.Elements[S.Top_idx];
    printf("Loi! Ngan xep rong");
    return NULL;
}