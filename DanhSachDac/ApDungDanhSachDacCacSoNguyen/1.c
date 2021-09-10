#define USE_ALL
#include "AListLib.c"

int main()
{
    List list1, list2;
    readList(&list1);
    printList(list1);
    printOddNumbers(list1);

    copyEvenNumbers(list1, &list2);
    printList(list2);
}