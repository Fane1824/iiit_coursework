#include <stdio.h>
#include <stdlib.h>

long long int prob12(long long int n);
// {
//     if (n == 0) {
//         return 0;
//     }
//     long long int a = n;
//     long long int sum = 0;
//     while (a != 0) {
//         long long int temp = a % 10;
//         a /= 10;
//         int temp2 = 1;
//         while (temp != 0 && (temp-1) != 0) {
//             temp2 *= (temp);
//             temp--;
//         }
//         sum += temp2;
//     }
//     if (sum == n) {
//         return 1;
//     }
//     return 0;
// }

int main() {

    long long int n;
    scanf("%lld", &n);
    if (prob12(n)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}