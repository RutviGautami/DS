#include <stdio.h>
#include <math.h>

int main() {
    int num, originalNum, remainder, result, n, count;
    for (num = 1; num <= 1000; num++) {
        originalNum = num;
        count = 0;
        result = 0;
        while (originalNum != 0) {
            originalNum /= 10;
            ++count;
        }
        originalNum = num;
        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += pow(remainder, count);
            originalNum /= 10;
        }
        if (result == num)
            printf("%d ", num);
    }
    return 0;
}
