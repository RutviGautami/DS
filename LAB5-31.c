#include<stdio.h>

int array(int n[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&n[i][j]);
        }
    }
    return n;
}
int main(){
    int a[2][2],b[2][2],c[2][2];
    printf("first array: ");
    array(a);
    printf("second array: ");
    array(b);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}