#define USE_ALL 1
#include "AListLib.c"

int main()
{
    List list;
    readList(&list);
    printList(list);

    ElementType x;
    scanf("%d", &x);
    removeAll(x, &list);
    printList(list);

    return 0;
}