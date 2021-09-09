#define USE_ALL 1
#include "AListLib.c"

int main()
{
    List list;
    readList(&list);
    printList(list);
    printf("%.3f", getAvg(list));
}