
#include "Dosya.h"
#include "Kisi.h"
#include "Oyun.h"
#include "time.h"
Oyun new_Oyun()
{
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->basla = &basla;
    this->bekle = &bekle;
    this->bitti = &bitti;
    this->yazdir = &yazdir;
    return this;
}
void bekle()
{
    int milli_seconds = 250;
    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
    
}
void basla()
{   
    double masa=0;
    Kisi kisi_ptr;
    Kisi kisi_ptr_yedek;
    Kisi zengin_ptr;
    char *kisiYolu = "doc/Kisiler.txt";
    char *sayiYolu = "doc/Sayilar.txt";
    Dosya dosya = new_Dosya();
    
    int satir1 = dosya->satir_sayisi(sayiYolu);
    int satir2 = dosya->satir_sayisi(kisiYolu);
    int *sayilar = dosya->sayilar_okuma();
    kisi_ptr = dosya->kisiler_okuma();

    kisi_ptr_yedek= kisi_ptr;
    zengin_ptr =kisi_ptr;
    
    for (int i = 0; i < satir1; i++)
    {
        int sayi = sayilar[i];
        for (int j = 0; j < satir2; j++)
        {
            if (kisi_ptr_yedek->parasi>0)
            {
                if (kisi_ptr_yedek->sayi==sayi)
                {
                    //kazandı
                    double kazanilan = 9*((kisi_ptr_yedek->parasi)*(kisi_ptr_yedek->yatirilan));
                    kisi_ptr_yedek->parasi = kisi_ptr_yedek->parasi + kazanilan;
                    masa = masa - kazanilan;
                }
                else
                {
                    //kaybetti
                    double kaybedilen = (kisi_ptr_yedek->parasi*kisi_ptr_yedek->yatirilan);
                    kisi_ptr_yedek->parasi = kisi_ptr_yedek->parasi - kaybedilen;
                    masa = masa + kaybedilen;
                    if ((kisi_ptr_yedek->parasi)<1000)
                    {
                        kisi_ptr_yedek->parasi=(-1);
                    }
                }
                if ((kisi_ptr_yedek->parasi)>(zengin_ptr->parasi))
                {
                    zengin_ptr=kisi_ptr_yedek;
                }
            }
            kisi_ptr_yedek++;
        }
        kisi_ptr_yedek=kisi_ptr;
        yazdir(sayi,i+1,masa,zengin_ptr->ad_soyad,zengin_ptr->parasi);
        bekle();
        
    }
    bitti(satir1,masa);
}
void yazdir(int sansliSayi,int tur,long masa,char* zengin_ad,long bakiye)
{
    system("cls");
    int indis1=0;
    int indis2=0;
    int indis3=0;
    int indis4=30;
    int indis5=0;
    if (sansliSayi==10)
    {
        indis1=2;
    }
    else
    {
        indis1=1;
    }
    for (int i = tur; i != 0; i/=10)
    {
        indis2++;
    }
    for (long  i = masa; i != 0; i/=10)
    {
        indis3++;
    }
    for (long i = bakiye; i != 0; i/=10)
    {
        indis5++;
    }
    printf("\n\n\n\n\n\n");
    
    printf("                              #############################################\n");
    //---------------------------------------------------------------------------------------------
    printf("                              ##             SANSLI SAYI: %d",sansliSayi);
    for (int i = 0; i < 43-(28+indis1); i++)
    {
        printf(" ");
    }
    printf("##\n");
    //---------------------------------------------------------------------------------------------
    printf("                              #############################################\n");
    printf("                              #############################################\n");
    //---------------------------------------------------------------------------------------------
    printf("                              ##                  TUR: %d",tur);
    for (int i = 0; i < 43-(25+indis2); i++)
    {
        printf(" ");
    }
    printf("##\n");
    //----------------------------------------------------------------------------------------------
    printf("                              ##     MASA BAKIYE: %d TL",masa);
    for (int i = 0; i < 40-(20+indis3); i++)
    {
        printf(" ");
    }
    printf("##\n");
    //----------------------------------------------------------------------------------------------
    printf("                              ##                                         ##\n");
    printf("                              ##-----------------------------------------##\n");
    printf("                              ##              EN ZENGIN KISI             ##\n");
    //----------------------------------------------------------------------------------------------
    printf("                              ##           %s",zengin_ad);
    for (int i = 0; i < 43-(15+indis4); i++)
    {
        printf(" ");
    }
    printf("##\n");
    //----------------------------------------------------------------------------------------------
    printf("                              ##     BAKIYESI: %d",bakiye);
    for (int i = 0; i < 43-(17+indis5); i++)
    {
        printf(" ");
    }
    printf("##\n");
    //----------------------------------------------------------------------------------------------
    printf("                              ##                                         ##\n");
    printf("                              #############################################\n");
    printf("\n\n\n\n\n\n");
    

}
void bitti(int tur,long masa)
{
    system("cls");
    int indis1=0;
    int indis2=0;
    for (int i = tur; i != 0; i/=10)
    {
        indis1++;
    }
    for (long  i = masa; i != 0; i/=10)
    {
        indis2++;
    }
    printf("\n\n\n\n\n\n");
    printf("                              #############################################\n");
    printf("                              ##                  TUR: %d",tur);
    for (int i = 0; i < 43-(25+indis1); i++)
    {
        printf(" ");
    }
    printf("##\n");
    printf("                              ##     MASA BAKIYE: %d TL",masa);
    for (int i = 0; i < 40-(20+indis2); i++)
    {
        printf(" ");
    }
    printf("##\n");
    printf("                              ##                                         ##\n");
    printf("                              ##-----------------------------------------##\n");
    printf("                              ##                OYUN BITTI               ##\n");
    printf("                              ##                                         ##\n");
    printf("                              ##                                         ##\n");
    printf("                              ##                                         ##\n");
    printf("                              #############################################\n");
    printf("\n\n\n\n\n\n");

}
