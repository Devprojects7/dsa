#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node *next;
} list;

void traversal(list *ptr){
    while(ptr!=NULL){
    printf(" %d ", ptr->num);
    ptr = ptr->next;

    }
}

list *insertatfirst(list *ptr, int value){
    list *newNode = (list *)malloc(sizeof(list));
    newNode->num = value;
    newNode->next = ptr;
    return newNode;
}
list *insertatindex(list *ptr, int value, int index){
    list *newNode = (list *)malloc(sizeof(list));
    list *p = ptr;
    int i = 0;
    while(i!=index-1){
    p = p->next;
    i++;
    }
    newNode->num = value;
    newNode->next = p->next;
    p->next = newNode;
    return ptr;
}


int main(){
    list *first, *second, *third, *fourth, *fifth;

    first = (list *)malloc(sizeof(list));
    second = (list *)malloc(sizeof(list));
    third = (list *)malloc(sizeof(list));
    fourth = (list *)malloc(sizeof(list));
    fifth = (list *)malloc(sizeof(list));

    first->num = 100;
    first->next = second;
    second->num = 60;
    second->next = third;
    third->num = 700;
    third->next = fourth;
    fourth->num = 100;
    fourth->next = fifth;
    fifth->num = 500;
    fifth->next = NULL;
    traversal(first);

    printf("\nAfter insertion at first \n");
    first = insertatfirst(first, 1000);

    traversal(first);
    printf("\nAfter insertion at between \n");
    first = insertatindex(first, 2,1);

    traversal(first);
}