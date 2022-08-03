
#include "Kisi.h"
#include "Dosya.h"

Kisi new_Kisi(int satir)
{
    Kisi kisiler = (Kisi)malloc(sizeof(struct KISI)*satir);
    return kisiler;

}
