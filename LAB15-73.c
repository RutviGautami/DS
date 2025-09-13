#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lptr;
    int info;
    struct node *rptr;
};

struct node *l = NULL;
struct node *r = NULL;
struct node *temp = NULL;

void createdouble(int n){

    for(int i=0;i<n;i++){
        int x;
        struct node *new=(struct node *)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        new->info = x;

        if(l == NULL){
            new->lptr = NULL;
            new->rptr = NULL;
            l = new;
            temp = l;
        }

        else if(i == n-1){
            temp->rptr = new;
            new->lptr = temp;
            new->rptr = NULL;
            temp = new;
            r = new;
        }

        else{
            temp->rptr = new;
            new->lptr = temp;
            temp = new;
        }
    }
    temp = l;
}

void deleteAlternate(int n){
    temp = l;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            if(i == n){
                r = r->lptr;
                r->rptr = NULL;
                printf("deleted successfully\n");
                return;
            }      
            temp->lptr->rptr = temp->rptr;
            temp->rptr->lptr = temp->lptr; 
        }
        temp = temp->rptr;
        
    }
    
    printf("deleted successfully\n");
}



void display(){
    temp = l;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ",temp->info);
        temp = temp->rptr;
    }
    temp = r;
    printf("\nBackward: ");
    while(temp != NULL){
        printf("%d ",temp->info);
        temp = temp->lptr;
    }
}

void main(){
    int n;
    printf("Enter size of doubly linked list: ");
    scanf("%d",&n);
    printf("Enter doubly linked list\n");
    createdouble(n);
    deletespecific(n);
    display();
}