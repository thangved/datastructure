#include <string.h>
#include <stdio.h>

#ifndef DanhSach
struct SinhVien
{
    char MSSV[10], HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

typedef struct
{
    struct SinhVien A[40];
    int n;
} DanhSach;
#endif