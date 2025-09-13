#include<stdio.h>

struct interval{
    int start;
    int end;
};

int top=-1;

void push(int stack[],int x){
    stack[++top] = x;
}

int pop(int stack[]){
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
    printf("Enter size of array: ");
    scanf("%d",&n);
    int stack[100];
    struct interval a[n];
    int i=0;
    while(i!= n){
        printf("Enter start and end of element: ");
        scanf("%d %d",&a[i].start,&a[i].end);
        i++;
    }
    i=0;
    push(stack,a[i].start);
    push(stack,a[i].end);
    while(i != n){
        int j = i+1;
            if(a[i].end >= a[j].start && a[i].end <= a[j].end){
                pop(stack);
                push(stack,a[j].end);
                a[i].end = a[j].end;
                i++;
            }
            if(a[i].start >= a[j].start && a[i].start <= a[j].end){
                int x = pop(stack);
                pop(stack);
                push(stack,a[j].start);
                push(stack,x);
                a[i].end = a[j].end;
                i++;
            }
            else{
                push(stack,a[i].start);
                push(stack,a[i].end); 
            }
        i++;   
    }
    display(stack);
}

