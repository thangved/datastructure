#include <StackLib.h>

void hienthi(NganXep *pS)
{
    for (int i = pS->Dinh; i < SoPhanTu; i++)
        printf("%d ", pS->DuLieu[i]);
}