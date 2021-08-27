// Cho trước khai báo kiểu List như trên cùng với các phép toán :

//     -void
//     readList(List *pL) : Nhập một danh sách chỉ bởi con trỏ pL từ bàn phím

//     - void printList(List L) : hiển thị danh sách L lên màn hình

// Và cho hàm main() như sau :

// #include <stdio.h>

//     int main()
// {
//     //Khai báo biến
//     List L;

//     //Gọi hàm nhập và hàm hiển thị danh sách
//     ...

//         return 0;
// }

#define _USE_ALL 1
#include "AListLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    return 0;
}