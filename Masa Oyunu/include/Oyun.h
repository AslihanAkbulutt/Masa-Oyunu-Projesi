

#ifndef OYUN_H
#define OYUN_H

struct OYUN
{
    void (*basla)();
    void (*yazdir)(int,int,long,char*,long);
    void (*bitti)(int,long);
    void (*bekle)();
};
typedef struct OYUN* Oyun;
Oyun new_Oyun();
void basla();
void yazdir(int,int,long,char*,long);
void bitti(int,long);
void bekle();

#endif
