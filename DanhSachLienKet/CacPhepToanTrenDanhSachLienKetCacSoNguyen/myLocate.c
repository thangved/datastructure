#include <define.h>

Position myLocate(ElementType x, int i, List L)
{
    Position P = L;
    int count = 0;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            count++;
        if (count == i)
            return P->Next;
        P = P->Next;
    }
    return P->Next;
}