/**
 * @file PListLib.c
 * @author Kim Minh Thắng (https://github.com/thangved)
 * @brief Thư viện danh sách liên kết
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>

/*__DEFINE__TYPE__*/
typedef int ElementType; // kieu cua phan tu du lieu

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position; // kieu vi tri
typedef Position List;
/*__END__DEFINE__TYPE__*/

/*__FUNCTION__DECLARATION__*/
void deleteList(Position P, List *pL);                // xoa phan tu sau vi tri P
int emptyList(List L);                                //  kiem tra danh sach co rong hay khong
Position first(List L);                               // tra ve vi tri dau tien
Position endList(List L);                             // tra ve vi tri phan tu cuoi cung
void insertList(ElementType X, Position P, List *pL); // chen them mot phan tu
Position locate(ElementType x, List L);               // tra ve vi tri phan tu dau tien co gia tri X
Position myLocate(ElementType x, int i, List L);      // tra ve phan tu x thu i
void makenullList(List *pL);                          // khoi tao danh sach rong
Position next(Position P, List L);                    // tra ve vi tri tiep theo
Position previous(Position P, List L);                // tra ve vi tri truoc P
ElementType retrieve(Position P, List L);             // tra ve gia tri phan tu
/*__END__FUNCTION__DECLARATION__*/

/*__FUNCTION__*/
void deleteList(Position P, List *pL)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}
int emptyList(List L)
{
    return L->Next == NULL;
}
Position endList(List L)
{
    Position P = L;
    while (1)
    {
        if (P->Next == NULL)
            return P;
        P = P->Next;
    }
}
Position first(List L)
{
    return L;
}
void insertList(ElementType x, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}
Position locate(ElementType x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return P;
        P = P->Next;
    }
    return P;
}
void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}
Position myLocate(ElementType x, int i, List L)
{
    Position P = L;
    int count = 0;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            count++;
        if (count == i)
            return P->Next;
        P = P->Next;
    }
    return P->Next;
}
Position next(Position P, List L)
{
    return P->Next;
}
Position previous(Position P, List L)
{
    Position Q = L;
    while (Q->Next->Next != NULL)
    {
        if (Q->Next->Next == P)
            Q = Q->Next;
    }
    return Q->Next;
}
ElementType retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}
/*__END__FUNCTION__*/
#define USE_ALL 1
#ifdef USE_ALL
/*__OTHER__FUNCTION__*/
/*__DECLARATION__*/
void addFirst(ElementType x, List *pL);  // them phan tu vao vi tri dau tien
void append(ElementType x, List *pL);    // them phan tu vao cuoi ds
void copyEvenNumbers(List L, List *pL);  // sao chep so le tu L qua pL
void deleteX(ElementType x, List *pL);   // xoa phan tu x
List difference(List L1, List L2);       // tra ve tap hieu cua L1 L2
void erase(ElementType x, List *pL);     // xoa phan tu x dau tien
float getAvg(List L);                    // tra ve trung binh cong
List intersection(List L1, List L2);     // tra ve tap giao cua L1 L2
int member(ElementType x, List L);       // kiem tra phan tu co trong L
void normalize(List *pL);                // bien danh sach thanh tap hop
void printList(List L);                  // hien thi danh sach phan tu
void printOddNumbers(List L);            // in so le
List readSet();                          // nhap tap hop
void removeAll(ElementType x, List *pL); // xoa tat ca phan tu x
void readList(List *pL);                 // nhap danh sach tu ban phim
void sort(List *pL);                     // sap xep danh sach
List unionSet(List L1, List L2);         // tinh tap hop cua 2 ds
/*__END__DECLARATION__*/

/*__FUNCTION__BODY__*/
void addFirst(ElementType x, List *pL)
{
    insertList(x, first(*pL), pL);
}
void append(ElementType x, List *pL)
{
    if (!member(x, *pL))
        insertList(x, endList(*pL), pL);
}
void copyEvenNumbers(List L, List *pL)
{
    makenullList(pL);
    Position P = first(L);
    Position End = endList(L);
    while (P != End)
    {
        if (retrieve(P, L) % 2 == 0)
            append(retrieve(P, L), pL);
        else
            P = next(P, L);
    }
}
void deleteX(ElementType x, List *pL)
{
    while (locate(x, *pL) != endList(*pL))
    {
        deleteList(locate(x, *pL), pL);
    }
}
List difference(List L1, List L2)
{
    List L;
    Position P = first(L1);
    Position EL1 = endList(L1);
    Position EL2 = endList(L2);
    while (P != EL1)
    {
        if (locate(retrieve(P, L1), L2) != EL2)
            append(retrieve(P, L1), &L);
        P = next(P, L1);
    }
}
void erase(ElementType x, List *pL)
{
    if (locate(x, *pL) != endList(*pL))
        deleteList(locate(x, *pL), pL);
}
float getAvg(List L)
{
    float sum = 0;
    int length = 0;
    Position P = first(L);
    Position E = endList(L);
    while (P != E)
    {
        sum += retrieve(P, L);
        P = next(P, L);
        length++;
    }
    return sum / length;
}
List intersection(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P2 = first(L2);
    Position E2 = endList(L2);
    while (P2 != E2)
    {
        if (member(retrieve(P2, L2), L1))
            if (!member(retrieve(P2, L2), L))
                addFirst(retrieve(P2, L2), &L);
        P2 = next(P2, L2);
    }
    return L;
}
int member(ElementType x, List L)
{
    return locate(x, L) != endList(L);
}
void normalize(List *pL)
{
    Position P = *pL, Q;
    while (P->Next != NULL)
    {
        Q = P->Next;
        while (Q->Next != NULL)
        {
            if (P->Next->Element == Q->Next->Element)
            {
                deleteList(Q, pL);
            }
            else
            {
                Q = Q->Next;
            }
        }
        P = P->Next;
    }
}
void printList(List L)
{
    Position P = first(L);
    Position E = endList(L);
    while (P != E)
    {
        printf("%d ", retrieve(P, L));
        P = next(P, L);
    }
    printf("\n");
}
void printOddNumbers(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 != 0)
            printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}
List readSet()
{
    List L;
    makenullList(&L);
    int n;
    ElementType e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        if (member(e, L))
            continue;
        addFirst(e, &L);
    }

    return L;
}
void removeAll(ElementType x, List *pL)
{
    while (locate(x, *pL)->Next != NULL)
        deleteList(locate(x, *pL), pL);
}
void readList(List *pL)
{
    makenullList(pL);
    int n;
    scanf("%d", &n);
    ElementType e;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        insertList(e, endList(*pL), pL);
    }
}
void sort(List *pL)
{
    Position P = *pL,
             N;
    while (P->Next != NULL)
    {
        N = P->Next;
        while (N->Next != NULL)
        {
            if (P->Next->Element > N->Next->Element)
            {
                ElementType Temp = P->Next->Element;
                P->Next->Element = N->Next->Element;
                N->Next->Element = Temp;
            }
            N = N->Next;
        }
        P = P->Next;
    }
}
List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P1 = first(L1),
             P2 = first(L2),
             E1 = endList(L1),
             E2 = endList(L2);
    while (P1 != E1)
    {
        insertList(retrieve(P1, L1), endList(L), &L);
        P1 = next(P1, L1);
    }

    while (P2 != E2)
    {
        if (!member(retrieve(P2, L2), L))
            insertList(retrieve(P2, L2), endList(L), &L);
        P2 = next(P2, L2);
    }

    return L;
}
/*__END__FUNCTION__BODY__*/
/*__END__OTHER__FUNCTION__*/
#endif
