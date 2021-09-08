# HÀNG ĐỢI DANH SÁCH ĐẶC

## CÀI ĐẶT

### MaxLength

> Chiều dài tối đa của mảng.

```c
#define MaxLength <number>
```

### ElementType

> Kiểu dữ liệu của các phần tử.

```c
typedef <type> ElementType;
```

### Queue

> Cấu trúc hàng đợi:
>
> - `Elements`: Mảng các phần tử.
>
> - `Front`: Chỉ số đầu.
>
> - `Rear`: Chỉ số cuối.
>

```c
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
}
Queue;
```
