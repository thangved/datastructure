/**
 * @file NListLib.c
 * @author Kim Minh Thắng (https://github.com/thangved)
 * @brief Thư viện danh sách liên kết
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>

/*__DEFINE__TYPE__*/
typedef int ElementType; // kieu cua phan tu du lieu

struct Node
{
    ElementType Element;
    struct Node *Next;
}

typedef struct Node *Position; // kieu vi tri
typedef Position List;
/*__END__DEFINE__TYPE__*/

/*__FUNCTION__DECLARATION__*/
void makenullList(List *pL);                          // khoi tao danh sach rong
int emptyList(List L);                                //  kiem tra danh sach co rong hay khong
ElementType retrieve(Position P, List L);             // tra ve gia tri phan tu
void insertList(ElementType X, Position P, List *pL); // chen them mot phan tu
void deleteList(Position P, List *pL);                // xoa phan tu sau vi tri P
Position first(List L);                               // tra ve vi tri dau tien
Position endList(List L);                             //tra ve vi tri phan tu cuoi cung
Position next(Position P);                            // tra ve vi tri tiep theo
/*__END__FUNCTION__DECLARATION__*/

/*__FUNCTION__*/
void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(List));
    (*pL)->Next = NULL;
}
int emptyList(List L)
{
    return L->Next == NULL;
}
ElementType retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}
void insertList(ElementType X, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(Position));
    T->Element = X;
    T->Next = Position->Next;
    P->Next = T;
}
void deleteList(Position P, List *pL)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->next;
        free(Temp);
    }
}
Position first(List L)
{
    return L;
}
Position endList(List L)
{
    Position P;
    P = first(L);
    while (P->Next != NULL)
        P = P->Next;
    return P;
}
Position next(Position P)
{
    return P->Next;
}
/*__END__FUNCTION__*/
