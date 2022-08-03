/**
*
* @author Aslihan Akbulut  aslihan.akbulut1@ogr.sakarya.edu.tr
* @since 08.05.2022
* <p>
* Sinif: 2C  no:G201210080 
* </p>
*/
#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct KISI
{
    char ad_soyad[30];
    float parasi;
    float yatirilan;
    int sayi;
    
};
typedef struct KISI* Kisi;

Kisi new_Kisi(int);




#endif