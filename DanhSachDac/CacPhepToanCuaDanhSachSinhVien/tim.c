#include "define.h"

int tim(char MSSV[10], DanhSach L)
{
    for (int i = 0; i < L.n; i++)
        if (strcmp(MSSV, L.A[i].MSSV) == 0)
            return i + 1;
    return L.n + 1;
}