#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear = -1;

void insertfront(int queue[],int x,int n){
    if(front == 0){
        printf("Overflow"); 
        return;   
    }
    if(front == -1){
        front = rear = 0;
    }
    else{
        front--;
    }
    queue[front] = x;
    return;
}

void insertrear(int queue[],int x,int n){
    if(rear > n){
        printf("queue overflow\n");
        return;
    }
    queue[++rear] = x;
    if(front == -1){
        front = 0;
    }
}
int deletefront(int queue[]){
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

int deleterear(int queue[]){
    if(rear == -1){
        prntf("Underflow");
        return -1;
    }
    int y = queue[rear];
    if(rear == front){
        rear = front = -1;
    }
    else{
        rear--;
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
        printf("Enter \n0 to insert at front \n1 to insert at rear \n2 to delete from front \n3 to delete from rear\nany other key to exit:\n");
        scanf("%d",&check);
        switch(check){
            case 0: printf("Enter element you want to insertfront: ");
                    scanf("%d",&x);
                    insertfront(queue,x,n);
                    break;
            case 1: printf("Enter element you want to insertrear: ");
                    scanf("%d",&x);
                    insertrear(queue,x,n);
                    break;
            case 2: printf("%d dequeueed\n",deletefront(queue));
                    break;
            case 3: printf("%d dequeueed\n",deleterear(queue));
                    break;
        }
    }
    display(queue);
}
