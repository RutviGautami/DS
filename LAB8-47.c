#include <stdio.h>

int rear= -1;
int front = -1;

void insert(int queue[],int x,int n){
    if(rear == n){
        rear = 0;
    }
    else{
        rear++;
    }
    if(rear == front){
        printf("queue overflow\n");
        return;
    }
    queue[rear] = x;
    if(front == -1){
        front = 0;
    }
}

int delete(int queue[],int n){
    if(front == -1){
        printf("queue underflow\n");
        return -1; 
    }
    int y = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
        return y;
    }
    if(front == n){
        front = 0;
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
        printf("Enter 0 to insert \n1 to delete \nany other key to exit:\n");
        scanf("%d",&check);
        switch(check){
            case 0: printf("Enter element you want to insert: ");
                    scanf("%d",&x);
                    insert(queue,x,n);
                    break;
            case 1: printf("%d deleteed\n",delete(queue,n));
                    break;
        }
    }
    display(queue);
}