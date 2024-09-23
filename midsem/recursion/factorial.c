#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 1) 
        return n;
    return n * factorial(n - 1);
}

int main() {
    printf("%d", factorial(5));
    return 0;
}