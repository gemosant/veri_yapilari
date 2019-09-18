#include <stdio.h>
#include <stdlib.h>

/*

TEK BOYUTLU DÝZÝ YAZDIRMA

void dizi_yazdir(int *dizi, int *len_dizi){

    int i;
    for(i = 0;i < 5; i++){
        printf("%d\n", *dizi);
        dizi++;
    }
}

int main(){
    int dizi[]={1,2,3,4,5};
    dizi_yazdir(dizi, 5);
    return 0;
}

*/

void tek_boyutlu_dizi_olustur(int **dizi, int len_dizi){
    *dizi = (int *)malloc(len_dizi*sizeof(int));
    *(*dizi+3) = 13;
    *(*dizi+4) = 42;
}

int main()
{
    int *dizi_1;
    tek_boyutlu_dizi_olustur(&dizi_1, 5);

    printf("Adres: %p", (dizi_1 + 3)); // ADRES
    printf("\nAdreste Tutulan Deger: %d", *(dizi_1+3)); // ADRESTE TUTULAN DEÐER

    printf("\nAdres: %p", (dizi_1 + 4)); // ADRES
    printf("\nAdreste Tutulan Deger: %d", *(dizi_1+4)); // ADRESTE TUTULAN DEÐER
    return 0;
}
