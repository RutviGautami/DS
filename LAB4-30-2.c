#include <stdio.h>

int main() {
    char c[100];
    gets(c);

    for(int i=0;c[i]!='\0';i++){
       if (c[i] >= 'a' && c[i] <= 'z') {
        c[i] = c[i] - 32;
       }
    }
    puts(c);
}
