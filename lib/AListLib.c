/**
 * Thư viện danh sách đặc dựa trên tài liệu của trường Đại học Cần Thơ.
 * ------------------------
 * © 2021 Minh Thắng https://github.com/thangved.
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
void copyEvenNumbers(List list1, List *pList2);
int countList(ElementType x, List list);
void deleteList(Position p, List *pL);
void difference(List list1, List list2, List *pList);
int emptyList(List list);
Position endList(List list);
void erase(ElementType x, List *pList);
int fullList(List list);
Position first(List list);
float getAvg(List list);
void insertList(ElementType x, Position p, List *pL);
void insertSet(ElementType x, List *pList);
void intersection(List list1, List list2, List *pList);
Position locate(ElementType x, List list);
ElementType minList(List list);
void makenullList(List *pL);
int member(ElementType x, List list);
ElementType maxList(List list);
Position next(Position p, List L);
void normalize(List *pList);
Position previous(Position p, List L);
void printList(List L);
void printOddNumbers(List list);
ElementType retrieve(Position p, List list);
void removeAll(ElementType x, List *pList);
void readList(List *pList);
void readSet(List *pList);
ElementType sumList(List list);
void swap(ElementType array[], int i, int j);
void sort(List *pList);
void unionSet(List list1, List list2, List *pList);
/* __END__FUNCTIONS__INTERFACE__*/

// hàm chép toàn bộ các số chẵn trong danh sách L1 sang danh sách kết quả
void copyEvenNumbers(List list1, List *pList2)
{
    pList2->Last = 0;
    for (int i = 0; i < list1.Last; i++)
        if (list1.Elements[i] % 2 == 0)
        {
            pList2->Elements[pList2->Last] = list1.Elements[i];
            pList2->Last++;
        }
}

// dem x trong List
int countList(ElementType x, List list)
{
    int count = 0;
    for (int i = 0; i < list.Last; i++)
        if (list.Elements[i] == x)
            count++;
    return count;
}

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

// tim hieu cua hai tap
void difference(List list1, List list2, List *pList)
{
    makenullList(pList);
    for (int i = 0; i < list1.Last; i++)
        if (!member(list1.Elements[i], list2))
            insertSet(list1.Elements[i], pList);
}

// ham kiem tra mot ds co rong hay khong
int emptyList(List list)
{
    return list.Last == 0;
}

// ham tra ve vi tri sau vi tri cuoi cung cua List
Position endList(List list)
{
    return list.Last + 1;
}

// Xóa phần tử đầu tiên có giá trị là x trong danh sách chỉ bởi con trỏ pL
void erase(ElementType x, List *pList)
{
    deleteList(locate(x, *pList), pList);
}

// ham kiem tra ham co full khong
int fullList(List list)
{
    return list.Last == MaxLength;
}

// ham tra ve vi tri dau tien cua List
Position first(List list)
{
    return 1;
}

// tra ve gia tri trung binh cua List
float getAvg(List list)
{
    if (list.Last == 0)
        return -10000;
    return (float)sumList(list) / list.Last;
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

// them phan tu vao cuoi List
void insertSet(ElementType x, List *pList)
{
    pList->Elements[pList->Last] = x;
    pList->Last++;
}

// ham tim tap giao cua L1 L2
void intersection(List list1, List list2, List *pList)
{
    makenullList(pList);
    for (int i = 0; i < list1.Last; i++)
        if (member(list1.Elements[i], list2))
            insertSet(list1.Elements[i], pList);
}

// ham tra ve vi tri dau tien cua phan tu x co trong List
Position locate(ElementType x, List list)
{
    for (int i = 1; i <= list.Last; i++)
        if (x == retrieve(i, list))
            return i;
    return list.Last + 1;
}

//  trả về giá trị nhỏ nhất trong các phần tử của danh sách L
ElementType minList(List list)
{
    ElementType min = list.Elements[0];
    for (int i = 0; i < list.Last; i++)
        if (min > list.Elements[i])
            min = list.Elements[i];
    return min;
}

// lam rong danh sach
void makenullList(List *pL)
{
    pL->Last = 0;
}

// ham kiem tra 1 phan tu co trong List hay khong
int member(ElementType x, List list)
{
    for (int i = 1; i <= list.Last; i++)
        if (x == retrieve(i, list))
            return 1;
    return 0;
}

//  trả về giá trị lớn nhất trong các phần tử của danh sách L
ElementType maxList(List list)
{
    ElementType max = list.Elements[0];
    for (int i = 0; i < list.Last; i++)
        if (max < list.Elements[i])
            max = list.Elements[i];
    return max;
}

// tra ve vi tri sau vi tri p trong List
Position next(Position p, List L)
{
    if (p > L.Last)
        return 0;
    if (p == L.Last)
        return endList(L);
    return p + 1;
}

// lam cho List co phan tu duy nhat
void normalize(List *pList)
{
    for (int i = 0; i < pList->Last; i++)
        for (int j = i + 1; j < pList->Last; j++)
            if (pList->Elements[i] == pList->Elements[j])
            {
                deleteList(j + 1, pList);
                j--;
            }
}

// tra ve vi tri truoc vi tri p trong List
Position previous(Position p, List L)
{
    if (p <= first(L))
        return 0;
    return p - 1;
}

// in ra List
void printList(List L)
{
    for (Position p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L));

    printf("\n");
}

// ham in so le
void printOddNumbers(List list)
{
    for (int i = 0; i < list.Last; i++)
        if (!(list.Elements[i] % 2 == 0))
            printf("%d ", list.Elements[i]);
    printf("\n");
}

// ham tra ve gia tri cua List tai vi tri p
ElementType retrieve(Position p, List list)
{
    if (!(p > list.Last))
        return list.Elements[p - 1];
    return 0;
}

// xoa tat ca phan tu co gia tri x trong List
void removeAll(ElementType x, List *pList)
{
    if (!member(x, *pList))
        return;
    while (locate(x, *pList) <= pList->Last)
        deleteList(locate(x, *pList), pList);
}

// ham nhap List tu ban phim
void readList(List *pList)
{
    Position last;
    scanf("%d", &last);
    pList->Last = last;

    for (Position p = 1; p <= pList->Last; p++)
        scanf("%d", &pList->Elements[p - 1]);
}

// ham them n phan tu vao List neu no chua co trong List
void readSet(List *pList)
{
    readList(pList);
    normalize(pList);
}

// trả về tổng giá trị các phần tử trong danh sách L
ElementType sumList(List list)
{
    ElementType sum = 0;
    for (int i = 0; i < list.Last; i++)
        sum += list.Elements[i];
    return sum;
}

// ham hoan doi 2 phan tu trong mang
void swap(ElementType array[], int i, int j)
{
    ElementType temp = array[i];

    array[i] = array[j];
    array[j] = temp;
}

// ham sap xep
void sort(List *pList)
{
    for (int i = 0; i < pList->Last; i++)
        for (int j = i + 1; j < pList->Last; j++)
            if (pList->Elements[i] > pList->Elements[j])
                swap(pList->Elements, i, j);
}

// tap hop cua 2 tap
void unionSet(List list1, List list2, List *pList)
{
    makenullList(pList);
    int i;
    for (i = 0; i < list1.Last; i++)
        insertSet(list1.Elements[i], pList);

    for (i = 0; i < list2.Last; i++)
        if (!member(list2.Elements[i], list1))
            insertSet(list2.Elements[i], pList);
}
