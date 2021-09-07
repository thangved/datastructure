/**
 * @file PDaThucLib.c
 * @author Kim Minh Thắng (https://github.com/thangved)
 * @brief Thư viện danh sách liên kết da thuc
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*__DEFINE__TYPE__*/
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
/*__END__DEFINE__TYPE__*/

/*__FUNCTIONS__DECLARATION__*/
void chenDonThuc(DonThuc x, DaThuc *pD); // chèn đơn thức x vào đa thức chỉ bởi con trỏ pD
DaThuc congDaThuc(DaThuc D1, DaThuc D2); // cong hai da thuc
void daoHam(DonThuc *d);                 // dao ham don thuc
void inDaThuc(DaThuc d);                 // hien thi da thuc
DaThuc khoitao();                        // tra ve da thuc rong
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2); // tra ve tich hai da thuc
DaThuc nhapDaThuc();                     // nhap va tra ve da thuc
DaThuc tinhDaoHam(DaThuc D);             // tinh dao ham cua da thuc
/*__END__FUNCTIONS__DECLARATION__*/

/*__FUNCTIONS__BODY__*/
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
            Position T = (Position)malloc(sizeof(struct Node));
            T->e = x;
            T->Next = P->Next;
            P->Next = T;
            return;
        }
        P = P->Next;
    }
    Position T = (Position)malloc(sizeof(struct Node));
    T->e = x;
    P->Next = T;
}
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
void daoHam(DonThuc *d)
{
    d->he_so = d->he_so * d->bac;
    d->bac--;
}
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
DaThuc khoitao()
{
    DaThuc D = (DaThuc)malloc(sizeof(DaThuc));
    D->Next = NULL;
    return D;
}
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
/*__END__FUNCTIONS__BODY__*/
int main()
{

    DaThuc d = khoitao();
    struct Node *p = d;
    DonThuc s1 = {6.2, 4};
    DonThuc s2 = {4.2, 0};
    DonThuc s3 = {2, 4};
    chenDonThuc(s1, &d);
    chenDonThuc(s2, &d);
    chenDonThuc(s3, &d);
    while (p->Next != NULL)
    {
        DonThuc e = p->Next->e;
        printf("%.3fX^%d ", e.he_so, e.bac);
        p = p->Next;
    }
    return 0;
}
