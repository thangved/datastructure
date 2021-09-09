# DANH SÁCH LIÊN KẾT

![banner](../assets/images/dslk-banner.png)

## MỘT SỐ KHÁI NIỆM

### struct Node

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

### Position

> `Position` chỉ vị trí của phần tử, vị trí của phần tử là địa chỉ phần tử trước nó và có kiểu là `struct Node*`

```c
typedef struct Node* Position;
```

### List

> `List` chỉ kiểu của danh sách đồng thời là `Header` - vị trí đầu của danh sách và có kiểu là `Position`.

```c
typedef Position List;
```

## LIÊN KẾT

- [Các phép toán trên danh sách liên kết các số nguyên](./CacPhepToanTrenDanhSachLienKetCacSoNguyen)

- [Áp dụng danh sách liên kết các số nguyên](./ApDungDanhSachLienKetCacSoNguyen)

- [Danh sách sinh viên](./DanhSachSinhVien)

- [Đa thức](./DaThuc)

- [Thư viện PListLib.c](./lib/PListLib.c)
