#include <stdio.h>
#include <stdlib.h>

int binsearch(int l, int r, int x, int a[]) {
    int m = (l + r) / 2;
    if (l > r)
        return -1;
    if (a[m] < x)
        return binsearch(m + 1, r, x, a);
    else if (a[m] > x)
        return binsearch(l, m - 1, x, a);
    return m;
}

int main() {
    int l = 5; //length of array.
    int a[] = {1,2,3,4,5};
    printf("%d", binsearch(0, l - 1, 3, a));
    return 0;
}