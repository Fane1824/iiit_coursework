#include <stdio.h>
#include <stdlib.h>

void prob11(long long int n, long long int* arr, long long int* ans);
// {
//     long long int total = 0;
//     for (int i = 0; i <n; i++) {
//         if (arr[i]) {
//             total += n-i-1;
//         } else {
//             total += i;
//         }
//     }
//     int l = 0;
//     int r = n-1;
//     int count = 0;
//     while (l <= r) {
//         if (!arr[l]) {
//             total -= l;
//             total += n-l-1;
//             ans[count] = total;
//             count++;
//         }
//         if (arr[r]) {
//             total -= n-r-1;
//             total += r;
//             ans[count] = total;
//             count++;
//         }
//         l++;
//         r--;
//     }
//     for (int i = count; i < n; i++) {
//         ans[i] = total;
//     }
// }

int main() {

    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    long long int ans[n];
    for (long long int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    prob11(n, arr, ans);
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}