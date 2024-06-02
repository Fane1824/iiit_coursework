#include <stdio.h>

long long int lonely(long long int arr[], long long int n);

    // int x = arr[0];
    // for (int i = 1; i < n; i++) {
    //     x = x ^ arr[i];
    // }
    // return x;

int main() {

    long long int n;
    scanf("%lld", &n);
    long long int arr[2 * n + 1];
    for (int i = 0; i < 2 * n + 1; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld", lonely(arr, 2 * n + 1));
    return 0;
}