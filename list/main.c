#include "AListLib.c"
#include <stdio.h>

// ham nhap List tu ban phim
void readList(List *pList)
{
    Position last;
    scanf("%d", &last);
    pList->Last = last;

    for (Position p = 1; p <= pList->Last; p++)
        scanf("%d", &pList->Elements[p - 1]);
}

// in ra List
void printList(List L)
{
    for (Position p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L));

    printf("\n");
}
// tim hieu cua hai tap
void difference(List list1, List list2, List *pList)
{
    pList->Last = 0;
    for (int i = 0; i < list1.Last; i++)
        if (!member(list1.Elements[i], list2))
        {
            pList->Elements[pList->Last] = list1.Elements[i];
            pList->Last++;
        }
}

int main()
{
    List list1, list2, list3;

    readList(&list1);
    readList(&list2);

    normalize(&list1);
    normalize(&list2);
    difference(list1, list2, &list3);

    printList(list1);
    printList(list2);
    printList(list3);

    return 0;
}