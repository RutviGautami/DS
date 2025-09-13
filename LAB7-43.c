#include<stdio.h>
#include<string.h>
#include<ctype.h>

int top = -1;

void push(int stack[],int x){
    stack[++top] = x;
}

int pop(int stack[]){
    return stack[top--];
}

int evalution_postfix(char postfix[]){
    int i=0,o1,o2;
    int value = 0;
    int stack[100];
    while(postfix[i] != '\0'){
        int temp = postfix[i];
        if(isdigit(temp)){
            push(stack,(temp-48));
        }
        else if(temp == '+'){
            o2 = pop(stack);
            o1 = pop(stack);
            int ans = o1+o2;
            push(stack,ans);
        }
        else if(temp == '-'){
            o2 = pop(stack);
            o1 = pop(stack);
            int ans = o1-o2;
            push(stack,ans);
        }
        else if(temp == '/'){
            o2 = pop(stack);
            o1 = pop(stack);
            int ans = o1/o2;
            push(stack,ans);
        }
        else if(temp == '*'){
            o2 = pop(stack);
            o1 = pop(stack);
            int ans = o1*o2;
            push(stack,ans);
        }
        else if(temp == '^'){
            o2 = pop(stack);
            o1 = pop(stack);
            int ans = 1;
            for(int j=0;j<o2;j++){
                ans = ans*o1;
            }
            push(stack,ans);
        }
        i++;
    }
    return pop(stack);
}

void main(){
    char postfix[100];
    printf("enter postfix string: ");
    gets(postfix);
    int answer = evalution_postfix(postfix);
    printf("%d",answer);
}