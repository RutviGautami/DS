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

struct node *copy(struct node *list){
    struct node *firstlist = list;
    struct node *first=NULL;
    struct node *temp = NULL;
    struct node *save = NULL;
    while(list!=0){
        temp=(struct node*)malloc(sizeof(struct node));
        temp->info = list->info;
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
        list=list->link;
    }
    return first;
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
    struct node *copylist=NULL;
    copylist=copy(list);
    display(copylist);

}