#include <stdio.h>

int main() {

    int n, d; 
    scanf("%d", &n);
    int arr[n][n];
    for (int c1 = 0; c1 < n; c1++) {
        for (int c2 = 0; c2 < n; c2++) {
            scanf("%d", &arr[c1][c2]);
        }
    }
    scanf("%d", &d);
    if (d == 1) {
        int no_change = arr[0][n-1];
        for (int c3 = n-1; c3 >= 1; c3--) {
            arr[0][c3] = arr[0][c3-1];
        }
        for (int c4 = 0; c4 < n-1; c4++) {
            arr[c4][0] = arr[c4+1][0];
        }
        for (int c5 = 0; c5 < n-1; c5++) {
            arr[n-1][c5] = arr[n-1][c5+1];
        }
        for (int c6 = n-1; c6 > 1; c6--) {
            arr[c6][n-1] = arr[c6-1][n-1];
        }
        arr[1][n-1] = no_change;
    } else if (d == 0) { 
        int cor1 = arr[0][0];   
        int cor2 = arr[n-1][0];
        int cor3 = arr[n-1][n-1];
        for (int c7 = 0; c7 < n-1; c7++) {
            arr[0][c7] = arr[0][c7 + 1];
        }
        for (int c8 = n-1; c8 > 1; c8--) {
            arr[c8][0] = arr[c8-1][0]; 
        }
        arr[1][0] = cor1;
        for (int c9 = n-1; c9 > 1; c9--) {
            arr[n-1][c9] = arr[n-1][c9-1];
        }
        arr[n-1][1] = cor2;
        for (int c10 = 0; c10<n-2; c10++) {
            arr[c10][n-1] = arr[c10+1][n-1];
        }
        arr[n-2][n-1] = cor3;

    }

    for (int c1 = 0; c1 < n; c1++) {
        for (int c2 = 0; c2 < n; c2++) {
            printf("%d ", arr[c1][c2]);
        }
        printf("\n");
    }

    return 0;
}