#include<stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack *adrs;
};

struct stack *createnode(int n){
    struct stack *top=NULL;
    struct stack *save=NULL;
    struct stack *temp=NULL;
    for(int i=0;i<n;i++){
        temp = (struct stack*)malloc(sizeof(struct stack));
        scanf("%d",&(temp->data));
        temp->adrs = top;
        top = temp;
    }
    return top;
}

struct stack *push(struct stack *top,int value) {
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    if (!temp) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    temp->data = value;
    temp->adrs = top;
    top = temp;
    printf("%d pushed to stack\n", value);
    return top;
}

// Pop operation
struct stack *pop(struct stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }

    struct stack* temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->adrs;
    free(temp);
    return top;
}

// Peek operation
struct stack *peek(struct stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return NULL;
    }
    printf("Top element: %d\n", top->data);
    return top;
}

// Display all elements in the stack
void display(struct stack *top) {
    struct stack* temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->adrs;
    }
    printf("\n");
}

void freeStack(struct stack *top) {
    struct stack *temp;
    while (top != NULL) {
        temp = top;
        top = top->adrs;
        free(temp);
    }
}


int main(){
    int n;
    printf("Enter size of list: ");
    scanf("%d",&n);
    struct stack *st=NULL;
    printf("enter elements in ascending order\n");
    st = createnode(n);

    int choice, value;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                st=push(st,value);
                break;

            case 2:
                st=pop(st);
                break;

            case 3:
                st=peek(st);
                break;

            case 4:
                display(st);
                break;

            case 5:
                freeStack(st);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}