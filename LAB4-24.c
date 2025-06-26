#include<stdio.h>
int main(){
    int n,location,value;
    scanf("%d %d %d",&n,&location,&value);
    int a[50];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n-1;i>=location;i--){
        a[i+1]=a[i];
    }
    a[location]=value;
    for(int i=0;i<n+1;i++){
        printf("%d,",a[i]);
    }

}