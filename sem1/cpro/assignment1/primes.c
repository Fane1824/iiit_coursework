#include <stdio.h>

int main() {

    int x, count, test, flag;
    flag = 0;
    scanf("%d", &x);
    for (count = 2; count <= x; count++) {
        flag = 0;
        for (test = 2; test < count; test++) {
            if (count % test == 0) {
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("%d ", count);
        }
    }

    return 0;
}