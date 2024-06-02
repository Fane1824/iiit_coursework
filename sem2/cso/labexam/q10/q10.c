#include <stdio.h>
#include <stdlib.h>

long long int prob10(long long int n, long long int* arr);
// {
//     long long int ceven = 0, codd = 0;
//     for (long long int i = 0; i < n; i++) {
//         if (arr[i] % 2) {
//             codd++;
//         } else {
//             ceven++;
//         }
//     }
//     if (codd > 0 && ceven > 0) {
//         for (long long int i = 0; i < n-1; i++) {
//             for (long long j = 0; j < n-1; j++) {
//                 if (arr[j] > arr[j+1]) {
//                     long long int temp = arr[j];
//                     arr[j] = arr[j+1];
//                     arr[j+1] = temp;
//                 }
//             }
//         }
//     } 
// }

int main() {

    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    // printf("%lld", prob10(n, arr));
    prob10(n, arr);
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }    
    return 0;
}