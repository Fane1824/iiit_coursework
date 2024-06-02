#include<stdio.h>
#include<string.h>
#include<math.h>

int jump(int n, int m, long long int squares[n][m], int x, int y) {

    if (x == 0) {
        return 1;
    } else if (squares[x][y] == -1) {
        return 0;
    } else if (squares[x][y] != 0) {
        return squares[x][y];
    } else {
        if (x-2 >= 0 && y+1 < m) {
            squares[x][y] += jump(n, m, squares, x-2, y+1);
            squares[x][y] %= (int)(pow(10, 9) + 7);
        }   
        if (x-1 >= 0 && y+2 < m) {
            squares[x][y] += jump(n, m, squares, x-1, y+2);
            squares[x][y] %= (int)(pow(10, 9) + 7);
        }   
        if (x-1 >= 0 && y-2 >= 0) {
            squares[x][y] += jump(n, m, squares, x-1, y-2);
            squares[x][y] %= (int)(pow(10, 9) + 7);
        }
        if (x-2 >= 0 && y-1 >= 0) {
            squares[x][y] += jump(n, m, squares, x-2, y-1);
            squares[x][y] %= (int)(pow(10, 9) + 7);
        }
    }

    return (squares[x][y] % (int)(pow(10, 9) + 7));
}

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int x_set[k], y_set[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &x_set[i]);
        scanf("%d", &y_set[i]);
    }
    long long int squares[n][m];   
    memset(squares, 0, sizeof squares);

    for (int a = 0; a < k; a++) {
        squares[x_set[a] - 1][y_set[a] - 1] = -1; 
    }

    for (int i = 0; i < m; i++) {
        jump(n, m, squares, n-1, i);
        printf("%lld ", squares[n-1][i]);
    }

    return 0;
}