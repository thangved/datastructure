#include "define.h"

Position next(Position p, List L)
{
    if (p > L.Last)
        return 0;
    return p + 1;
}