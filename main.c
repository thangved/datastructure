#include "lib/PListLib.c"

List unionList(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1,
             Q = L2,
             end = L;

    while (P->Next != NULL && Q->Next != NULL)
    {
        if (P->Next->Element < Q->Next->Element)
        {
            insertList(P->Next->Element, end, &L);
            P = P->Next;
        }
        else
        {
            insertList(Q->Next->Element, end, &L);
            Q = Q->Next;
        }
        L = L->Next;
    }

    if (P->Next == NULL)
        P = Q;

    while (P->Next != NULL)
    {
        insertList(P->Next->Element, end, &L);
        L = L->Next;
        P = P->Next;
    }
    return L;
}