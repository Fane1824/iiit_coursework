#include <stdio.h>

long long int binary_search(long long int* L, long long int key, long long int* iterations);
// {
//     long long int left = 0;
//     long long int right = 31; 

//     while (left <= right) {
//         long long int mid = (left + right) / 2;
//         if (L[mid] == key) {
//             while (mid > 0 && L[mid - 1] == key) {
//                 mid--;
//             }
//             (*iterations)++;
//             return mid;
//         } else if (L[mid] < key) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//         (*iterations)++;
//     }
//     return -1; 
// }

int main() {
    long long int L[32];
    long long int key;
    long long int iterations = 0;
    for (int i = 0; i < 32; i++) {
        scanf("%lld", &L[i]);
    }
    scanf("%lld", &key);

    printf("%lld", binary_search(L, key, &iterations));
    printf(" %lld", iterations);

    return 0;
}
