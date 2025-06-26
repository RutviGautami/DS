#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,sum=0;
    printf("Enter size of a: ");
    scanf("%d",&n);
    int *iptr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",(iptr+i));
        sum+=*(iptr+i);
    }
    printf("%d,",sum);
}