#include <stdio.h>
#include <string.h>

int main() {

    int n, k, sum = 0;
    scanf("%d %d", &n, &k);
    char str[n];
    int arr[n];
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        arr[i] = (int)str[i];
        sum += (arr[i]-97);
    }

    if (sum >= k) {
        for (int j = 0; j < n; j++) {
            while (arr[j] > 97 && k > 0) {
                arr[j]--;
                k--;
            }
            if (k == 0) {
                break;
            }
        }
    } else {
        int arr1[n];
        k -= sum;
        for (int f = 0; f < n; f++) {
            arr1[f] = 97;
        }
        for (int j = n-1; j >=0; j--) {
            if (arr[j] < 110) {
                arr1[j] = (arr[j]-97) + arr[j];
                while (k > 0 && arr1[j] < 122) {
                    k--;
                    arr1[j]++;
                }
            }
            if (k == 0) {
                for (int m = 0; m < n; m++) {
                    arr[m] = arr1[m];
                }
                break;
            }
        }
    }
    
    if (k != 0) {
        printf("-1");
        return 0;
    }
    
    for (int a = 0; a < n; a++) {
        printf("%c", (char)arr[a]);
    }

    return 0;
}