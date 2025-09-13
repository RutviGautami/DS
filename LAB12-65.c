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

struct node* exchange(struct node* head,int k,int n) {
    if (k <= 0 || k > n) {
        printf("Invalid value of k.\n");
        return head;
    }

    struct node *x_prev=NULL;
    struct node *x=head;
    struct node *y_prev=NULL;
    struct node *y=head;

    for(int i=1;i<k;i++){
        x_prev = x;
        x = x->link;
    }
    for(int i=1;i<n-k+1;i++){
        y_prev = y;
        y = y->link;
    }
    if(x == y){
        return head;
    }
    // Swap two nodes x and y by adjusting links
    if (x_prev!=NULL) x_prev->link = y;
    else head = y;

    if (y_prev!=NULL) y_prev->link = x;
    else head = x;

    // Swap next pointers
    struct node* temp = x->link;
    x->link = y->link;
    y->link = temp;

    return head;
   
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
    int k;
    printf("Enter k: ");
    scanf("%d",&k);
    struct node *list=NULL;
    list=createlist(n);
    list=exchange(list,k,n);
    display(list);

}