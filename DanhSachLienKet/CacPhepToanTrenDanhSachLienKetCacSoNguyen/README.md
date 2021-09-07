# CÁC PHÉP TOÁN TRÊN DANH SÁCH LIÊN KẾT CÁC SỐ NGUYÊN

## DANH SÁCH LIÊN KẾT

### struct Node

> `struct Node` là một cấu trúc gồm 2 trường:
>
> - Trường `Element` lưu trữ giá trị có kiểu ElementType;
> - Trường `Next` là con trỏ lưu địa chỉ của phần tử kế tiếp trong danh sách có kiểu struct Node *.

```c
struct Node{
    ElementType Element;
    struct Node * Next;
}
```

### Position

> `Position` chỉ vị trí của phần tử, vị trí của phần tử là phần tử trước nó và có kiểu là `struct Node*`

```c
typedef struct Node* Position;
```

### List

> `List` chỉ kiểu của danh sách đồng thời là `Header` - vị trí đầu của danh sách có kiểu là Position.

```c
typedef Position List;
```

## CÁC PHÉP TOÁN TRÊN DANH SÁCH LIÊN KẾT CÁC SỐ NGUYÊN

### deleteList

> Xóa phần tử có `Position P`.

```c
void deleteList(Position P, List *pL)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}
```

### emptyList

> Kiểm tra danh sách rỗng.

```c
int emptyList(List L)
{
    return L->Next == NULL;
}
```

### endList

> Trả về vị trí sau vị trí cuối cùng của danh sách `L`.

```c
Position endList(List L)
{
    Position P = L;
    while (1)
    {
        if (P->Next == NULL)
            return P;
        P = P->Next;
    }
}
```

### first

> Trả về vị trí đầu tiên của danh sách `L`.

```c
Position first(List L)
{
    return L;
}
```

### insertList

> Chèn thêm phần tử vào vị trí `P`.

```c
void insertList(ElementType x, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(Position));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}
```

### locate

> Trả về vị trí đầu tiên của `x` trong danh sách `L`.

```c
Position locate(ElementType x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return P;
        P = P->Next;
    }
    return P;
}
```

### makenullList

> Khởi tạo danh sách rỗng.

```c
void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(List));
    (*pL)->Next = NULL;
}
```

### myLocate

> Trả về vị trí thứ `i` của phần tử `x` trong danh sách `L`.

```c
Position myLocate(ElementType x, int i, List L)
{
    Position P = L;
    int count = 0;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            count++;
        if (count == i)
            return P->Next;
        P = P->Next;
    }
    return P->Next;
}
```

### next

> Trả về vị trí tiếp theo của `P`.

```c
Position next(Position P, List L)
{
    return P->Next;
}
```

### previous

> Trả về vị trí trước `P`.

```c
Position previous(Position P, List L)
{
    Position Q = L;
    while (Q->Next->Next != NULL)
    {
        if (Q->Next->Next == P)
            Q = Q->Next;
    }
    return Q->Next;
}
```

### retrieve

> Trả về giá trị của phần tử có vị trí `P`.

```c
ElementType retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}
```
