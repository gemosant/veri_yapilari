#include <stdio.h>
#include <stdlib.h>

// MATRÝS ÇARPIMI


void matris_carpimi(int A[][3], int A_row, int A_column,
                    int B[][2], int B_row, int B_column,
                    int C[][2], int C_row, int C_column){

    int i, j, k;
    if(A_column != B_row){

        printf("Carpim matrislerinin boyutlari uyusmuyor!\n");
        return;
    }
    else if(A_row != C_row || B_column != C_column){

        printf("Sonuc matrisinin boyutlari carpan matrislere uymuyor!\n");
        return;
    }
    else{

        for(i=0; i<A_row; i++){
            for(j=0; j<B_column; j++){

                C[i][j]=0;
                for(k=0; k<A_column; k++){
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                }
            }
        }
    }
}


void matris_yaz(int A[][2], int row){

    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<2; j++){
            printf("%3d ", A[i][j]);
            printf("\n");
        }
    }
}

int main(){

    int A[][3] = {{1,0,2},{2,1,4},{5,1,0},{0,0,3}};
    int B[][2] = {{0,1},{2,4},{3,1}};
    int C[4][2];

    matris_carpimi(A,4,3,B,3,2,C,4,2);

    matris_yaz(C,4);

    return 0;
}
