# MỘT SỐ PHÉP TOÁN TRÊN STACK

## CÁC PHÉP TOÁN CƠ BẢN

### makenullStack

> Khởi tạo một `Stack` rỗng.

```c
void makenullStack(Stack *pS)
{
    pS->Top_idx = MaxLength;
}
```

### emptyList

> Kiểm tra `Stack` rỗng.

```c
int emptyStack(Stack S)
{
    return S.Top_idx == MaxLength;
}
```

### fullStack

> Kiểm tra `Stack` đầy.

```c
int fullStack(Stack S)
{
    return S.Top_idx == 0;
}
```

### top

> Trả về giá trị của đỉnh `Stack`.

```c
ElementType top(Stack S)
{
    if (!emptyStack(S))
        return S.Elements[S.Top_idx];
    printf("Loi! Ngan xep rong");
    return NULL;
}
```

### pop

> Xóa phần tử ở đầu `Stack`.

```c
void pop(Stack *pS)
{
    if (!emptyStack(*pS))
        pS->Top_idx--;
    printf("Loi! Ngan xep rong");
}
```

### push

> Chèn thêm phần tử vào đỉnh `Stack`.

```c
void push(ElementType x, Stack *pS)
{
    if (fullStack(*pS))
    {
        printf("Loi! Ngan xep day");
        return;
    }
    pS->Top_idx--;
    pS->Elements[pS->Top_idx] = x;
}
```

## MỘT SỐ PHÉP TOÁN KHÁC
