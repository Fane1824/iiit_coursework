#include <stdio.h>

int main() {

    int n, count, x, sum = 0;
    scanf("%d \n", &n);
    for (count = 0; count < n; count++) {
        scanf("%d", &x);
        sum = sum ^ x;
    }
    printf("%d", sum);
    
    return 0;
}