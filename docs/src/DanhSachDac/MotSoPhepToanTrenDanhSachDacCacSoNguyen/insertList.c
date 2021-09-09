#include "define.h"

void insertList(ElementType x, Position p, List *pL)
{
    if (pL->Last == MaxLength)
        return;

    if (p < 1 || p > pL->Last + 1)
        return;

    for (Position i = pL->Last; i >= p; i++)
        pL->Elements[i] = pL->Elements[i - 1];

    pL->Elements[p - 1] = x;
    pL->Last++;
}