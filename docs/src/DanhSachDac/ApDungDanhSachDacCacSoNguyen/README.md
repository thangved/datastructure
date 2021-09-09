# ÁP DỤNG DANH SÁCH ĐẶC CÁC SỐ NGUYÊN

## LƯU Ý

> Đây là phần áp dụng danh sách đặc các số nguyên trên hệ thống else
> 
> Mình chỉ viết hàm `main` để các bạn biết cách làm. Còn các hàm khác không có trong file `AListLib.c` các bạn phải tự định nghĩa theo yêu cầu đề bài.

## BÀI TẬP

### BÀI 1

> - Khai báo sử dụng thư viện AListLib.c
> 
> - Định nghĩa các hàm nhập, hiển thị, liệt kê các số nguyên lẻ
> 
> - Định nghĩa hàm chép các số nguyên chẵn sang danh sách kết quả  
> 
> - Khai báo biến và gọi thực thi các hàm trên trong hàm main()

```c
#include "AListLib.c"

int main()
{
    List list1, list2;
    readList(&list1);
    printList(list1);
    printOddNumbers(list1);
    copyEvenNumbers(list1, &list2);
    printList(list2);
}
```

### BÀI 2

> - Khai báo sử dụng thư viện AListLib.c
> 
> - Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử  
> 
> - Khai báo và gọi thực thi các hàm trên trong hàm main()

```c
#include "AListLib.c"

int main()
{
    List list;
    readList(&list);
    printList(list);
    printf("%.3f", getAvg(list));
}
```

### BÀI 3

> - Khai báo sử dụng thư viện AListLib.c
> 
> - Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
> 
> - Định nghĩa hàm tìm tập hợp hợp của 2 tập hợp  
> 
> - Gọi thực thi các hàm trên trong hàm main()

```c
#include "AListLib.c"

int main()
{
    List list1, list2, list3;
    readSet(&list1);
    readSet(&list2);
    unionSet(list1, list2, &list3);
    printList(list1);
    printList(list2);
    printList(list3);
}
```

### BÀI 4

> - Khai báo sử dụng thư viện AListLib.c
> 
> - Định nghĩa các hàm nhập và hiển thị danh sách
> 
> - Định nghĩa hàm xóa tất cả phần tử x trong danh sách  
> 
> - Khai báo biến và gọi thực thi các hàm trên trong hàm main()

```c
#include "AListLib.c"

int main()
{
    List list;
    readList(&list);
    printList(list);

    ElementType x;
    scanf("%d", &x);
    removeAll(x, &list);
    printList(list);

    return 0;
}
```

### BÀI 5

> - Khai báo sử dụng thư viện AListLib.c 
> 
> - Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
> 
> - Định nghĩa hàm tìm tập hợp hiệu của 2 tập hợp  
> 
> - Gọi thực thi các hàm trên trong hàm main()

```c
int main()
{
    List list1, list2, list3;

    readSet(&list1);
    readSet(&list2);

    difference(list1, list2, &list3);

    printList(list1);
    printList(list2);
    printList(list3);

    return 0;
}
```

### BÀI 6

> - #include "AListLib.c"
> 
> - Định nghĩa các hàm nhập và hiển thị danh sách  
> 
> - Định nghĩa hàm xóa phần tử x được tìm thấy đầu tiên trong danh sách  
> 
> - Viết hàm main

```c
#include "AListLib.c"

int main()
{
    List list;
    readList(&list);
    printList(list);
    int x;
    scanf("%d", &x);
    deleteList(locate(x, list), &list);
    printList(list);
    return 0;
}
```
