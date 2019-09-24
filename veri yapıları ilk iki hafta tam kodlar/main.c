/* 
 * File:   main.c
 * Author: BMB
 *
 * Created on 24 Eylül 2013 Salı, 13:35
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/*
 * 
 */

void tek_boyutlu_dizi_olustur(int **dizi, int eleman_sayisi){
    int i;
    *dizi=(int*)malloc(sizeof(int)*eleman_sayisi);
    
    for(i=0; i<eleman_sayisi; i++){
        *(*dizi+i)= rand()%10;
    }
}

void tek_boyutlu_dizi_yaz(int *dizi, int eleman_sayisi){
    int i;
    
    for(i=0; i<eleman_sayisi; i++){
         printf("%p ", (dizi+i));
    }
    printf("\n");
    for(i=0; i<eleman_sayisi; i++){
         printf("%11d ", *(dizi+i));
    }
    printf("\n");
}

void dinamik_matris_olustur(int ***dizi,int satir,int sutun){
    int i,j;
    *dizi=(int**)malloc(satir*sizeof(int*));
    for(i=0; i<satir; i++){
        *(*dizi+i)= (int*)malloc(sutun*sizeof(int));
        for(j=0; j<sutun; j++)
            *(*(*dizi+i)+j)= rand()%2;
    }
}

void matris_degistir(int **dizi, int satir, int sutun){
    int i,j;
    for(i=0; i<satir; i++)
        for(j=0; j<sutun; j++)
            *(*(dizi+i)+j)=rand()%2;
}


void dinamik_matris_yaz(int **dizi,int satir,int sutun){
    int i,j;
    for(i=0; i<satir; i++){
        for(j=0; j<sutun; j++) printf("%4d ",*(*(dizi+i)+j));
        printf("\n");
    }
}

void dinamik_matris_carpimi(int **A,int A_satir, int A_sutun,
                           int **B, int B_satir, int B_sutun,
                           int **C, int C_satir, int C_sutun){
    
    
    int i,j,k;
    if(A_sutun!=B_satir){
        printf("Carpim matrislerinin boyutlari uyusmuyor!!!");
        return;
    }
    else if(A_satir!=C_satir || B_sutun!=C_sutun){
        printf("Sonuc matrisinin boyutlari carpan matrislere uymuyor!!!\n");
        return;
    }
    else{
        for(i=0; i<A_satir; i++)
            for(j=0; j<B_sutun; j++){
                C[i][j]=0;
                for(k=0; k<A_sutun; k++)
                    C[i][j]=C[i][j]+A[i][k]*B[k][j];
                    
            }   
    }
}

void dizi_kopyala(int *statik_dizi, int statik_dizi_uzunlugu, int **dinamik_dizi, int *dinamik_dizi_uzunlugu){
    int i;
    *dinamik_dizi=(int *)malloc(statik_dizi_uzunlugu*sizeof(int));
    if(*dinamik_dizi==NULL){
        printf("Heapte yer ayrilamadi...");
        exit(1);
    }
   *dinamik_dizi_uzunlugu=statik_dizi_uzunlugu;
   for(i=0; i<statik_dizi_uzunlugu; i++)
    
     //  (*dinamik_dizi)[i]=statik_dizi[i];
       *(*dinamik_dizi+i)=statik_dizi[i];
} 



void fonks1(int (*dizi)[3]){
    int i;
    for(i=0; i<3; i++) printf("%d ",(*dizi)[i]);
    printf("\n");
}

void fonks2(int (*dizi)[5][3]){
    int i,j;
    for(i=0; i<5; i++){
        for(j=0; j<3;j++){
            printf("%d ",(*dizi)[i][j]);
        }
        printf("\n");
    }    
            
}


int main(int argc, char** argv) {
    
    int dizi1[5]={4,6,7,9,22};
    int *dinamik_dizi;
    int dinamik_dizi_uzunlugu;
    int **A,**B,**C;
    int *dizi;
    int eleman_sayisi;
    int a;
    int *b;

    int AA[][5][3]={{{1,2,3},{14,5,6},{7,8,9},{10,11,12},{13,14,15}},
                    {{11,12,13},{14,15,16},{17,18,19},{110,111,112},{113,114,115}},
                    {{21,22,23},{24,25,26},{27,28,29},{210,121,122},{123,124,152}}} ;   
    
    fonks1(&AA[1][2]);
    
    printf("-------------------\n");

  //  fonks2(&AA[0]);
    fonks2(AA);
    
    printf("-------------------\n");
    
   
  
    
    srand(time(NULL)); // rastgele (random) sayilar olusturmak icin
    eleman_sayisi=10;
    tek_boyutlu_dizi_olustur(&dizi, eleman_sayisi);
    tek_boyutlu_dizi_yaz(dizi, eleman_sayisi);
    dinamik_matris_olustur(&A,5,6);
    printf("--- AA matrisi ----\n");
    dinamik_matris_yaz(A,5,6);
 
    dinamik_matris_olustur(&B,6,7);
    printf("--- BB matrisi ----\n");
    dinamik_matris_yaz(B,6,7);
 
    dinamik_matris_olustur(&C,5,7);
    printf("--- C matrisi ----\n");
    dinamik_matris_yaz(C,5,7);

    dinamik_matris_carpimi(A,5,6,B,6,7,C,5,7);
    printf("---- C=A*B matrisi ----\n");
    dinamik_matris_yaz(C,5,7);
    printf("-----------------------\n");
 
    
    A[2][3]=129;
    *(*(A+3)+4)=97;
    dinamik_matris_yaz(A,5,6);
    
    tek_boyutlu_dizi_yaz(dizi1,5);
    dizi_kopyala(dizi1,5,&dinamik_dizi,&dinamik_dizi_uzunlugu);
    tek_boyutlu_dizi_yaz(dinamik_dizi,dinamik_dizi_uzunlugu);
    
   
    return (EXIT_SUCCESS);
}

