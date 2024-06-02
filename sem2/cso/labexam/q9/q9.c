#include <stdio.h>
#include <stdlib.h>

long long int prob9(long long int n, long long int* arr); 
// {
//     int max = arr[0];
//     for (long long int i = 1; i < n; i++) {
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//     }
//     for (long long int i = 1; i < max; i++) {
//         int found = 0;
//         for (long long int j = 0; j < n; j++) {
//             if (arr[j] == i) {
//                 found = 1; 
//                 break;
//             }
//         }
//         if (!found) {
//             return i;
//         }
//     }
//     return max+1;
// }

int main() {

    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld", prob9(n, arr));

    return 0;
}


