/**
 * @file AListLib.c
 * @author Minh Thắng (https://github.com/thangved)
 * @brief Thư viện Danh sách đặc dựa trên tài liệu của Trường Đại học Cần Thơ
 * @version 0.1
 * @date 2021-08-27
 * 
 * @copyright Copyright (c) Minh Thang 2021
 * 
 */

#include <stdio.h>

/*__DEFINE__TYPE__*/
#ifndef MaxLength
#define MaxLength 300 // So phan tu toi da
#endif

#ifndef ElementType
typedef int ElementType; // Kieu du lieu cua phan tu
#endif

#ifndef Position
typedef int Position; // Position = index + 1
#endif

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;
/*__END__DEFINE__TYPE__*/

/* __FUNCTIONS__INTERFACE__ */
void deleteList(Position p, List *pL);
int emptyList(List L);
Position endList(List L);
int fullList(List L);
Position first(List L);
void insertList(ElementType x, Position p, List *pL);
Position locate(ElementType x, List L);
void makenullList(List *pL);
Position next(Position p, List L);
Position previous(Position p, List L);
ElementType retrieve(Position p, List L);
/* __END__FUNCTIONS__INTERFACE__*/

// ham xoa mot phan tu tai vi tri p
void deleteList(Position p, List *pL)
{
    if (p < first(*pL) || p >= endList(*pL))
    {
        printf("Vi tri khong hop le\n");
        return;
    }

    for (Position i = p; i < pL->Last; i++)
        pL->Elements[i - 1] = pL->Elements[i];

    pL->Last--;
}

// ham kiem tra mot ds co rong hay khong
int emptyList(List L)
{
    return L.Last == 0;
}

// ham tra ve vi tri sau vi tri cuoi cung cua List
Position endList(List L)
{
    return L.Last + 1;
}

// ham kiem tra ham co full khong
int fullList(List L)
{
    return L.Last == MaxLength;
}

// ham tra ve vi tri dau tien cua List
Position first(List L)
{
    return 1;
}

// ham chen 1 phan tu vao List
void insertList(ElementType x, Position p, List *pL)
{
    if (fullList(*pL))
        return;

    if (p < first(*pL) || p > endList(*pL) + 1)
        return;

    for (Position i = pL->Last; i >= p; i++)
        pL->Elements[i] = pL->Elements[i - 1];

    pL->Elements[p - 1] = x;
    pL->Last++;
}

// ham tra ve vi tri dau tien cua phan tu x co trong List
Position locate(ElementType x, List L)
{
    for (int i = 1; i <= L.Last; i++)
        if (x == retrieve(i, L))
            return i;
    return L.Last + 1;
}

// lam rong danh sach
void makenullList(List *pL)
{
    pL->Last = 0;
}

// tra ve vi tri sau vi tri p trong List
Position next(Position p, List L)
{
    if (p > L.Last)
        return 0;
    return p + 1;
}

// tra ve vi tri truoc vi tri p trong List
Position previous(Position p, List L)
{
    if (p <= first(L))
        return 0;
    return p - 1;
}

// ham tra ve gia tri cua List tai vi tri p
ElementType retrieve(Position p, List L)
{
    if (!(p > L.Last))
        return L.Elements[p - 1];
    return 0;
}

/* Cac ham khong co trong AListLib*/

#ifdef _USE_ALL
/* __FUNCTIONS__INTERFACE__ */
void copyEvenNumbers(List L1, List *pL2);
int countList(ElementType x, List L);
void difference(List L1, List L2, List *pL);
void erase(ElementType x, List *pL);
float getAvg(List L);
void insertSet(ElementType x, List *pL);
void intersection(List L1, List L2, List *pL);
ElementType minList(List L);
int member(ElementType x, List L);
ElementType maxList(List L);
void normalize(List *pL);
void printList(List L);
void printOddNumbers(List L);
void removeAll(ElementType x, List *pL);
void readList(List *pL);
void readSet(List *pL);
ElementType sumList(List L);
void sort(List *pL);
void unionSet(List L1, List L2, List *pL);
/* __END__FUNCTIONS__INTERFACE__*/

// hàm chép toàn bộ các số chẵn trong danh sách L1 sang danh sách kết quả
void copyEvenNumbers(List L1, List *pL2)
{
    pL2->Last = 0;
    for (int i = 0; i < L1.Last; i++)
        if (L1.Elements[i] % 2 == 0)
        {
            pL2->Elements[pL2->Last] = L1.Elements[i];
            pL2->Last++;
        }
}

