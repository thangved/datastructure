#define USE_ALL 1
#include "lib/PListLib.c"

void printInverseList(List L)
{
    List tempL;
    makenullList(&tempL);
    Position P = L;
    while (P != endList(L))
    {
        insertList(retrieve(P, L), first(tempL), &tempL);
        P = next(P, L);
    }
    printList(tempL);
}
int main()
{
    List L;
    readList(&L);
    printInverseList(L);
    return 0;
}