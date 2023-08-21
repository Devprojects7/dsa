#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;    //array to store items
} s;
int isEmpty(s *ptr){
    if(ptr->top==-1){  //if the top is -1 which is before 0 so its empty
        return 1;
    }
    else{
        return 0;
    }

}

int isFull(s *ptr){
    if(ptr->top == ptr->size-1){
        return 1;  //if the 
    }
    else{
        return 0;
    }
}

void push(s *ptr, int num){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = num;
    }
}

int pop(s *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow. Cannot pop from the stack\n");

    }
    else{
        int num = ptr->arr[ptr->top];
        ptr->top--;
        return num;
    }
}
int main(){
    s *stack;
    stack->size = 10;
    stack->top = -1;

    stack->arr = (int *)malloc(stack->size * sizeof(int));

    printf("\nBefore pushing %d\n",isEmpty(stack));
    push(stack, 500);
    printf("\nAfter pushing %d\n",isEmpty(stack));

    pop(stack);

    printf("\nAfter popping %d",isEmpty(stack));
}