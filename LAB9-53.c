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
    for(int k=0;k<n;k++){
        for(int i=0;i<n-1;i++){
            if(*(iptr+i)>*(iptr+i+1)){
                int temp=*(iptr+i);
                *(iptr+i)=*(iptr+i+1);
                *(iptr+i+1)=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d,",*(iptr+i));
    }
}