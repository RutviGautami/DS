//by exchanging values we put simmilar values in last last place and when n-- the last value will not display
//j-- for now the values are replace with its before value
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[50];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(int p=j;p<n;p++){
                    a[p]=a[p+1]+a[p];
                    a[p+1]=a[p]-a[p+1];
                    a[p]=a[p]-a[p+1];
                }
                n--;
                j--;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }

}