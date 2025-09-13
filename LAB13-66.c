#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first = NULL;

struct node *insertAtLast(int x){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if(first==NULL){
        first = newnode;
    }
    else{
        struct node *save;
        save = first;
        while (save->link!=NULL)
        {
            save = save -> link;
        }
        save->link = newnode;
    }
    return newnode;   
}

void insertAtFirst(int x){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    first = newnode;  
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

void main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);

        if (first == NULL) {
            insertAtFirst(x);
        } else if (x < first->info) {
            insertAtFirst(x);
        } else {
            struct node *temp = first;
            while (temp->link != NULL && temp->link->info < x) {
                temp = temp->link;
            }

            if (temp->link == NULL) {
                insertAtLast(x);
            } else {
                insertbetween(temp,x);
            }
        }
    }

    display();
}


