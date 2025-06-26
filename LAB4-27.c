#include<stdio.h>
int main(){
    int n,value,location;
    scanf("%d %d",&n,&value);
    int a[50];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]==value){
            location = i;
            break;
        }
    }
    for(int i=location;i<n-1;i++){
        a[i]=a[i+1];
    }
    for(int i=0;i<n-1;i++){
        printf("%d,",a[i]);
    }

}