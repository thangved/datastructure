// khong cop ham main

#include <stdio.h>

typedef struct
{
    float Real, Image;
} Complex;

Complex readComplex()
{
    Complex a;
    scanf("%f%f", &a.Real, &a.Image);
    return a;
}

void printComplex(Complex complex)
{
    printf("%.3f + i%.3f", complex.Real, complex.Image);
}

int main(int argc, char const *argv[])
{
    Complex a;

    a = readComplex(); // Gọi hàm nhập 1 số phức từ bàn phím

    printComplex(a); // Hiển thị số phức a lên màn hình

    return 0;
}
