// #include "PListLib.c"
// Định nghĩa các hàm nhập, hiển thị, trung bình cộng các phần tử
// Gọi thực thi các hàm trên trong hàm main()

#define USE_ALL 1
#include "PListLib.c"

int main()
{
    List L;
    readList(&L);
    printList(L);
    printf("%.3f", getAvg(L));
    return 0;
}
