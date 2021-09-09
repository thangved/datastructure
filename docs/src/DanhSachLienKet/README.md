# MỘT SỐ KHÁI NIỆM

![banner](../assets/images/dslk-banner.png)

## struct Node

> `struct Node` là một cấu trúc gồm 2 trường:
>
> - Trường `Element` lưu trữ giá trị có kiểu ElementType;
> - Trường `Next` là con trỏ lưu địa chỉ của phần tử kế tiếp trong danh sách có kiểu `struct Node *`.

```c
struct Node{
    ElementType Element;
    struct Node * Next;
};
```

## Position

> `Position` chỉ vị trí của phần tử, vị trí của phần tử là địa chỉ phần tử trước nó và có kiểu là `struct Node*`
>
> => Để lấy giá trị tại `Position P` ta phải truy cập vào `Next` và lấy ra trường `Element`.
>
> **P->Next->Element;**

```c
typedef struct Node* Position;
```

## List

> `List` chỉ kiểu của danh sách đồng thời là `Header` - vị trí đầu của danh sách và có kiểu là `Position`.

```c
typedef Position List;
```
