#include <stdio.h>
#include <string.h>

#define MAX 100

char revpolish[MAX];      // Postfix output
int polishtop = 0;        // Index for revpolish
int r = 0;                // Rank tracker

int stackTop = -1;        // Separate top for operator stack

// Push to stack
void push(char stack[], char x) {
    stack[++stackTop] = x;
}

// Pop from stack
char pop(char stack[]) {
    return stack[stackTop--];
}

// Input precedence
int input_precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7; // Operand
    }
}

// Stack precedence
int stack_precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default: return 8; // Operand
    }
}

// Rank of symbol
int rank(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return -1;
    else
        return 1;
}

void postfixfun(char stack[], char str[]) {
    int i = 0;
    char next;

    while ((next = str[i]) != '\0') {
        while (stackTop >= 0 && stack_precedence(stack[stackTop]) > input_precedence(next)) {
            char temp = pop(stack);
            revpolish[polishtop++] = temp;
            r += rank(temp);
            if (r < 1) {
                printf("Invalid expression (rank error)\n");
                return;
            }
        }

        if (stackTop >= 0 && stack_precedence(stack[stackTop]) != input_precedence(next)) {
            push(stack, next);
        } else {
            pop(stack); // Matching parentheses
        }

        i++; 
    }

    // Final validation
    if (stackTop != -1 || r != 1) {
        printf("Invalid expression (stack/rank mismatch)\n");
    } else {
        printf("Postfix expression: ");
        for (int i = 0; i < polishtop; i++) {
            printf("%c", revpolish[i]);
        }
        printf("\n");
    }
}

// Entry point
int main() {
    char infix[MAX];
    char stack[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove newline if present
    size_t len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    // Initialize stack with '(' and append ')' to infix
    push(stack, '(');
    strcat(infix, ")");

    postfixfun(stack, infix);

    return 0;
}