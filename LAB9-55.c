#include<stdio.h>
#include<stdlib.h>

struct student{
    int roll_no;
    char name[100];
    char branch[10];
    int batch_no;
};

void main(){
    int n;
    printf("Enter number of: ");
    scanf("%d",&n);
    struct student *iptr =(struct student *)malloc(n*sizeof(struct student));

    for(int i=0;i<n;i++){
        scanf("%d",&(iptr+i)->roll_no);
        scanf("%s",&(iptr+i)->name);
        scanf("%s",&(iptr+i)->branch);
        scanf("%d",&(iptr+i)->batch_no);
    }

    for (int i = 0; i < n; i++) {
    printf("%d,", (iptr + i)->roll_no);
    printf("%s,", (iptr + i)->name);
    printf("%s,", (iptr + i)->branch);
    printf("%d\n", (iptr + i)->batch_no);
    }
}