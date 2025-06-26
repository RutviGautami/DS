#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first=NULL;

void insertAtFirst(){
    int x;
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    printf("enter value to insert at first: ");
    scanf("%d",&x);
    newnode->info = x;
    newnode->link = first;
    first = newnode;

}
void insertAtLast(){
    int x;
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    printf("enter value to insert at last: ");
    scanf("%d",&x);
    newnode->info = x;
    if(first==NULL){
        newnode->link = NULL;
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
}

void deleteFirst(){
    struct node *save;
    save=first;
    first->link=first;
    free(save);
    printf("deleted\n");
}

void deleteLast(){
    struct node *save,*pred;
    save=first;
    pred=first;
    while (save!=NULL)
    {
        pred=save;
        save = save -> link;
    }
    pred->link=NULL;
    free(save);
    printf("deleted\n");
}

void deleteSpecific(){
    struct node *newnode;
    scanf("%d",&newnode->link);
    struct node *save,*pred;
    save=first;
    pred=first;
    while (save!=newnode->link)
    {
        pred=save;
        save = save -> link;
    }
    pred->link=save->link;
    free(save);
    printf("deleted\n");
}

void display(){
    if(first==NULL){
        printf("is empty");
    }
    else{
        while (first->link!=NULL)
        {
            printf("%d,",first->info);
            first = first -> link;
        } 
        printf("\n");
    }
    
}

void count(){
    int count=0;
    while (first!=NULL)
    {
        count++;
        first = first -> link;
    }
    printf("%d\n",count);   
}

void main(){
    int choice;
    do{
        printf("enter 1 to insert at first\n");
        printf("enter 2 to insert at last\n");
        printf("enter 3 to delet at first\n");
        printf("enter 4 to delet at last\n");
        printf("enter 5 to delet at specific position\n");
        printf("enter 6 to print list\n");
        printf("enter 7 for number of element\n");
        printf("enter 0 to end programe\n");
        printf("enter: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertAtFirst();
                    break;
            case 2: insertAtLast();
                    break;
            case 3: deleteFirst();
                    break;
            case 4: deleteLast();
                    break;
            case 5: deleteSpecific();
                    break;
            case 6: display();
                    break;
            case 7: count();
                    break;
            case 0: break;
    }

    }
    while(choice!=0);
}