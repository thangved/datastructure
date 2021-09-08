#include <StackLib.h>

void xoa(NganXep *pS)
{
    if (pS->Dinh == SoPhanTu)
        return;
    pS->Dinh++;
}