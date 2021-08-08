#include <stdio.h>

struct Point
{
    double x, y;
};

int main(int argc, char const *argv[])
{
    struct Point a;
    scanf("%lf%lf", &a.x, &a.y);        // Nhap tu ban phim cho tung truong
    printf("(%.3lf, %.3lf)", a.x, a.y); //Hien thi
    return 0;
}
