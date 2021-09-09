// #include "PListLib.c"
// Định nghĩa các hàm nhập và hiển thị danh sách
// Định nghĩa hàm xóa tất cả phần tử x trong danh sách
// Gọi thực thi các hàm trên trong hàm main()

#define USE_ALL 1
#include "PListLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    ElementType x;
    scanf("%d", &x);
    removeAll(x, &L);
    printList(L);
    return 0;
}