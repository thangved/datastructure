/**
 * @file define.h
 * @author Minh Thắng (https://github.com/thangved)
 * @brief Định nghĩa các kiểu dữ liệu
 * @version 0.1
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) Minh Thắng 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>

/*__DEFINE__TYPE__*/
typedef int ElementType; // kieu cua phan tu du lieu

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position; // kieu vi tri
typedef Position List;
/*__END__DEFINE__TYPE__*/