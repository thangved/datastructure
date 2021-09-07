#include "define.c"

void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(List));
    (*pL)->Next = NULL;
}