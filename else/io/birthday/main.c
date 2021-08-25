#include <stdio.h>

int main(int argc, char const *argv[])
{
    int day, month, year;

    scanf("%d%d%d", &day, &month, &year);

    printf("%02d/%02d/%04d", day, month, year);
    return 0;
}
