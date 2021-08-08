#include <stdio.h>

struct Point
{
    double X, Y;
};

struct Rect
{
    struct Point A, B;
};

int main(int argc, char const *argv[])
{
    struct Rect a = {{5, 7}, {1, 10}};
    return 0;
}
