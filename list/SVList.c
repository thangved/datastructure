typedef struct
{
    char MSSV[10], hoVaTen[50];
    float LT, TH1, TH2;
} SinhVien;

#define maxLength 40

typedef SinhVien ElementType;
typedef int Position;

typedef struct
{
    ElementType A[maxLength];
    Position n;
} List;
