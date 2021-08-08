#include <stdio.h>

struct Point
{
    double x, y;
};

struct Point readPoint()
{
    struct Point point;
    scanf("%lf%lf", &point.x, &point.y);
    return point;
}

void printPoint(struct Point point)
{
    printf("(%0.3f, %0.3f)", point.x, point.y);
}


int main(int argc, char const *argv[])
{
    struct Point a;
    scanf("%lf%lf", &a.x, &a.y);        // Nhap tu ban phim cho tung truong
    printf("(%.3lf, %.3lf)", a.x, a.y); //Hien thi
    return 0;
}
