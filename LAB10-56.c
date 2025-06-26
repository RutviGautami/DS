#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *first=NULL;

void main(){
    struct node *newnode =(struct node *)malloc(sizeof(struct node));
    newnode->info=5;
    newnode->link=NULL;
    printf("%d\n",newnode->info);
    printf("%d\n",newnode->link);
}