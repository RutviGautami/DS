#include<stdio.h>
#include<stdlib.h>


void main(){
    int *iptr=(int *)malloc(sizeof(int));
    char *cptr=(char *)malloc(sizeof(char));
    float *fptr=(float *)malloc(sizeof(float));

    if(iptr && cptr && fptr){
        *iptr=22;
        *cptr='R';
        *fptr=246.57;
        printf("%d,%c,%f",*iptr,*cptr,*fptr);
        free(iptr);
        free(cptr);
        free(fptr);
    }
    else{
        printf("not allocate");
    }
}