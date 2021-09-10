#define USE_ALL 1
#include "AListLib.c"

int main()
{
    List list;
    readList(&list);
    printList(list);
    int x;
    scanf("%d", &x);
    deleteList(locate(x, list), &list);
    printList(list);
    return 0;
}