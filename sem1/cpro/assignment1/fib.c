#include <stdio.h>

int main() {

    int x, y, n, c, count;
    scanf("%d %d %d", &n, &x, &y);
    if (n==1) {
        printf("%d", x);
    } else {
        printf("%d %d ", x, y);
        if (n>2) {
            for (count = 2; count < n; count++) {
                c = x + y;
                printf("%d ", c);
                x = y;
                y = c;
            }
        }
    } 

    return 0;
}