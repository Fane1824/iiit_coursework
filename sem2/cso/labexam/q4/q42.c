#include <stdio.h>
#include <stdlib.h>

long long int prob4 (long long int n);
// {
//     long long int a = n;
//     long long int b = 0;
//     while (a != 0) {
//         int temp = a % 10;
//         a /= 10;
//         b *= 10;
//         b += temp;
//     }
//     if (n == b) {
//         return 1;
//     }
//     return 0;
// }

int main() {
    long long int n;
    scanf("%lld", &n);
    if(prob4(n)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    
    return 0;
}