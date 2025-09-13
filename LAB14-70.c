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

void display(struct node *tempfirst){
    struct node *temp=tempfirst;
    do{
        printf("%d->",temp->info);
        temp=temp->link;
    }while(temp != tempfirst );
    printf("(back to %d)\n",tempfirst->info);
}

void main(){
    int n;
    printf("Enter size of circular linked list: ");
    scanf("%d",&n);
    printf("Enter list \n");
    createcircular(n);
    struct node *temp=first;
    if(n%2==1){
        for(int i=0;i<n/2;i++){
            temp=temp->link;
        } 
    }
    if(n%2==0){
        for(int i=1;i<n/2;i++){
            temp=temp->link;
        } 
    }
    
    struct node *firstsh=temp->link;
    temp->link=first;
    display(first); 
    last->link = firstsh;
    display(firstsh);
}