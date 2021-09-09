#include "define.h"

void deleteList(Position p, List *pL)
{
    if (p < 1 || p > pL->Last)
    {
        printf("Vi tri khong hop le\n");
        return;
    }

    for (Position i = p; i < pL->Last; i++)
        pL->Elements[i - 1] = pL->Elements[i];

    pL->Last--;
}