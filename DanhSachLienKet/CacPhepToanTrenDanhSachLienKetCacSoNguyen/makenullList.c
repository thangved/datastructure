#include "define.c"

void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}