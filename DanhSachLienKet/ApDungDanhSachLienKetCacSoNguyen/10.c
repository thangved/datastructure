// #include "pLLib.c"
// Định nghĩa các hàm nhập, hiển thị và sắp xếp danh sách
// Gọi thực thi các hàm trên trong hàm main()

#define USE_ALL 1
#include "pLLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    sort(&L);
    printList(L);
    return 0;
}
