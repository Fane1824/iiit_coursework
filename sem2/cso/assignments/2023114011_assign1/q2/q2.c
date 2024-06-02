#include <stdio.h>

void rotate(long long int arr[], long long int n, long long int rotated[]) ;
//     for (int i = 0; i < n-1; i++) {
//         rotated[i] = arr[i+1];
//     }
//     rotated[n-1] = arr[0];


int main() {

    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    long long int rotated[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    rotate(arr, n, rotated); 
    for (int i = 0; i < n; i++) {
        printf("%lld ", rotated[i]);
    }
    return 0;
}