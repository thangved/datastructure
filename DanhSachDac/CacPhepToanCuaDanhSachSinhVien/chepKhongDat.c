#include "all.h"

float tongDiem(struct SinhVien S)
{
    return S.DiemLT + S.DiemTH1 + S.DiemTH2;
}

DanhSach chepKhongDat(DanhSach L)
{
    DanhSach _L = dsRong();
    for (int i = 0; i < L.n; i++)
        if (tongDiem(L.A[i]) < 4)
            chenCuoi(L.A[i], &_L);
    return _L;
}