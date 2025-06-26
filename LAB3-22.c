#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int rows;
    scanf("%d",&rows);
    for (int i = 0; i < rows; i++) {
        for (int space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d  ", factorial(i) / (factorial(j) * factorial(i - j)));
        }
        printf("\n");
    }

    return 0;
}
