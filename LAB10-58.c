#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nextadd;
};

struct node *createlist(int n){
    struct node *first = NULL;
    struct node *temp = NULL;
    struct node *save = NULL;
    for(int i=0;i<n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&(temp->data));
        temp->nextadd = NULL;
        if(first==NULL){
            first = temp;
            save=first;
        }
        else {
            save->nextadd = temp;
            save=temp;
        }

        temp = NULL;
    }
    return first;
}

int areEqual(struct node* head1, struct node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data){
            return 0;
        }
            head1 = head1->nextadd;
            head2 = head2->nextadd;
    }
    return (head1 == NULL && head2 == NULL);
}

int main(){
    int n1,n2;
    printf("enter n1 n2: ");
    scanf("%d %d",&n1,&n2);
    if(n1==n2){
        struct node *list1 = NULL;
        struct node *list2 = NULL;
        printf("Enter first link list:\n");
        list1 = createlist(n1);
        
        printf("Enter second link list:\n");
        list2 = createlist(n2);
        
        if(areEqual(list1,list2)){
            printf("is same");
        }
        else{
            printf("not same");
        }

    }
    else{
        printf("sizes are not same");
    }
    return 0;
}