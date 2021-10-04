#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PQueue.c"

int main()
{
    char hash[512];
    char key[100];

    fgets(hash, 511, stdin);
    fflush(stdin);
    fgets(key, 99, stdin);
    fflush(stdin);

    hash[strlen(hash) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    Queue Q;
    makenullQueue(&Q);
    for (int i = 0; i < strlen(key); i++)
        enQueue(key[i] - 48, &Q);

    for (int i = 0; i < strlen(hash); i++)
    {
        printf("%c", hash[i] - front(Q));
        enQueue(front(Q), &Q);
        deQueue(&Q);
    }

    return 0;
}