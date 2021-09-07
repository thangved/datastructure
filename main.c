#include <stdio.h>
#include <stdlib.h>
/*__DEFINE__TYPE__*/
#ifndef MaxLength
#define MaxLength 300 // So phan tu toi da
#endif

#ifndef ElementType
typedef int ElementType; // Kieu du lieu cua phan tu
#endif

#ifndef Position
typedef int Position; // Position = index + 1
#endif

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;
/*__END__DEFINE__TYPE__*/
void addFirst(ElementType x, List *pL)
{
    for (int i = 0; i < pL->Last; i++)
        pL->Elements[i + 1] = pL->Elements[i];
    pL->Last++;
    pL->Elements[0] = x;
}

void makenullList(List *pL)
{
    pL->Last = 0;
}

void readList(List *pL)
{
    makenullList(pL);
    int n, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        addFirst(e, pL);
    }
}

void printList(List L)
{
    for (int i = 0; i < L.Last; i++)
        printf("%d ", L.Elements[i]);
}

int main()
{
    List L;
    readList(&L);
    printList(L);
    return 0;
}