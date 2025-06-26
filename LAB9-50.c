#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter size of a: ");
    scanf("%d",&n);
    int *iptr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",(iptr+i));
    }
    for(int i=0;i<n;i++){
        printf("%d,",*(iptr+i));
    }
}