#include<stdio.h>
int Isprime(int n){
    int count=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
            break;
        }
    }
    if(count==0){
        return 1;
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        if(Isprime(i)==1){
            printf("%d,",i);
        }
    }
}