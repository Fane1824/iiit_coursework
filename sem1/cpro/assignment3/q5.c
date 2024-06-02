#include <stdio.h>
#include <string.h>

int irrfunc(int store[], int arr[], int c, int n) {
    if (arr[c] > n-c-1) {
        return store[c] = arr[c];
    } else if (store[c] != -1) {
        return store[c];
    }
    return store[c] = arr[c] + irrfunc(store, arr, c+arr[c], n);
}

int main() {

    int t;
    scanf("%d", &t);
    int irr[t];
    for (int i = 0; i < t; i++) {
        int n, f, max = 0;
        scanf("%d", &n);
        int arr[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        int store[n];
        memset(store, -1, sizeof store);
        for (int k = n-1; k >= 0; k--) {
            f = irrfunc(store, arr, k, n);
            if (f > max) {
                max = f;
            }
        }
        irr[i] = max;
    }
    for (int e = 0; e < t; e++) {
        printf("%d\n", irr[e]);
    }

    return 0;
}