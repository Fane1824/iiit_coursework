#include <stdio.h>
#include <stdlib.h>

long long int prob7(long long int n, long long int b, long long int* arr);
// {
//     long long int sum = 0;
//     for (long long int i = 0; i < b; i++) {
//         sum += arr[i];
//     }
//     long long int max = sum;
//     long long int c = 0;
//     for (int i = b-1; i >= 0; i--) {
//         sum -= arr[i];
//         sum += arr[n-c-1];
//         c++;
//         if (sum > max) {
//             max = sum;
//         }
//     }
//     return max;
// }


int main() {

    long long int n, b;
    scanf("%lld %lld", &n, &b);
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld\n", prob7(n, b, arr));
    return 0;
}