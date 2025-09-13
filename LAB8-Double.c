#include <stdio.h>

int rear= -1;
int front = -1;

void insertAtRear(int queue[],int x,int n){
    if(rear > n){
        printf("queue overflow\n");
        return;
    }
    queue[++rear] = x;
    if(front == -1){
        front = 0;
    }
}
void insertAtFront(int queue[],int x,int n){
    if(front == 0){
        printf("queue overflow\n");
        return;
    }
    if(front == -1) front = rear = 1;
    else front--;
    queue[front] = x;
    return;
}

int deleteFromFront(int queue[]){
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

int deleteFromRear(int queue[]){
    if(rear == 0){
        printf("queue underflow\n");
        return 0; 
    }
    int y = queue[rear];
    if(front == rear) front = rear = -1;
    else rear--;
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
        printf("Enter 0 to insertAtRear \n1 to deleteFromFront \nany other key to exit:\n");
        scanf("%d",&check);
        switch(check){
            case 0: printf("Enter element you want to insertAtRear: ");
                    scanf("%d",&x);
                    insertAtRear(queue,x,n);
                    break;
            case 1: printf("%d deleteFromFront\n",deleteFromFront(queue));
                    break;
            case 2: printf("Enter element you want to insertAtFront: ");
                    scanf("%d",&x);
                    insertAtFront(queue,x,n);
                    break;
            case 3: printf("%d deleteFromRear\n",deleteFromRear(queue));
                    break;
        }
    }
    display(queue);
}