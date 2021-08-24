#include <stdio.h>
struct SinhVien
{
    char MSSV[10], HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

#define maxLength 40

typedef struct SinhVien ElementType;
typedef int Position;

typedef struct
{
    ElementType A[maxLength];
    Position n;
} DanhSach;

DanhSach dsRong()
{
    DanhSach danhSach;
    danhSach.n = 0;
    return danhSach;
}

void chenCuoi(struct SinhVien sinhVien, DanhSach *pDanhSach)
{
    pDanhSach->A[pDanhSach->n] = sinhVien;
    pDanhSach->n++;
}

int tim(char MSSV[10], DanhSach danhSach)
{
    int i;
    for (i = 0; i < danhSach.n; i++)
        if (MSSV == danhSach.A[i].MSSV)
            return i + 1;
    return i + 1;
}

struct SinhVien nhapSV()
{
    struct SinhVien sinhVien;

    fgets(sinhVien.MSSV, 10, stdin);
    fgets(sinhVien.HoTen, 50, stdin);
    scanf("%f", &sinhVien.DiemLT);
    scanf("%f", &sinhVien.DiemTH1);
    scanf("%f", &sinhVien.DiemTH2);

    return sinhVien;
}

DanhSach nhap()
{
    DanhSach danhSach = dsRong();
    struct SinhVien sinhVien;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        sinhVien = nhapSV();
        if (tim(sinhVien.MSSV, danhSach) < 1 || tim(sinhVien.MSSV, danhSach) >= danhSach.n)
        {
            chenCuoi(sinhVien, &danhSach);
        }
    }
    return danhSach;
}