#include <stdio.h>
#include <stdlib.h>

//without static variable
int strl(char s[], int i) { //expected initial value of i is 1.
    if (s[i - 1] == '\0')
        return i;
    return strl(s, ++i);
}

//with static variable
int strlength(char s[]) {
    static int i = 1;
    if (s[i - 1] == '\0')
        return i;
    ++i;
    return strlength(s);
}

int main() {
    char s[] = "Amongus";
    printf("%d\n", strl(s, 1));
    printf("%d", strlength(s));
    return 0;
}