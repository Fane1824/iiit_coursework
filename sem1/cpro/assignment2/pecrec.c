#include <stdio.h>

int main() {

    int n, y, unique_squares = -1; 
    int flag = 0;
    scanf("%d", &n);
    int squares[35000];
    for (int count = 0; count < n; count++) {
        int arr[4];
        for (int c = 0; c < 4; c++) {
            int x;
            scanf("%d", &x);
            arr[c] = x;
        }
        for (int c2 = (arr[0] + 1); c2 <= arr[1]; c2++) {
            for (int c3 = (arr[2] + 1); c3 <= arr[3]; c3++) {
                int z = c2 * 100 + c3;
                for (int c5 = 0; c5 <= unique_squares; c5++) {
                    if (squares[c5] == z) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    unique_squares++;
                    squares[unique_squares] = z;
                }
                flag = 0;

            }
        }
    }
    printf("%d", (unique_squares+1));

    return 0; 
}