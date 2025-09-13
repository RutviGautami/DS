#include <stdio.h>

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
    char stack1[100],stack2[100],i=0;
    while(str[i] == str[i+1]){
        push(stack1,str[i++]);
    }
    push(stack1,str[i++]);
    int top1 = top+1;
    top = -1;
    while(str[i] == str[i+1]){
        push(stack2,str[i++]);
    }
    push(stack1,str[i++]);
    int top2 = top+1;
    if(str[i] == '\0' && top1 == top2){
        printf("Valid");
    }
    else{
       printf("Invalid"); 
    } 
}
