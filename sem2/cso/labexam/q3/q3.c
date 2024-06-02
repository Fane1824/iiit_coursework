#include <stdio.h>
#include <stdlib.h>

void prob3(long long int x, long long int* arr) 
{
    for (int i = 0; i < x; i++) {
        int j = i + 1;
        if (j % 3 == 0 && j % 5 == 0) {
            arr[i] = -3;
            continue;
        }
        if (j % 3 == 0) {
            arr[i] = -1;
            continue;
        }
        if (j % 5 == 0) {
            arr[i] = -2;
            continue;
        } 
        arr[i] = j;
    }
}

int main() {

    long long int x;
    scanf("%lld", &x);
    long long int arr[x];
    prob3(x, arr);
    for (int i = 0; i < x; i++) {
        printf("%lld ", arr[i]);
    }
    return 0;
}