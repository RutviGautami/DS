#include <stdio.h>
#include <stdlib.h>

struct queue{
    int info;
    struct queue *nxtque;
};
    struct queue *front=NULL;
    struct queue *rear=NULL;

void createqueue(int n){
    
    struct queue *temp=NULL;
    
    for(int i=0;i<n;i++){
        temp = (struct queue*)malloc(sizeof(struct queue));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("Enter element %d: ",i+1);
        scanf("%d",&(temp->info));
        temp->nxtque=NULL;
        if(front == NULL){
            front = temp;
            rear = front;
        }
        else{
            rear->nxtque = temp;
            rear = temp;
        }
        temp = NULL;
    }
}

void Enqueue(){
    struct queue *new=(struct queue*)malloc(sizeof(struct queue));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter element you want to enqueue: ");
    scanf("%d",&(new->info));
    new->nxtque = NULL;
    if(front == NULL){
       front=new;
       rear = front;
       return;
    }
    rear->nxtque = new;
    rear = new;
    printf("Enqueued successfully.\n");
}

void Dequeue(){
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct queue *temp = front;
    front = front->nxtque;
    free(temp);
    if (front == NULL)
        rear = NULL;
    printf("Dequeued successfully.\n");
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct queue *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->nxtque;
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("enter elements of queue\n");
    createqueue(n);
    Enqueue();
    Dequeue();
    display();
}