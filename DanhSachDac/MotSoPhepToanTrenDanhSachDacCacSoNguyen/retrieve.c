#include "define.h"

ElementType retrieve(Position p, List L)
{
    if (!(p > L.Last))
        return L.Elements[p - 1];
    return 0;
}