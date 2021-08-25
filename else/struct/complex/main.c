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
    printf("%.3f + i%.3f\n", complex.Real, complex.Image);
}

void add(Complex a, Complex b, Complex *c)
{
    c->Real = a.Real + b.Real;
    c->Image = a.Image + b.Image;
}

int main(int argc, char const *argv[])
{
    Complex a = {1, 1};
    Complex b;
    add(a, a, &b);

    return 0;
}
