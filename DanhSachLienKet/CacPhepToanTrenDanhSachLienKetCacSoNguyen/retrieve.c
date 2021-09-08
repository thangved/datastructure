#include <define.h>

ElementType retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}