#include <stdio.h>
#include <stdlib.h>

void swap_numbers(int *a, int *b){

    int c;
    c = *a;
    *a = *b;
    *b = c;
    return;
}

int main()
{
    int x, y;
    x = 10;
    y = 20;
    swap_numbers(&x, &y);
    printf("%d\n%d", x, y);

    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    *ptr = 100;
    printf("\n--------------------------------\n");
    printf("%p\n%d", ptr, *ptr);

    return 0;
}


