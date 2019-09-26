#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
};

typedef struct n node;

int main()
{
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> x = 10;
    root -> next = (node *)malloc(sizeof(node));
    root -> next -> x = 20;
    root -> next -> next = (node *)malloc(sizeof(node));
    root -> next -> next -> x = 30;

    node * iter; // s�rekli next next yapmak yerine root gibi linked list i�indee dola�abilecek bir iter olu�turmak daha iyi
    iter = root;
    printf("%d\n", iter -> x);
    iter = iter -> next;
    printf("%d\n", iter -> x);

    return 0;
}
