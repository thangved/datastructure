#define USE_ALL 1
#include "AListLib.c"

int main()
{
    List list1, list2, list3;
    readSet(&list1);
    readSet(&list2);
    unionSet(list1, list2, &list3);
    printList(list1);
    printList(list2);
    printList(list3);
}