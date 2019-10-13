/*
    SORU:
        Bir dizinin icindeki sayilarin ortalamasini, toplamlarini ve en buyugunu donduren fonksiyon yaz.
        Cozum icin "caal by reference" kullan.
*/

#include <stdio.h>
#include <stdlib.h>

void fonksiyon(int *a, int boyut, int *toplam, int *ortalama, int *enBuyuk){

    int t = 0;
    int en_buyuk = a[0];

    for(int i=0; i<boyut; i++){
        if(a[i]>en_buyuk){
            en_buyuk = a[i];
        }
    t += a[i];
    }
    *toplam = t;
    *ortalama = t / boyut;
    *enBuyuk = en_buyuk;
}

int main()
{
    int a[5] = {3, 7, 1, 9, 5};
    int *toplam = (int *)malloc(sizeof(int));
    int *ortalama = (int *)malloc(sizeof(int));
    int * eBuyuk = (int *)malloc(sizeof(int));

    fonksiyon(a, 5, toplam, ortalama, eBuyuk);

    printf("toplam: %d\nortalama: %d\nen buyuk: %d\n", *toplam, *ortalama, *eBuyuk);

    return 0;
}
