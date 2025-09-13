#include <stdio.h>

int top=-1;

void push(char stack[],char x){
    stack[++top] = x;
}

char pop(char stack[]){
    return stack[top--];
}

void display(char stack[]){
    for(int i=0;i<=top;i++){
        printf("%c,",stack[i]);
    }
    return;
}
void main(){
    char str[100];
    gets(str);
    char stack[100],i=0;
    while(str[i] != 'c'){
        push(stack,str[i++]);
    }
    i++;
    while(str[i] != '\0'){
        if(pop(stack) != str[i]){
            printf("Invalid grammar");
            return;
        }
        i++;
    }
    display(stack);
    printf("Valid grammar");
}
