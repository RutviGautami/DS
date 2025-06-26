# include<stdio.h>
int main(){
    int n,small,large;
    scanf("%d %d",&m,&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    small=a[0];
    large=a[0];
    for(int i=1;i<n;i++){
        if(small>a[i]){
            small=a[i];
        }
        if(large<a[i]){
            large=a[i];
        }
    }
    printf("small=%d,large=%d",small,large);
    
}