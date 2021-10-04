#include <stdio.h>
#include <string.h>
#include "Stack.h"

int ktChuoi()
{
    // nhap chuoi
    char chuoi[256];
    fgets(chuoi, 255, stdin);
    chuoi[strlen(chuoi) - 1] = '\0';

    // tao ngan xep
    Stack S;
    makenullStack(&S);

    // xet tung ki tu
    for (int i = 0; i < strlen(chuoi); i++)
    {
        if (chuoi[i] == '(')
            push('(', &S);
        else if (chuoi[i] == ')')
        {
            if (emptyStack(S))
                return 0;
            else
                pop(&S);
        }
    }
    return emptyStack(S);
}

int main()
{
    if (ktChuoi())
    {
        printf("Chuoi ngoac dung");
    }
    else
    {
        printf("Chuoi ngoac khong dung");
    }
    return 0;
}