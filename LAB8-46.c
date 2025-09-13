#include <stdio.h>

int rear= -1;
int front = -1;

void enqueue(int queue[],int x,int n){
    if(rear > n){
        printf("queue overflow\n");
        return;
    }
    queue[++rear] = x;
    if(front == -1){
        front = 0;
    }
}

int dequeue(int queue[]){
    if(rear<0){
        printf("queue underflow\n");
        return 0; 
    }
    int y = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
    return y;
}

void display(int queue[]){
    for(int i=front;i<=rear;i++){
        printf("%d,",queue[i]);
    }
    return;
}

void main(){
    int n;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    int queue[n];
    int check=0,x;
    while(check==1 || check ==0){
        printf("Enter 0 to enqueue \n1 to dequeue \nany other key to exit:\n");
        scanf("%d",&check);
        switch(check){
            case 0: printf("Enter element you want to enqueue: ");
                    scanf("%d",&x);
                    enqueue(queue,x,n);
                    break;
            case 1: printf("%d dequeueed\n",dequeue(queue));
                    break;
        }
    }
    display(queue);
}