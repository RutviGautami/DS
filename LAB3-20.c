# include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                flag=1;
                break;
            }
        }
    }
    if(flag==1){
        printf("has duplicate");
    }
    if(flag==0){
        printf("not has duplicate");
    }
}