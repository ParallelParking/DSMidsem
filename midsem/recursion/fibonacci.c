#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n == 1 || n == 0)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    printf("%d", fibonacci(7));
    return 0;
}