#include <stdio.h>
#include <stdlib.h>                       

typedef struct createnode{
    int value;
    struct createnode *nextnode;
}s;

void printlist(s *ptr){
    while(ptr!=NULL){
        printf(" %d ",ptr->value);
        ptr= ptr->nextnode;
    }
}
int main(){

    s *first, *second, *third, *fourth, *fifth;

    first = (s*)malloc(sizeof(s));
    second= (s*)malloc(sizeof(s));    
    third= (s*)malloc(sizeof(s));    
    fourth= (s*)malloc(sizeof(s));    
    fifth= (s*)malloc(sizeof(s));

    first->value = 90;
    first->nextnode= second;
    second-> value = 500;
    second->nextnode= third;
    third-> value = 40;
    third->nextnode= fourth;
    fourth-> value = 900;
    fourth->nextnode= fifth;
    fifth-> value = 20;
    fifth->nextnode= NULL;
 

    printlist(first);



    return 0;
}