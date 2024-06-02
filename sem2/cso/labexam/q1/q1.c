#include <stdio.h>
#include <stdlib.h>

long long int prob1 (long long int m, long long int n, long long int s); 
// {
//     if (s == 1) {
//         return m + n;
//     }
//     if (s == 2) {
//         return m - n;
//     }
//     if(s == 3) {
//         return m/n;
//     }
//     if (s == 4) {
//         long long int a = 1;
//         for (long long int i = 0; i < n; i++) {
//             a *= m;
//         }
//         return a;
//     }
//     return m % n;
// }


int main() {
    long long int m, n, s;
    scanf("%lld %lld %lld", &m, &n, &s);
    printf("%lld", prob1(m, n, s));

    return 0;
}