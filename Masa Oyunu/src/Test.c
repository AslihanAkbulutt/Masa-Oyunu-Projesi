/**
*
* @author Aslihan Akbulut  aslihan.akbulut1@ogr.sakarya.edu.tr
* @since 08.05.2022
* <p>
* Sinif: 2C  no:G201210080 
* </p>
*/
#include "stdio.h"
#include "Dosya.h"
#include "Kisi.h"
#include "Oyun.h"
int main()
{
    Oyun oyun = new_Oyun();
    oyun->basla();
    
    return 0;

}