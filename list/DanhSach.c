#include <stdio.h>
struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
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

void hienthi(DanhSach danhSach)
{
    for (int i = 0; i < danhSach.n; i++)
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", danhSach.A[i].MSSV, danhSach.A[i].HoTen, danhSach.A[i].DiemLT, danhSach.A[i].DiemTH1, danhSach.A[i].DiemTH2, danhSach.A[i].DiemLT + danhSach.A[i].DiemTH1 + danhSach.A[i].DiemTH2);
}
