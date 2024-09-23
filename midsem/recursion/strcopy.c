#include <stdio.h>
#include <stdlib.h>

void strcopy(char s[], char t[], int i) { //s <- t
    s[i] = t[i];
    if (t[i] == '\0')
        return;
    strcopy(s, t, ++i);
}

int main() {
    char s[] = "Amongus";
    char t[] = "Ohio";
    strcopy(s, t, 0);
    printf("%s", s);
    return 0;
}