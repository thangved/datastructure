// #include "pLLib.c"
// Định nghĩa các hàm nhập, hiển thị, liệt kê các số nguyên lẻ
// Định nghĩa hàm chép các số nguyên chẵn sang danh sách kết quả
// Gọi thực thi các hàm trên trong hàm main()

#define USE_ALL 1
#include "pLLib.c"

int main()
{
    List L1, L2;
    readList(&L1);
    printList(L1);
    printOddNumbers(L1);
    copyEvenNumbers(L1, &L2);
    printList(L2);
    return 0;
}
