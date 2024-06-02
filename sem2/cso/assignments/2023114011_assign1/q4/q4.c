#include <stdio.h>

long long int sum(long long int arr[], long long int n);
    // int largest = arr[0];
    // int smallest = arr[0];
    // for (int i = 1; i < n; i++) {
    //     if (arr[i] < smallest) {
    //         smallest = arr[i];
    //     }
    //     if (arr[i] > largest) {
    //         largest = arr[i];
    //     }
    // }
    // return smallest + largest;


int main() {
    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    long long int result = sum(arr, n);
    printf("%lld", result);

    return 0;
}