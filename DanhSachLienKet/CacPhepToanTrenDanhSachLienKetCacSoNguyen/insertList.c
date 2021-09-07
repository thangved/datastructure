#include "define.c"

void insertList(ElementType x, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(Position));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}