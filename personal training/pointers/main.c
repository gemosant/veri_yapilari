#include <stdio.h>
#include <stdlib.h> //malloc icin gerekli

int fonksiyon_1(int *);

int fonksiyon_2(int *);

int main()
{
    // TEMEL POINTER
    //int a = 10;
    //int *p;
    //p = &a;
    //printf("p nin gostedigi yerdeki deger: %d\n", *p);
    //printf("p nin gosterdigi yerin adresi: %d\n", p);
    //printf("a nin degeri: %d\n", a);
    //printf("a nin adresi: %d\n", &a);
    //printf("p nin adresi: %d\n", &p);
    //TEMEL POINTER

    int *p;
    int a = 10;
    p = &a;
    printf("%d\n", *p);
    *p = 20; //a nin degerini degitirdik
    printf("%d\n", a);

    printf("\n");

    int *q = (int *)malloc(sizeof(int)*a);
    q[3] = 70;
    printf("%d\n", *(q+3)); // *(q+3) == q[3]

    fonksiyon_1(&a);
    printf("%d\n", a);

    fonksiyon_2(&a);
    printf("%d\n", a);

    return 0;
}

int fonksiyon_1(int * a){ // call by reference (atif ile cagirma)
    *a = 80;
}

int fonksiyon_2(int * a){ // call by value (deger ile cagirma)
    a = 42;
}
