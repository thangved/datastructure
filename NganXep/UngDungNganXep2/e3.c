#include <stdio.h>
#include "Stack.h"

void inThaplucphan(int n)
{
    char Hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    Stack S;
    makenullStack(&S);

    while (n != 0)
    {
        push(Hex[n % 16], &S);
        n /= 16;
    }

    while (!emptyStack(S))
    {
        printf("%c", top(S));
        pop(&S);
    }
    printf("\n");
}

int main()
{
    inThaplucphan(101);
}