// dem x trong List
int countList(ElementType x, List L)
{
    int count = 0;
    for (int i = 0; i < L.Last; i++)
        if (L.Elements[i] == x)
            count++;
    return count;
}

// tim hieu cua hai tap
void difference(List L1, List L2, List *pL)
{
    makenullList(pL);
    for (int i = 0; i < L1.Last; i++)
        if (!member(L1.Elements[i], L2))
            insertSet(L1.Elements[i], pL);
}

// Xóa phần tử đầu tiên có giá trị là x trong danh sách chỉ bởi con trỏ pL
void erase(ElementType x, List *pL)
{
    deleteList(locate(x, *pL), pL);
}

// tra ve gia tri trung binh cua List
float getAvg(List L)
{
    if (L.Last == 0)
        return -10000;
    float sum = 0;
    for (int i = 0; i < L.Last; i++)
        sum += L.Elements[i];
    return (float)sum / L.Last;
}

// them phan tu vao cuoi List
void insertSet(ElementType x, List *pL)
{
    pL->Elements[pL->Last] = x;
    pL->Last++;
}

// ham tim tap giao cua L1 L2
void intersection(List L1, List L2, List *pL)
{
    makenullList(pL);
    for (int i = 0; i < L1.Last; i++)
        if (member(L1.Elements[i], L2))
            insertSet(L1.Elements[i], pL);
}

//  trả về giá trị nhỏ nhất trong các phần tử của danh sách L
ElementType minList(List L)
{
    ElementType min = L.Elements[0];
    for (int i = 0; i < L.Last; i++)
        if (min > L.Elements[i])
            min = L.Elements[i];
    return min;
}

// ham kiem tra 1 phan tu co trong List hay khong
int member(ElementType x, List L)
{
    for (int i = 1; i <= L.Last; i++)
        if (x == retrieve(i, L))
            return 1;
    return 0;
}

//  trả về giá trị lớn nhất trong các phần tử của danh sách L
ElementType maxList(List L)
{
    ElementType max = L.Elements[0];
    for (int i = 0; i < L.Last; i++)
        if (max < L.Elements[i])
            max = L.Elements[i];
    return max;
}

// lam cho List co phan tu duy nhat
void normalize(List *pL)
{
    for (int i = 0; i < pL->Last; i++)
        for (int j = i + 1; j < pL->Last; j++)
            if (pL->Elements[i] == pL->Elements[j])
            {
                deleteList(j, pL);
                j--;
            }
}

// in ra List
void printList(List L)
{
    for (Position p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L));

    printf("\n");
}

// ham in so le
void printOddNumbers(List L)
{
    for (int i = 0; i < L.Last; i++)
        if (!(L.Elements[i] % 2 == 0))
            printf("%d ", L.Elements[i]);
    printf("\n");
}

// xoa tat ca phan tu co gia tri x trong List
void removeAll(ElementType x, List *pL)
{
    while (member(x, *pL))
        deleteList(locate(x, *pL), pL);
}

// ham nhap List tu ban phim
void readList(List *pL)
{
    Position last;
    scanf("%d", &last);
    pL->Last = last;

    for (Position p = 1; p <= pL->Last; p++)
        scanf("%d", &pL->Elements[p - 1]);
}

// ham them n phan tu vao List neu no chua co trong List
void readSet(List *pL)
{
    readList(pL);
    normalize(pL);
}

// trả về tổng giá trị các phần tử trong danh sách L
ElementType sumList(List L)
{
    ElementType sum = 0;
    for (int i = 0; i < L.Last; i++)
        sum += L.Elements[i];
    return sum;
}

// ham sap xep
void sort(List *pL)
{
    for (int i = 0; i < pL->Last; i++)
        for (int j = i + 1; j < pL->Last; j++)
            if (pL->Elements[i] > pL->Elements[j])
            {
                ElementType Temp = pL->Elements[i];
                pL->Elements[i] = pL->Elements[j];
                pL->Elements[j] = Temp;
            }
}

// tap hop cua 2 tap
void unionSet(List L1, List L2, List *pL)
{
    makenullList(pL);
    int i;
    for (i = 0; i < L1.Last; i++)
        insertSet(L1.Elements[i], pL);

    for (i = 0; i < L2.Last; i++)
        if (!member(L2.Elements[i], L1))
            insertSet(L2.Elements[i], pL);
}
#endif
