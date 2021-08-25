# emptyList

## Công dụng

> Kiểm tra 1 danh sách có rỗng hay không?

## Prototype

### Đầu vào

- Danh sách L

### Đầu ra

- Giá trị `1` tương đương với **true**, `0` tương đương với **false**.

## Code mẫu

```c
int emptyList(List list)
{
    return list.Last == 0;
}
```
