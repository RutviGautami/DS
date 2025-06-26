#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("Enter size of string: ");
    scanf("%d",&n);
    char *iptr=(char *)malloc(n*sizeof(char));
    scanf("%s",iptr);

    int count=0;
    
    for(int i=0;i<=n/2;i++){
        if((*(iptr+i))!=(*(iptr+n-i-1))){
            count++;
            break;
        }
    }
    if(count==0){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }
}