#include<stdio.h>

int top=-1;

void push(char stack[],char x){
    stack[++top] = x;
}

char pop(char stack[]){
    return stack[top--];
}

char change(char s){
    if(s == ']'){
        return '[';
    }
    else if(s == '}'){
        return '{';
    }
    else{
        return '(';
    }
}

void main(){
    char str[100];
    gets(str);
    char stack[100],i=0;
    while(str[i] != '\0'){
        char next = str[i];
        if(change(next) == stack[top]){
            pop(stack);
        }
        else{
            push(stack,next);
        }
        i++;
    }
    if(top != -1){
        printf("0");
    }
    else{
        printf("1");
    }
}
