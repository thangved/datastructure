// #include "PListLib.c"
// Định nghĩa các hàm nhập và hiển thị danh sách
// Gọi thực thi hàm nhập và hiển thị trong hàm main()

#define USE_ALL 1
#include "PListLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    return 0;
}