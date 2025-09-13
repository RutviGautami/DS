#include <stdio.h>

int top=-1;

void push(int stack[],int x,int n){
    if(top > n){
        printf("stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop(int stack[]){
    if(top<0){
        printf("stack underflow\n");
        return 0; 
    }
    return stack[top--];
}

void display(int stack[]){
    for(int i=0;i<=top;i++){
        printf("%d,",stack[i]);
    }
    return;
}

void main(){
    int n;
    printf("Enter size of stack: ");
    scanf("%d",&n);
    int stack[n];
    int check=0,x;
    while(check==1 || check ==0){
        printf("Enter 0 to push \n1 to pop \nany other key to exit:\n");
        scanf("%d",&check);
        switch(check){
            case 0: printf("Enter element you want to push: ");
                    scanf("%d",&x);
                    push(stack,x,n);
                    break;
            case 1: printf("%d poped\n",pop(stack));
                    break;
        }
    }
    display(stack);
}