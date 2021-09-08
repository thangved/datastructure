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

## MỘT SỐ PHÉP TOÁN KHÁC (BÀI TẬP TRÊN ELSE)

### xoa

> Xóa phần tử đỉnh.

```c
void xoa(NganXep *pS)
{
    if (pS->Dinh == SoPhanTu)
        return;
    pS->Dinh++;
}
```

### khoitao

> Khởi tạo `Stack` rỗng.

```c
void khoitao(NganXep *pS)
{
    pS->Dinh = SoPhanTu;
}
```

### them

> Thêm phần tử vào đỉnh của `Stack`.

```c
void them(int x, NganXep *pS)
{
    if (pS->Dinh == 0)
        return;
    pS->Dinh--;
    pS->DuLieu[pS->Dinh] = x;
}
```

### ktRong

> Kiểm tra `Stack` rỗng.

```c
int ktRong(NganXep S)
{
    return S.Dinh == SoPhanTu;
}
```

### ktDay

> Kiểm tra `Stack` đầy.

```c
int ktDay(NganXep S)
{
    return S.Dinh == 0;
}
```

### hienthi

> Hiển thị `Stack`.

```c
void hienthi(NganXep *pS)
{
    for (int i = pS->Dinh; i < SoPhanTu; i++)
        printf("%d ", pS->DuLieu[i]);
}
```

### giatriDinh

> Trả về giá trị tại đỉnh.

```c
int giatriDinh(NganXep S)
{
    return S.DuLieu[S.Dinh];
}
```
