# include<stdio.h>
int main(){
    int m,n,p,sum=0;
    scanf("%d %d %d",&m,&n,&p);
    int a[p];
    for(int i=0;i<p;i++){
        scanf("%d",&a[i]);
    }
    int j;
    for(j=0;j<p;j++){
        if(m==a[j]){
            a[j]=n;
            break;
        }
    }
    printf("%d \n",j);
    for(int k=0;k<p;k++){
        printf("%d ,",a[k]);
    }
}