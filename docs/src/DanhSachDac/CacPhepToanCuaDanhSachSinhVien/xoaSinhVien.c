#include "all.h"

void xoaSinhVien(char MSSV[10], DanhSach *pL)
{
    while (tim(MSSV, *pL) <= pL->n)
        xoaTai(tim(MSSV, *pL), pL);
}