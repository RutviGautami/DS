#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first=NULL;
struct node *last=NULL;

void createcircular(int n){
    struct node *temp=NULL;

    for(int i=0;i<n;i++){
        int x;
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        newnode->info = x;
        newnode->link = NULL;
        if(first == NULL){
            first = newnode;
            temp = first;
        }
        else{
            temp->link = newnode;
            temp = newnode;
        }
    }
    last = temp;
    last->link = first;
}

void insertatfront(){
    int x;
    printf("Enter value you want to insert at first: ");
    scanf("%d",&x);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;
    last->link = newnode;
    newnode->link = first;
    first = newnode;
    printf("Insert at front successfully\n");
}

void insertatend(){
    int x;
    printf("Enter value you want to insert at end: ");
    scanf("%d",&x);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;
    last->link = newnode;
    newnode->link = first;
    last = newnode;
    printf("Insert at end successfully\n");
}

void deletespecific(){
    int x;
    printf("Enter value you want to delete: ");
    scanf("%d",&x);
    struct node *temp=first;
    do{
        temp = temp->link;
    }
    while(temp->link->info != x && temp !=first);

    if(temp->link->link == first){
        temp->link = temp->link->link;
        first = temp->link;
    }
    else if(temp->link->link == last){
        temp->link = temp->link->link;
        last = temp;
    }
    else{
        temp->link = temp->link->link;
    }
    printf("deleted successfully\n");
}

void display(){
    struct node *temp=first;
    do{
        printf("%d->",temp->info);
        temp=temp->link;
    }while(temp != first);
    printf("(back to %d)",first->info);
}
   
void main(){
    int n;
    printf("Enter size of circular linked list: ");
    scanf("%d",&n);
    printf("Enter list \n");
    createcircular(n);
    insertatfront();
    insertatend();
    deletespecific();
    display();
}