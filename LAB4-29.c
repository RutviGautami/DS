#include<stdio.h>
int main(){
    int n1,n2,k=0;
    scanf("%d %d",&n1,&n2);
    int a[n1+n2];
    int b[n2];
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    for(int i=n1;i<n1+n2;i++){
            a[i]=b[k];
            k++;
    }
    for(int i=0;i<n1+n2;i++){
        printf("%d,",a[i]);
    }

}