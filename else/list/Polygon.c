typedef struct
{
    int x, y;
} Point;

#define maxLength 100

typedef Point ElementType;
typedef int Position;

typedef struct
{
    ElementType c[maxLength];
    Position p;
} Polygon;
