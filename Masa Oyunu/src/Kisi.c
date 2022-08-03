/**
*
* @author Aslihan Akbulut  aslihan.akbulut1@ogr.sakarya.edu.tr
* @since 08.05.2022
* <p>
* Sinif: 2C  no:G201210080 
* </p>
*/
#include "Kisi.h"
#include "Dosya.h"

Kisi new_Kisi(int satir)
{
    Kisi kisiler = (Kisi)malloc(sizeof(struct KISI)*satir);
    return kisiler;

}