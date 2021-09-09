# KHAI BÁO DANH SÁCH

## ĐA THỨC

> Đa thức là danh sách đơn thức.

```c
typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct DaThuc
{
    DonThuc A[100];
    int so_luong;
};
```

## Line

> Chuỗi là danh sách các kí tự.

```c
typedef struct
{
    char c[80];
    int p;
} Line;
```

## List

> Danh sách các số thực `float`.

```c
typedef struct
{
    float c[100];
    int p;
} List;
```

## Danh sách sinh viên

> Danh sách sinh viên.

```c
typedef struct
{
    char MSSV[10], hoVaTen[50];
    float LT, TH1, TH2;
} SinhVien;

typedef struct
{
    SinhVien A[40];
    int n;
} List;
```

## Polygon

> Polygon

```c
typedef struct
{
    int x, y;
} Point;

typedef struct
{
    Point c[100];
    int p;
} Polygon;
```
