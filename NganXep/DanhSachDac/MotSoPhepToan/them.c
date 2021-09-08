#include <StackLib.h>

void them(int x, NganXep *pS)
{
    if (pS->Dinh == 0)
        return;
    pS->Dinh--;
    pS->DuLieu[pS->Dinh] = x;
}