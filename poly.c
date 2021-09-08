#include <stdlib.h>

typedef struct Polynom
{
    int coeff, pow;
    struct Polynom *link;
} poly;

poly *tichdathuc(poly *px)
{
    poly *result = (poly *)malloc(sizeof(poly));
    poly *end = result;
    poly *pP = px;

    while (pP->link != NULL)
    {
        // 2x
        end->link = (poly *)malloc(sizeof(poly));
        end->link->coeff = pP->link->coeff * 2;
        end->link->pow = pP->link->pow + 1;
        end = end->link;

        // 1
        end->link = (poly *)malloc(sizeof(poly));
        end->link->coeff = pP->link->coeff;
        end->link->pow = pP->link->pow;
        end = end->link;

        pP = pP->link;
    }

    return result;
}

int main()
{
    poly *px = (poly *)malloc(sizeof(poly));
    px->link = (poly *)malloc(sizeof(poly));
    px->link->coeff = 1;
    px->link->pow = 2;
    px->link->link = NULL;
    poly *fx = tichdathuc(px);
    return 0;
}
