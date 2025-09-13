#include<stdio.h>
#include<string.h>

char revpolish[100];
int polishtop = 0;
int top = -1;
int r=0;

void push(char stack[],char x){
    stack[++top] = x;
}

int pop(char stack[]){
    return stack[top--];
}

int input_precedence(char c){
    if(c=='+'||c=='-'){
        return 2;
    }
    else if(c=='*'||c=='/'){
        return 4;
    }
    else if(c=='^'){
        return 5;
    }
    else if(c=='('){
        return 9;
    }
    else if(c==')'){
        return 0;
    }
    else{
        return 7;
    }
}

int stack_precedence(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 3;
    }
    else if(c=='^'){
        return 6;
    }
    else if(c=='('){
        return 0;
    }
    else{
        return 8;
    }
}

int rank(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return -1;
    }
    else{
        return 1;
    }
}

void postfixfun(char stack[],char str[]){
    int i=0;
    strcat(str,")");
    char next;
    while(str[i] != '\0'){
        next = str[i];
        if(top<0){
            printf("invalid expression");
            return;
        }
        while(stack_precedence(stack[top])>input_precedence(next)){
            char temp = pop(stack);
            revpolish[polishtop++]=temp;
            r = r+rank(temp);
            if(r<1){
                printf("invalid");
                return;
            }
        }
        if(stack_precedence(stack[top])!=input_precedence(next)){
            push(stack,next);
        }
        else{
            pop(stack);
        }
        i++;
    }
    if(top!=-1 || r!=1){
        printf("invalid not possible\n");
    }
    else{
        for(int i=polishtop;i>=0;i--){
            printf("%c",revpolish[i]);
        }
        printf("\n");
    }
}

void main(){
    char infix[100];
    printf("Enter infix string: ");
    gets(infix);
    strrev(infix);
    char stack[100];
    push(stack,'(');
    postfixfun(stack,infix);
}