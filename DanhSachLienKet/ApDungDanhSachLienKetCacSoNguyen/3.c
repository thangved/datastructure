// #include "PListLib.c"
// Định nghĩa các hàm nhập tập hợp và hiển thị danh sách
// Định nghĩa hàm tìm tập hợp hợp của 2 tập hợp
// Gọi thực thi các hàm trên trong hàm main()

#define USE_ALL 1
#include "PListLib.c"

int main()
{
    List L1 = readSet(),
         L2 = readSet();
    printList(L1);
    printList(L2);
    printList(unionSet(L1, L2));
    return 0;
}