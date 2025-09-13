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

int evalution_prefix(char prefix[]){
    int i=0,o1,o2;
    int value = 0;
    int stack[100];
    while(prefix[i] != '\0'){
        int temp = prefix[i];
        if(isdigit(temp)){
            push(stack,(temp-48));
        }
        else if(temp == '+'){
            o1 = pop(stack);
            o2 = pop(stack);
            int ans = o1+o2;
            push(stack,ans);
        }
        else if(temp == '-'){
            o1 = pop(stack);
            o2 = pop(stack);
            int ans = o1-o2;
            push(stack,ans);
        }
        else if(temp == '/'){
            o1 = pop(stack);
            o2 = pop(stack);
            int ans = o1/o2;
            push(stack,ans);
        }
        else if(temp == '*'){
            o1 = pop(stack);
            o2 = pop(stack);
            int ans = o1*o2;
            push(stack,ans);
        }
        else if(temp == '^'){
            o1 = pop(stack);
            o2 = pop(stack);
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
    char prefix[100];
    printf("enter prefix string: ");
    gets(prefix);
    strrev(prefix);
    int answer = evalution_prefix(prefix);
    printf("%d",answer);
}