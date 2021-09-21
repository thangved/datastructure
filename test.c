#include <stdio.h>
#include "plistlib.h"

void readList(List *L)
{ // bai 1
    int i, n;
    ElementType X;
    makeNullList(L);
    printf("Nhap so phan tu cua danh sach n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &X);
        insertList(X, endList(*L), L);
    }
}

List dsle(List L)
{
    List L1;
    makeNullList(&L1);
    Position P = first(L);
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 != 0)
        {
            insertList(P->Next->Element, endList(L1), &L1);
            endList(L1);
        }
        P = P->Next;
    }
    return L1;
}
List dschan(List L)
{
    List L2;
    makeNullList(&L2);
    Position P = first(L);

    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 == 0)
        {
            insertList(P->Next->Element, endList(L2), &L2);
            endList(L2);
        }
        P = P->Next;
    }
    return L2;
}
void xoasole(List *L)
{
    Position P = first(*L);
    while (next(P, *L) != NULL)
    {
        if (retrieve(P, *L) % 2 != 0)
        {
            deleteList(P, L);
        }
        else
        {
            P = next(P, *L);
        }
    }
}
int main(int argc, char *argv[])
{
    List L, L1, L2;
    makeNullList(&L);

    readList(&L);
    printList(L);
    printList(dsle(L1));
    printList(dschan(L2));
    return 0;
}