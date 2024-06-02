#include <stdio.h>
#include <stdlib.h>

void prob5(long long int n, long long int* arr); 
// {
//     int c0 = 0;
//     for (int i = 0; i < n; i++) {
//         if (!arr[i]) {
//             c0++;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (i < c0) {
//             arr[i] = 0;
//         } else {
//             arr[i] = 1;
//         }
//     }
// }

int main() {

    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    prob5(n, arr);
    for (int i = 0; i < n; i++) {
        printf("%lld", arr[i]);
    }
    return 0;
}