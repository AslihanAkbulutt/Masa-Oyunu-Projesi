
#include "Dosya.h"
#include "Kisi.h"

Dosya new_Dosya()
{
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));
    this->kisiler_okuma = &kisiler_okuma;
    this->satir_sayisi = &satir_sayisi;
    this->sayilar_okuma = &sayilar_okuma;
    this->karakter_sayisi= &karakter_sayisi;
    this->CharToDouble= &CharToDouble;
    return this;
}
int satir_sayisi(char* dosyaAdi)
{
    FILE * dosya;
    dosya = fopen(dosyaAdi,"r");
    int sayac = 1;
    char ch;
    if (dosya!=NULL)
    {
        while (!(feof(dosya)))
        {
            ch=getc(dosya);
            if(ch=='\n')
            {
                sayac++;
            }
        }
        fclose(dosya);
        return sayac;
    }
    else
    {
        printf("Dosya Acilamadi.\n");
    }

}
int *sayilar_okuma()
{
    char *sayiYolu = "doc/Sayilar.txt";
    FILE * dosya;
    dosya = fopen(sayiYolu,"r");
    int satir = satir_sayisi(sayiYolu);
    int* sayilar = (int*)malloc(sizeof(int)*satir);
    
    int i=0;

    if ( dosya != NULL)
    {
        while (!(feof(dosya)))
        {
            fscanf(dosya, "%d", &sayilar[i]);
            i = i + 1;
        }
        fclose(dosya);
        return sayilar;
    }
    else
    {
        printf("Dosya Acilamadi.\n");
    }

}
Kisi kisiler_okuma()
{
    char *kisiYolu = "doc/Kisiler.txt";
    FILE * dosya;
    dosya = fopen(kisiYolu,"r");
    int satir = satir_sayisi(kisiYolu);
    char karakter;
    int sayac =0;
    Kisi kisi_ptr = new_Kisi(satir);
    Kisi kisi_yedek = kisi_ptr;

    if (dosya!=NULL)
    {
        for (int i = 0; i < satir; i++)
        {
    
            int sayi = karakter_sayisi(i+1);
            if(satir-1==i)
            {
                sayi = sayi-1;
            }

            char Kisiler[sayi];

            for (int j = 0; j < sayi+1; j++)
            {
                fscanf(dosya,"%c",&karakter);
                if (karakter=='\n')
                {
                    
                }
                else
                {
                    Kisiler[j]=karakter;
                }
                
            }
            char yedek[sayi];
            for (int j = 0; j < sayi ; j++)
            {
                yedek[j]=Kisiler[j];
            }
            yedek[sayi]='\0';

            char x[] = "#";
        
            char *ptr = strtok(yedek, x);
            char* ad_soyad;
            char* parasi;
            char* yatirilan;
            char* Ssayi;
            int sayac2 =1;

            ad_soyad = ptr;

            while(ptr!=NULL)
            {
                ptr = strtok(NULL, x);
                
                if(sayac2 == 1)
                {
                    parasi = ptr;
                }
                else if(sayac2 == 2)
                {
                    yatirilan = ptr;
                }
                else if(sayac2 == 3)
                {
                    Ssayi = ptr;
                }
                else
                {

                }
                sayac2++;
            }

            double dparasi = CharToDouble(parasi);
            
            double dyatirilan = CharToDouble(yatirilan);

            int isayi = atoi(Ssayi);
            
            kisi_yedek->parasi=dparasi;
            kisi_yedek->yatirilan=dyatirilan;
            kisi_yedek->sayi=isayi;
            int sayac3=strlen(ad_soyad);
            for (int j = 0; j < sayac3; j++)
            {
                kisi_yedek->ad_soyad[j]=ad_soyad[j];
            }
            for (int j = sayac3; j < 30; j++)
            {
                kisi_yedek->ad_soyad[j]=' ';
            }
            kisi_yedek->ad_soyad[30]='\0';
            
            kisi_yedek++;
        }
        
        fclose(dosya);
        return kisi_ptr;
    }
    else
    {
        printf("Dosya Bulunamadı.");
    }
}
int karakter_sayisi(int satir)
{
    char *kisiYolu = "doc/Kisiler.txt";
    FILE * dosya2;
    dosya2 = fopen(kisiYolu,"r");
    char karakter;
    int i =0;
    int sayac = 0;
    
    if (satir==0)
    {
        return 0;    
    }
   
    while (!(feof(dosya2)))
    {
        fscanf(dosya2, "%c", &karakter);
        if(karakter=='\n')
        {
            sayac = sayac +1;
            if(sayac==satir)
            {
                fclose(dosya2);
                return i;
            }
            i=(-1);
        }
        i = i + 1;
    }
    fclose(dosya2);
    
    return i;
}
double CharToDouble(char sayi[])
{
    int sayac =0;
    double sonuc =0;
    double m = 1;
    int nokta =0;
    for (int i = 0; sayi[i] != '\0'; i++)
    {
        if(sayi[i]=='.')
        {
            nokta=i;
        }
    }
    
    for(int i = nokta-1; i >= 0; i--)
    {
        sonuc += (sayi[i] - '0') * m;
        m *= 10; 
    }
    m =(0.1);
    for(int i = nokta+1; i < sayi[i]!='\0'; i++) 
    {
        
        sonuc += (sayi[i] - '0') * m;
        m = m/10; 
    }
    
    return sonuc;
}
