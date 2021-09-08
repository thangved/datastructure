// #include "pLLib.c"
// Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
// Định nghĩa hàm chép các số chẵn sang danh sách kết quả
// Gọi thực thi các hàm trên trong hàm main()

#define USE_ALL 1
#include "pLLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    copyEvenNumbers(L, &L);
    printList(L);
    printf("%.3f", getAvg(L));
    return 0;
}