#include <define.h>

void pop(Stack *pS)
{
    if (pS->Top_idx == MaxLength)
        pS->Top_idx--;
    printf("Loi! Ngan xep rong");
}