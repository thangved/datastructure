/**
 * @file SVLib.c
 * @author Minh Thắng (https://github.com/thangved)
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) Minh Thắng 2021
 * 
 */

#include <stdio.h>
#include <string.h>

/*__DEFINE__TYPE__*/
#ifndef MaxLength
#define MaxLength 40 // So luong phan tu toi da
#endif

#ifndef Position
typedef int Position; //Position <=> index + 1
#endif

struct SinhVien
{
    char MSSV[10], HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};

typedef struct SinhVien ElementType;

typedef struct
{
    ElementType A[MaxLength];
    Position n;
} DanhSach;
/*__END__DEFINE__TYPE__*/

/*__FUNCTIONS__INTERFACE__*/
void chenCuoi(struct SinhVien sinhVien, DanhSach *pDanhSach);
int checkDat(struct SinhVien sinhVien);
DanhSach chepKhongDat(DanhSach iDanhSach);
DanhSach dsRong();
void hienThiSinhVien(struct SinhVien sinhVien);
void hienthiDat(DanhSach danhSach);
void hienthi(DanhSach danhSach);
int ktRong(DanhSach danhSach);
ElementType nhapSV();
DanhSach nhap();
int tim(char *MSSV, DanhSach danhSach);
float tongDiem(struct SinhVien sinhVien);
void xoaTai(int p, DanhSach *pDanhSach);
void xoaSinhVien(char *MSSV, DanhSach *pDanhSach);
/*__END__FUNCTIONS__INTERFACE__*/

// chen them 1 SinhVien vao cuoi DanhSach
void chenCuoi(struct SinhVien sinhVien, DanhSach *pDanhSach)
{
    if (pDanhSach->n >= 40)
    {
        printf("Loi! Danh sach day!");
        return;
    }
    pDanhSach->A[pDanhSach->n] = sinhVien;
    pDanhSach->n++;
}

// kiem tra diem cua SinhVien co dat hay khong (>= 4.0)
int checkDat(struct SinhVien sinhVien)
{
    float tongDiem = sinhVien.DiemLT + sinhVien.DiemTH1 + sinhVien.DiemTH2;

    return tongDiem >= 4;
}

// tra ve DanhSach SinhVien co tongDiem Chua Dat
DanhSach chepKhongDat(DanhSach iDanhSach)
{
    DanhSach oDanhSach = dsRong();

    for (int i = 0; i < iDanhSach.n; i++)
        if (!checkDat(iDanhSach.A[i]))
            chenCuoi(iDanhSach.A[i], &oDanhSach);

    return oDanhSach;
}

// tra ve DanhSach rong
DanhSach dsRong()
{
    DanhSach danhSach;
    danhSach.n = 0;
    return danhSach;
}

// hien thi thong tin cua mot SinhVien
void hienThiSinhVien(struct SinhVien sinhVien)
{
    printf("%s - ", sinhVien.MSSV);
    printf("%s - ", sinhVien.HoTen);

    printf("%.2f - ", sinhVien.DiemLT);
    printf("%.2f - ", sinhVien.DiemTH1);
    printf("%.2f - ", sinhVien.DiemTH2);
    printf("%.2f\n", tongDiem(sinhVien));
}

// hien thi tat ca SinhVien co tong diem >= 4.0
void hienthiDat(DanhSach danhSach)
{
    for (int i = 0; i < danhSach.n; i++)
        if (tongDiem(danhSach.A[i]) >= 4)
            hienThiSinhVien(danhSach.A[i]);
}

// hien thi 1 DanhSach
void hienthi(DanhSach danhSach)
{
    for (int i = 0; i < danhSach.n; i++)
        hienThiSinhVien(danhSach.A[i]);
}

// kiem tra su rong cua DanhSach
int ktRong(DanhSach danhSach)
{
    return danhSach.n == 0;
}

// nhap thong tin va tra ve 1 SinhVien
ElementType nhapSV()
{
    struct SinhVien sinhVien;

    getchar();
    fgets(sinhVien.MSSV, 10, stdin);
    sinhVien.MSSV[strlen(sinhVien.MSSV) - 1] = '\0';
    fflush(stdin);

    fgets(sinhVien.HoTen, 50, stdin);
    sinhVien.HoTen[strlen(sinhVien.HoTen) - 1] = '\0';
    fflush(stdin);

    scanf("%f", &sinhVien.DiemLT);
    scanf("%f", &sinhVien.DiemTH1);
    scanf("%f", &sinhVien.DiemTH2);

    return sinhVien;
}

// tra ve DanhSach n SinhVien
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

// tim vi tri SinhVien theo MSSV
int tim(char *MSSV, DanhSach danhSach)
{
    int i;
    for (i = 0; i < danhSach.n; i++)
        if (strcmp(MSSV, danhSach.A[i].MSSV) == 0)
            return i + 1;
    return i + 1;
}

// tra ve tong diem
float tongDiem(struct SinhVien sinhVien)
{
    return sinhVien.DiemLT + sinhVien.DiemTH1 + sinhVien.DiemTH2;
}

// xoa 1 SinhVien tai vi tri p trong DanhSach
void xoaTai(int p, DanhSach *pDanhSach)
{
    for (int i = p - 1; i < pDanhSach->n; i++)
        pDanhSach->A[i] = pDanhSach->A[i + 1];

    pDanhSach->n--;
}

// xoa SinhVien theo MSSV
void xoaSinhVien(char *MSSV, DanhSach *pDanhSach)
{
    xoaTai(tim(MSSV, *pDanhSach), pDanhSach);
}
