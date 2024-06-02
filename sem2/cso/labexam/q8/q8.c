#include <stdio.h>
#include <stdlib.h>

void prob8(long long int n, long long int* arr);
// {
//     for (int i = 0; i < n-1; i++) {
//         for (int j = 0; j < n-1; j++) {
//             if (arr[j] > arr[j+1]) {
//                 long long int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     for (int i = 0; i < n; i+=2) {
//         if (i+1 < n) {
//             long long int temp = arr[i];
//             arr[i] = arr[i+1];
//             arr[i+1] = temp;        
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
    prob8(n, arr);
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    return 0;
}