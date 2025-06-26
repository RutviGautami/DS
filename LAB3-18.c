# include<stdio.h>
int main(){
    int m,n,sum=0;
    scanf("%d %d",&m,&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<=m;i++){
        sum=sum+a[i];
    }
    printf("%f",((float)sum/(m+1)));
    
}