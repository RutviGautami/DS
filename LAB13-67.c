#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first = NULL;

void createlist(int n){
    struct node *save=NULL;
    struct node *temp=NULL;
    for(int i=0;i<n;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&(temp->info));
        temp->link=NULL;
        if(first == NULL){
            first = temp;
            save = first;
        }
        else{
            save->link = temp;
            save = temp;
        }
        temp = NULL;
    }
}

void insertbetween(struct node *temp, int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = temp->link;
    temp->link = newnode;
}

void display() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = first;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int GCD(int x,int y){
    int gcd=1;
    for(int i=2;i<=x && i<=y;i++){
        if(x%i==0 && y%i==0){
             gcd=i;
        }
    }
    return gcd;
}

void main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    createlist(n);
    struct node *current=first->link;
    struct node *prev=first;
    for(int i=1;i<n;i++){
        insertbetween(prev,GCD(current->info,prev->info));
        prev=current;
        current=current->link;
    }

    display();
}


