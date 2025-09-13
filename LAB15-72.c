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

void insertatfront(){
    printf("insert value you want to insert at front: ");
    int x;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&x);
    new->info = x;
    new->lptr = NULL;
    new ->rptr = l;

     if (l != NULL) {
        l->lptr = new;
    } 
    else {
        r = new; // if list was empty
    }
    
    l = new;
    printf("Insert successfully\n");
}

void insertatend(){
    printf("insert value you want to insert at end: ");
    int x;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&x);
    new->info = x;
    new->lptr = r;
    new ->rptr = NULL;

    if (r != NULL) {
        r->rptr = new;
    } 
    else {
        l = new; // if list was empty
    }

    r = new;
    printf("Insert successfully\n");
}

void deletespecific(int n){
    printf("Enter element no you want to delete: ");
    int x;
    scanf("%d",&x);
    temp = l;
    if(x == 1){
        l = l->rptr;
        l->lptr = NULL;
        printf("deleted successfully\n");
        return;
    }
    if(x == n){
        r = r->lptr;
        r->rptr = NULL;
        printf("deleted successfully\n");
        return;
    }
    for(int i=0;i<x-1;i++){
        if(i == n){
            printf("Element not found\n");
            return;
        }
        else{
            temp = temp->rptr;
        }
    }
    temp->lptr->rptr = temp->rptr;
    temp->rptr->lptr = temp->lptr;
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
    insertatfront();
    n++;
    insertatend();
    n++;
    deletespecific(n);
    n--;
    display();
}