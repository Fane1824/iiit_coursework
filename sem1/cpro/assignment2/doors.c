#include <stdio.h>

int main() {

    int long long x, a = 1;
    printf("Hello World");
    scanf("%lld", &x);
    while ((a * a) <= x) {
        printf("%d ", a * a);
        a+=1;
    }
    
    return 0;
}