#include <stdio.h>
#include <stdlib.h>

int phonegiving(int arr[], int n) {
    int x = 0;
    int counter = 0;
    for (int i =0; i < n; i++) {
        if (arr[i] == 1) {
            counter++;
        }
    }
    int arr2[counter];
    int c1 = 0;
    for (int i =0; i<n; i++) {
        if (arr[i] == 1) {
            arr2[c1] = i;
            c1++;
        }
    }
    counter--;
    for (int i = n-1; i>= 0; i--) {
        // printf("%d. ", i);
        // for (int j = 0; j < n; j++) {
        //     printf("%d ", arr[j]);
        // }
        // printf("\n");
        if (arr[i] == 1) {
            if (i == 0) {
                if (arr[1] == 2 || arr[2] == 2) {
                    arr[0] = 3;
                } else {
                    arr[0] = 2;
                }

            }
            if ((counter * 2) + 2 < n) {
                if (arr[(counter * 2) + 2] == 2 || arr[(counter * 2) + 1] == 2) {
                    arr[i] = 3;
                }
                int flag = 0;
                if (arr[(counter * 2) + 1] == 1) {
                    flag = 1;
                    arr[(counter * 2) + 1] = 3;
                }
                if (arr[(counter * 2) + 2] == 1) {
                    flag = 1;
                    arr[(counter * 2) + 2] = 3;
                }
                if (flag == 1) {
                    arr[i] = 2;
                }
            } else if ((counter * 2) + 1 < n) {
                if (arr[(counter * 2) + 1] == 2) {
                    arr[i] = 3;
                } else if (arr[(counter * 2) + 1] == 1) {
                    arr[i] = 2;
                    arr[(counter * 2) + 1] = 3;
                }
            }
            counter--;
        } 
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            printf("%d ", i);
            x++;
        }
    }
    return x;
}

int main() {

    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("%d", 0);
        return 0;
    }
    int arr[n];
    for (int i =0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n < 4) {
        if (arr[0] == 0) {
            printf("%d", 0);
        } else {
            printf("%d", 1);
        }
        return 0;
    }
    printf("%d", phonegiving(arr, n));
    return 0;
}