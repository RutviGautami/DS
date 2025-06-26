#include<stdio.h>
int main(){
    int n,reverse=0;
    scanf("%d",&n);
    for(int i=n;i<=1;i=i/10){
        reverse=reverse*10+(n%10);
    }
    printf("%d",reverse);
}