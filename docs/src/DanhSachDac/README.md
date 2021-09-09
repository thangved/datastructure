# MỘT SỐ KHÁI NIỆM

![banner](../assets/images/ctdlvgt-banner.png)

## Danh sách đặc

> Là cấu trúc danh sách mà các phần tử được lưu trữ bằng mảng và có độ dài tối đa là `MaxLength`.

## List

> `List` là cấu trúc `danh sách` gồm hai trường:
>
> - `Elements`: Mảng lưu trữ các phần tử có kiểu `ElementType` có số phần tử là `MaxLength`.
>
> - `Last`: Vị trí phần tử cuối cùng đồng thời là độ dài của `danh sách` có kiểu `Position`.

## MaxLength

> Số lượng phần tử tối đa của danh sách.

```c
#define MaxLength <number>
```

## ElementType

> Kiểu của phần tử trong danh sách.

```c
typedef <type> ElementType;
```

## Position

> Kiểu vị trí của Danh sách, tương đương với `index + 1`.

```c
typedef int Position;
```
