#include "define.h"

Position locate(ElementType x, List L)
{
    for (int i = 0; i <= L.Last; i++)
        if (x == L.Elements[i])
            return i + 1;
    return L.Last + 1;
}