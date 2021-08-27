// #include "AListLib.c"
// Định nghĩa các hàm nhập, hiển thị và sắp xếp danh sách
// Khai báo và gọi thực thi các hàm trên trong hàm main()

#include "AListLib.c"

/* __FUNCTIONS__INTERFACE__ */
void printList(List L);
void readList(List *pList);
void swap(ElementType array[], int i, int j);
void sort(List *pList);
/* __END__FUNCTIONS__INTERFACE__*/

// in ra List
void printList(List L)
{
    for (Position p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L));

    printf("\n");
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

int main()
{
    List L1;
    readList(&L1);
    printList(L1);
    sort(&L1);
    printList(L1);
    return 0;
}