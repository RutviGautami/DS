#include<stdio.h>

int top=-1;

void push(char stack[],char x){
    stack[++top] = x;
}

char pop(char stack[]){
    return stack[top--];
}

void main(){
    char str[100];
    gets(str);
    char stack[100],i=0;
    while(str[i] != '\0'){
        char next = str[i];
        if(next == '*'){
            pop(stack);
        }
        else{
            push(stack,next);
        }
        i++;
    }
    char a[top+1];
    while(top != -1){
        a[top]=pop(stack);
    }
    puts(a);
}
