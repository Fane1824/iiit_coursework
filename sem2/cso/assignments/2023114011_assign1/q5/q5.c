#include <stdio.h>
#include <stdlib.h>

void products(long long int* arr, long long int n, long long int* sums);
    // for (int i = 0; i < n; i++) {
    //     sums[i] = 1;
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i != j) {
    //             sums[i] = sums[i] * arr[j];
    //         }
    //     }
    // }


int main() {
    long long int n;
    scanf("%lld", &n);
    long long int nums[n];
    long long int sums[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    products(nums, n, sums);
    for (int i = 0; i < n; i++) {
        printf("%lld ", sums[i]);
    }

    return 0;
}