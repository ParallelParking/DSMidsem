#include <stdio.h>
#include <stdlib.h>

void hanoi(int discCount, char source, char buffer, char destination) {
    if (discCount == 0)
        return;
    hanoi(discCount - 1, source, destination, buffer); //move from source to buffer.
    printf("Moved %d from %c to %c\n", discCount, source, destination);
    hanoi(discCount - 1, buffer, source, destination); //move from buffer to destination
}

int main() {
    hanoi(4, 'A', 'B', 'C');
    return 0;
}