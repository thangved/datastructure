#include "define.c"

Position endList(List L)
{
    Position P = L;
    while (1)
    {
        if (P->Next == NULL)
            return P;
        P = P->Next;
    }
}