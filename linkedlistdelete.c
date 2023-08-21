#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number; 
    struct node *next;
}s;
void printlist(s *head){
    s *ptr =head;
    while(ptr!=NULL){
        printf(" %d ", ptr->number);
        ptr = ptr->next;
    }
}
s *deleteatfirst(s *head){
    s *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
s *deleteatany(s *head, int index){
    s *ptr = head;
    s *q = head->next;
    int i=0;
    while(i!=index-1){
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}
s *deleteatlast(s *head){
    s *ptr = head;
    s *q = head->next;
    while(q->next!=NULL){
        ptr= ptr->next;
        q = q->next; 
    }
    ptr->next = NULL;
    free(q);
    return head;
}
s *deleteatanynumber(s *head , int value){
    s *ptr = head;
    s *q = head->next;
   while (ptr->number != value && ptr->next != NULL) {
    ptr = ptr->next;
    q = q->next;
}
    if(ptr->number==value){
        ptr->next = q->next;
        free(q);
    }
    return head;

}
int main(){
    s *first, *second, *third, *fourth, *fifth;

    first = (s*) malloc(sizeof(s));
    second = (s*) malloc(sizeof(s));
    third = (s*) malloc(sizeof(s));
    fourth = (s*) malloc(sizeof(s));
    fifth = (s*) malloc(sizeof(s));

    first->number = 1000;
    first->next = second;
    second->number = 256;
    second->next = third;
    third->number = 110;
    third->next = fourth;
    fourth->number = 800;
    fourth->next = fifth;
    fifth->number = 650;
    fifth->next = NULL;

    printlist(first);
    printf("\nAfter deleting first\n");
    first = deleteatfirst(first);
    printlist(first);
    printf("\nAfter deleting at any index\n");
    first = deleteatany(first,2);
    printlist(first);
    printf("\nAfter deleting at last\n");
    first = deleteatlast(first);
    printlist(first);
    printf("\nAfter deleting after the given value\n");
    first = deleteatanynumber(first, 256);
    printlist(first);

    
    return 0;
}