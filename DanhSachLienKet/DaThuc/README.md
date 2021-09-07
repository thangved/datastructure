# ĐA THỨC

## KHAI BÁO KIỂU DỮ LIỆU

```c
typedef struct
{
    double he_so;
    int bac;
} DonThuc;
struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;
```

## MỘT SỐ PHÉP TOÁN

> Do hàm viết bằng tên tiếng Việt (hơn hết là vì tôi lười) nên sẽ không chú thích

### chenDonThuc

```c
void chenDonThuc(DonThuc x, DaThuc *pD)
{
    Position P = *pD;
    while (P->Next != NULL)
    {
        if (P->Next->e.bac == x.bac)
        {
            P->Next->e.he_so = P->Next->e.he_so + x.he_so;
            return;
        }
        if (P->Next->e.bac < x.bac)
        {
            Position T = (Position)malloc(sizeof(Position));
            T->e = x;
            T->Next = P->Next;
            P->Next = T;
            return;
        }
        P = P->Next;
    }
    Position T = (Position)malloc(sizeof(Position));
    T->e = x;
    P->Next = T;
}
```

### congDaThuc

```c
DaThuc congDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc D = khoitao();
    Position P = D1;
    while (P->Next != NULL)
    {
        chenDonThuc(P->Next->e, &D);
        P = P->Next;
    }
    P = D2;
    while (P->Next != NULL)
    {
        chenDonThuc(P->Next->e, &D);
        P = P->Next;
    }
    return D;
}
```

### daoHam

```c
void daoHam(DonThuc *d)
{
    d->he_so = d->he_so * d->bac;
    d->bac--;
}
```

### inDaThuc

```c
void inDaThuc(DaThuc d)
{
    DaThuc P = d;
    while (P->Next != NULL)
    {
        printf("%.3fX^%d", P->Next->e.he_so, P->Next->e.bac);
        if (P->Next->Next != NULL)
            printf(" + ");
        P = P->Next;
    }
    printf("\n");
}
```

### khoitao

```c
DaThuc khoitao()
{
    DaThuc D = (DaThuc)malloc(sizeof(DaThuc));
    D->Next = NULL;
    return D;
}
```

### nhanDaThuc

```c
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc P = D1, Q;
    DaThuc Result = khoitao();
    DonThuc E;
    while (P->Next != NULL)
    {
        Q = D2;
        while (Q->Next != NULL)
        {
            E.he_so = P->Next->e.he_so * Q->Next->e.he_so;
            E.bac = P->Next->e.bac + Q->Next->e.bac;
            chenDonThuc(E, &Result);
            Q = Q->Next;
        }
        P = P->Next;
    }
    return Result;
}
```

### nhapDaThuc

```c
DaThuc nhapDaThuc()
{
    int n;
    double hs;
    int bac;
    DonThuc d;
    DaThuc D = khoitao();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %d", &hs, &bac);
        d.he_so = hs;
        d.bac = bac;
        chenDonThuc(d, &D);
    }
    return D;
}
```

### tinhDaoHam

```c
DaThuc tinhDaoHam(DaThuc D)
{
    DaThuc P = D;
    while (P->Next != NULL)
    {
        daoHam(&P->Next->e);
        P = P->Next;
    }
    return D;
}
```
