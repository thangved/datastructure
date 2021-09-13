#include <stdarg.h>

int test(int a, ...)
{
    va_list list;
    va_start(list, a);
}

int main()
{
    int t = test(1, 2, 3);
    return 0;
}