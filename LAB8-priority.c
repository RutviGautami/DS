#include <stdio.h>

struct PriorityQueue{
    int value;
    int priority;
};

int front = -1;
int rear = -1;

void enqueue(struct PriorityQueue queue[],struct PriorityQueue x,int n){
    if(rear > n){
        printf("queue overflow\n");
        return;
    }
    queue[++rear] = x;
    if(front == -1){
        front = 0;
    }
}

int dequeue(struct PriorityQueue queue[]) {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }

    int minIndex = front;
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i].priority < queue[minIndex].priority) {
            minIndex = i;
        }
    }

    int val = queue[minIndex].value;

    // Shift elements to fill the gap
    for (int i = minIndex; i < rear; i++) {
        queue[i] = queue[i + 1];
    }

    rear--;
    if (rear < front) {
        front = -1;
        rear = -1;
    }

    return val;
}

void display(struct PriorityQueue queue[]){
    for(int i=front;i<=rear;i++){
        printf("%d,",queue[i].value);
    }
    return;
}

void main(){
    int n;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    struct PriorityQueue queue[n];
    int check=0;
    struct PriorityQueue x;
    
    while(check==1 || check ==0){
        printf("Enter 0 to enqueue \n1 to dequeue \nany other key to exit:\n");
        scanf("%d",&check);
        switch(check){
            case 0: printf("Enter element you want to enqueue and its priority: ");
                    scanf("%d",&x.value);
                    scanf("%d",&x.priority);
                    enqueue(queue,x,n);
                    break;
            case 1: printf("%d dequeueed\n",dequeue(queue));
                    break;
        }
    }
    display(queue);
}