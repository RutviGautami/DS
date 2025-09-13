#include<stdio.h>
#include<stdlib.h> 

int s[100];
int b[100];

void push(int stack[],int x,int top){
    stack[++top] = x;
}

int pop(int stack[],int top){
    return stack[top--];
}

void performoperation(int a[],int k){
    int topofs = -1;
    int topofb = -1;
    for(int i=0;i<k;i++){
        push(s,a[i],topofs);
        if(a[i]<a[i+1]){
            push(b,pop(s,topofs),topofb);
        }
    }
}

void main(){
     int n;
     prinf("Enter number of test case: ");
     scanf("%d",&n);
     for(int i=0;i<n;i++){
        int k;
        prinf("Enter size of array: ");
        scanf("%d",&k);
        int a[k];
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        performoperation(a,k);
     }
}