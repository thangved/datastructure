#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "AStack.c"
#include "CAQueue.c"

int isAb(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    char s[256];
    fgets(s, 255, stdin);
    s[strlen(s) - 1] = '\0';

    Stack S;
    makenullStack(&S);

    Queue Q;
    makenullQueue(&Q);

    // Dua vo ngan xep va hang doi
    for (int i = 0; i < strlen(s); i++)
        if (isAb(s[i]))
        {
            push(tolower(s[i]), &S);
            enQueue(tolower(s[i]), &Q);
        }

    // Kiem tra
    while (!emptyQueue(Q))
    {
        if (top(S) != front(Q))
        {
            printf("\"%s\" doc xuoi khac doc nguoc\n", s);
            return 0;
        }
        deQueue(&Q);
        pop(&S);
    }

    printf("\"%s\" doc xuoi va doc nguoc nhu nhau\n", s);

    return 0;
}
