# include<stdio.h>
int check(int b,int p,int a[p]){
    for(int i=0;i<p;i++){
        if(b==a[i]){
            b=i;
            break;
        }
    }
    return b;
}
int main(){
    int m,n,p,sum=0;
    scanf("%d %d %d",&m,&n,&p);
    int a[p];
    for(int i=0;i<p;i++){
        scanf("%d",&a[i]);
    }
    m=check(m,p,a);
    n=check(n,p,a);
    for(int j=m;j<=n;j++){
        sum=sum+a[j];
    }
    printf("%d",sum);
}