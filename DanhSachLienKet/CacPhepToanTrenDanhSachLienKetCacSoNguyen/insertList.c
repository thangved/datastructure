#include <define.h>

void insertList(ElementType x, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}