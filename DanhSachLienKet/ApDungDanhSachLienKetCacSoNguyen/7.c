// #include "PListLib.c"
// Định nghĩa các hàm nhập và hiển thị danh sách
// Định nghĩa hàm xóa phần tử x được tìm thấy đầu tiên trong danh sách
// Hàm main()

#define USE_ALL 1
#include "PListLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    ElementType x;
    scanf("%d", &x);
    erase(x, &L);
    printList(L);
    return 0;
}