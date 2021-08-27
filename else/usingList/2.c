// Khai báo sử dụng thư viện AListLib.c
// Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
// Định nghĩa hàm chép các số chẵn sang danh sách kết quả
// Khai báo biến và gọi thực thi các hàm trên trong hàm main() đáp ứng yêu cầu đặt ra.

#include "AListLib.c"

/* __FUNCTIONS__INTERFACE__ */
void copyEvenNumbers(List list1, List *pList2);
float getAvg(List list);
void printList(List L);
void readList(List *pList);
ElementType sumList(List list);
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

// tra ve gia tri trung binh cua List
float getAvg(List list)
{
    if (list.Last == 0)
        return -10000;
    return (float)sumList(list) / list.Last;
}

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

// trả về tổng giá trị các phần tử trong danh sách L
ElementType sumList(List list)
{
    ElementType sum = 0;
    for (int i = 0; i < list.Last; i++)
        sum += list.Elements[i];
    return sum;
}
int main()
{
    List L;
    readList(&L);
    printList(L);
    copyEvenNumbers(L, &L);
    printList(L);
    printf("%.3f", getAvg(L));
    return 0;
}