#include "./lib/PListLib.c"

void append(ElementType x, List *pL)
{
    Position P = endList(*pL);
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}
void normalize(List *pL)
{
    Position p, q;
    p = *pL;
    while (p->Next != NULL)
    {
        q = next(p, *pL);
        while (q->Next != NULL)
        {
            if (p->Next->Element == q->Next->Element)
                deleteList(q, pL);
            else
                q = q->Next;
        }
        p = p->Next;
    }
}

int main()
{
    List L;
    makenullList(&L);
    append(1, &L);
    append(2, &L);
    append(2, &L);
    append(2, &L);
    normalize(&L);
    return 0;
}