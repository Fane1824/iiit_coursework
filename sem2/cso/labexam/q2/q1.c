#include <stdio.h>
#include <stdlib.h>

long long int prob2(long long int x, long long int* arr);
// {
//     int i = 0;
//     int cnt = 0;
//     while (x != 0) {
//         arr[i] = x % 2;
//         x /= 2;
//         i++;
//         if (arr[i] == 1) {
//             cnt++;
//         }
//     }
//     if (cnt % 2) {
//         return 1;
//     } 
//     return 0;
// }

int main() {
    long long int x;
    long long int arr[64] = {0};
    scanf("%lld", &x);
    if (prob2(x, arr)) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }

    return 0;
}