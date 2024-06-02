#include <stdio.h>

long long int combs(long long int n, long long int r); 
// {
//     if (r == 0 || r == n) {
//         return 1;
//     }
//     long long int result = (combs(n - 1, r - 1) * n) / r;

//     return result;
// }

int main() {
    long long int n, r;
    scanf("%lld %lld", &n, &r);
    printf("%lld\n", combs(n, r));
    return 0;
}
