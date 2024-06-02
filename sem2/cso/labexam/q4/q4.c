#include <stdio.h>
#include <stdlib.h>

long long int lenfinder(long long int x); 
// {
//     long long int c1 = 0;
//     while (x != 0) {
//         x /= 10;
//         c1++;
//     }
//     return c1;
// }

long long int prob4(long long int x, long long int* arr, long long int n); 
// {
//     long long int a = x;
//     long long int i = 0;
//     while (a != 0) {
//         arr[i] = a % 10;
//         a /= 10;
//         i++;
//     }
//     for (int i = 0; i < n/2; i++) {
//         if (arr[i] != arr[n-1-i]) {
//             return 0;
//         }
//     }
//     return 1;
// }

int main() {

    
    long long int x;
    scanf("%lld", &x);
    long long int n =lenfinder(x);
    long long int arr[n];
    if (prob4(x, arr, n)) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i])
    }
    return 0;
}