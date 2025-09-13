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

//... → [prev] → [current] → [next] → ...
//... → [prev] → [next] → [current] → ...
void swap(struct node *prev, struct node *current) {
    struct node *next = current->link;

    if (next == NULL) { 
        return;
    }
    current->link = next->link;
    next->link = current;
    if (prev != NULL){
        prev->link = next;
    }
    else{
        first = next;
    }
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
    createlist(n);
    struct node *current=first ;
    struct node *prev=NULL;
    
      while (current != NULL && current->link != NULL) {
        swap(prev, current);

        // After swapping:
        // - current is now the second node in the pair
        // - next swap starts two nodes ahead
        prev = current;
        current = current->link;
    }
    display();
}


