#include "define.h"

void xoaTai(int p, DanhSach *L)
{
    for (int i = p; i < L->n; i++)
        L->A[i - 1] = L->A[i];
    L->n--;
}