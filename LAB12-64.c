 #include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node *createlist(int n){
    struct node *first = NULL;
    struct node *temp = NULL;
    struct node *save = NULL;
    for(int i=0;i<n;i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&(temp->info));
        temp->link = NULL;
        if(first==NULL){
            first = temp;
            save=first;
        }
        else {
            save->link = temp;
            save=temp;
        }

        temp = NULL;
    }
    return first;
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    
    //take first elment from current and store it to prev as first node
    while (current != NULL) {
        next = current->link;   // Store next node
        current->link = prev;   // Reverse current node's pointer
        prev = current;         // Move prev to current
        current = next;         // Move to next node4
    }
    return prev; // New head of the reversed list
}    

void display(struct node *first) {
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

int main(){
    int n;
    printf("Enter size of list: ");
    scanf("%d",&n);
    struct node *list=NULL;
    list=createlist(n);
    list=reverse(list);
    display(list);

}