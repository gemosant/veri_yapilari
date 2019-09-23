#include <stdio.h>
#include <stdlib.h>

void uc_boyutlu_dizi_yazdir(int (*dizi)[5][2], int ilk_boyut){

    int i;
    int j;
    int k;
    for (i=0;i<ilk_boyut;i++){
        for(j=0;j<5;j++){
            for(k=0;k<2;k++){
                printf("\n%p\n", dizi[i][j][k]);
            }
        }
    }

}


int main()
{
    int dizi[3][5][2]={{{1,2},{3,4},{5,6},{7,8},{9,10}},{{11,12},{13,14},{15,16},{17,18},{19,20}},{{21,22},{23,24},{25,26},{27,28},{29,30}}};
    uc_boyutlu_dizi_yazdir(&dizi[0][0], 3);//adreslerini yazdýrdýk

    return 0;
}
