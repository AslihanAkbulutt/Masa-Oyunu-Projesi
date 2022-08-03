
#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct DOSYA
{
    int (*satir_sayisi)(char*);
    int* (*sayilar_okuma)();
    struct KISI *(*kisiler_okuma)();
    int (*karakter_sayisi)(int);
    double (*CharToDouble)(char[]);
};

typedef struct DOSYA* Dosya;

Dosya new_Dosya();
int satir_sayisi(char*);
int *sayilar_okuma();
struct KISI *kisiler_okuma();
int karakter_sayisi(int);
double CharToDouble(char[]);


#endif
