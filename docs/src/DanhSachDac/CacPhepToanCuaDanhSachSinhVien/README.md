# CÁC PHÉP TOÁN TRÊN DANH SÁCH SINH VIÊN

## CÀI ĐẶT

### CẤU TRÚC SINH VIÊN

> Cấu trúc `struct SinhVien` gồm các trường:
>
> - `char` *MSSV, HoTen*: Lưu trữ mã số sinh viên và Họ tên sinh viên;
>
> - `float` *DiemLT, DiemTH1, DiemTH2*: Lưu trữ điểm lý thuyết, thực hành 1 và 2.

```c
struct SinhVien
{
    char MSSV[10], HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
```

### DANH SÁCH SINH VIÊN

```c
typedef struct
{
    SinhVien A[40];
    int n;
} DanhSach;
```

## CÁC PHÉP TOÁN

### dsRong

> Trả về một danh sách rỗng.

```c
DanhSach dsRong()
{
    DanhSach D;
    D.n = 0;
    return D;
}
```

### chenCuoi

> Thêm một sinh viên vào cuối danh sách.

```c
void chenCuoi(struct SinhVien S, DanhSach *L)
{
    L->A[L->n] = S;
    L->n++;
}
```

### tim

> Trả về vị trí xuất hiện đầu tiên của sinh viên.

```c
int tim(char MSSV[10], DanhSach L)
{
    for (int i = 0; i < L.n; i++)
        if (strcmp(MSSV, L.A[i].MSSV) == 0)
            return i + 1;
    return L.n + 1;
}
```

### xoaTai

> Xóa sinh viên tại vị trí `p`.

```c
void xoaTai(int p, DanhSach *L)
{
    for (int i = p; i < L->n; i++)
        L->A[i - 1] = L->A[i];
    L->n--;
}
```

### hienthi

> Hiển thị thông tin các sinh viên trong danh sách.

```c
void hienthi(DanhSach danhSach)
{
    for (int i = 0; i < danhSach.n; i++)
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", danhSach.A[i].MSSV, danhSach.A[i].HoTen, danhSach.A[i].DiemLT, danhSach.A[i].DiemTH1, danhSach.A[i].DiemTH2, danhSach.A[i].DiemLT + danhSach.A[i].DiemTH1 + danhSach.A[i].DiemTH2);
}
```

### nhap

> Nhập danh sách sinh viên từ bàn phím.

```c
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
```

### chepKhongDat

> Trả về danh sách sinh viên có tổng điểm **<4**

```c
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
```

### xoaSinhVien

> Xóa một sinh viên bằng cách truyền vào `MSSV`

```c
void xoaSinhVien(char MSSV[10], DanhSach *pL)
{
    while (tim(MSSV, *pL) <= pL->n)
        xoaTai(tim(MSSV, *pL), pL);
}
```
