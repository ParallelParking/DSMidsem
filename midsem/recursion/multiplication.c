#include <stdio.h>
#include <stdlib.h>

int multiplication(int m, int q) {
    if (q == 1)
        return m;
    return m + multiplication(m, q - 1);
}

int main() {
    printf("%d", multiplication(5, 4));
    return 0;
}