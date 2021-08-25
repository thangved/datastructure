#include <stdio.h>
#include <string.h>

// --- DanhSach ---

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

// --- end DanhSach ---

DanhSach dsRong()
{
    DanhSach danhSach;
    danhSach.n = 0;
    return danhSach;
}

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

int tim(char *MSSV, DanhSach danhSach)
{
    int i;
    for (i = 0; i < danhSach.n; i++)
        if (strcmp(MSSV, danhSach.A[i].MSSV) == 0)
            return i + 1;
    return i + 1;
}

void xoaTai(int p, DanhSach *pDanhSach)
{
    for (int i = p - 1; i < pDanhSach->n; i++)
        pDanhSach->A[i] = pDanhSach->A[i + 1];

    pDanhSach->n --;
}

int ktRong(DanhSach danhSach)
{
    return danhSach.n == 0;
}

// --- nhap() ---
int length(char *string)
{
    int i = 0;
    while (string[i])
        i++;
    return i;
}

struct SinhVien nhapSV()
{
    struct SinhVien sinhVien;

    getchar();
    fgets(sinhVien.MSSV, 10, stdin);
    sinhVien.MSSV[length(sinhVien.MSSV) - 1] = '\0';
    fflush(stdin);

    fgets(sinhVien.HoTen, 50, stdin);
    sinhVien.HoTen[length(sinhVien.HoTen) - 1] = '\0';
    fflush(stdin);

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

// --- end nhap() ---

// --- chepKhongDat() ---

int checkDat(struct SinhVien sinhVien)
{
    float tongDiem = sinhVien.DiemLT + sinhVien.DiemTH1 + sinhVien.DiemTH2;

    return tongDiem >= 4;
}

DanhSach chepKhongDat(DanhSach iDanhSach)
{
    DanhSach oDanhSach = dsRong();

    for (int i = 0; i < iDanhSach.n; i++)
        if (!checkDat(iDanhSach.A[i]))
            chenCuoi(iDanhSach.A[i], &oDanhSach);

    return oDanhSach;
}

// --- chepKhongDat() ---

// --- xoaSinhVien() ---

void xoaSinhVien(char *MSSV, DanhSach *pDanhSach)
{
    xoaTai(tim(MSSV, *pDanhSach), pDanhSach);
}

// --- end xoaSinhVien() ---

// --- hienthiDat() ---

float tongDiem(struct SinhVien sinhVien)
{
    return sinhVien.DiemLT + sinhVien.DiemTH1 + sinhVien.DiemTH2;
}

void hienThiSinhVien(struct SinhVien sinhVien)
{
    printf("%s - ", sinhVien.MSSV);
    printf("%s - ", sinhVien.HoTen);

    printf("%.2f - ", sinhVien.DiemLT);
    printf("%.2f - ", sinhVien.DiemTH1);
    printf("%.2f - ", sinhVien.DiemTH2);
    printf("%.2f\n", tongDiem(sinhVien));
}

void hienthiDat(DanhSach danhSach)
{
    for (int i = 0; i < danhSach.n; i++)
        if (tongDiem(danhSach.A[i]) >= 4)
            hienThiSinhVien(danhSach.A[i]);
}

// --- end hienthiDat() ---

// --- hienthi() ---

void hienthi(DanhSach danhSach){
    for(int i = 0; i < danhSach.n; i ++)
    hienThiSinhVien(danhSach.A[i]);
}

// --- end hienthi() ---

int main()
{
    DanhSach L;
    int i;

    L = nhap();
    for (i = 0; i <= L.n - 1; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
    return 0;
}
