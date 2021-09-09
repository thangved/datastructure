#include "define.h"

Position previous(Position p, List L)
{
    if (p <= 1)
        return 0;
    return p - 1;
}