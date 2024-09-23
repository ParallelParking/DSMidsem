#include <stdio.h>
#include <stdlib.h>

int palindrome(char s[], int l, int r) {
    if (l > r)
        return 1;
    if (s[l] != s[r])
        return 0;
    return palindrome(s, ++l, --r);
}

int main() {
    printf("%d", palindrome("malayalam", 0, 8));
    return 0;
}