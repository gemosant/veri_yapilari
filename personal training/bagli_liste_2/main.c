// Loop ile linked list kontrolu

#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
};

typedef struct n node;

void linked_list_bastir(node * r){
    while(r != NULL){
        printf("%d\n", r -> x);
        r = r -> next;
    }
}

void linked_list_eleman_ekle(node * r, int x){
    while(r -> next != NULL){
        r = r -> next;
    }
    r -> next = (node *)malloc(sizeof(node));
    r -> next -> x = x;
    r -> next -> next = NULL;
}

int main()
{
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> next = NULL;
    root -> x = 500;

    int i = 0;
    for(i=0; i<5; i++){
        linked_list_eleman_ekle(root, i*8);
    }

    linked_list_bastir(root);


    return 0;
}
