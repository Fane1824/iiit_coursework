#include <stdio.h>
#include <string.h>

int main() {

    char str[300001];
    scanf("%s", str);
    int n = strlen(str);
    int m, flag = 0, leftadd[300000], rightadd[300000], rc = 0, lc = 0;
    scanf("%d", &m);
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            printf("%c", str[i]);
        }
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            flag = 1 - flag;
        } else {
            int y;
            char d;
            scanf("%d %c", &y, &d);
            if (y == 1) {
                if (flag == 1) {
                    rightadd[rc] = (int)d;
                    rc++;
                } else {
                    leftadd[lc] = (int)d;
                    lc++;
                }
            } else {
                if (flag == 1) {
                    leftadd[lc] = (int)d;
                    lc++;
                } else {
                    rightadd[rc] = (int)d;
                    rc++;                    
                }                
            }
        }
    }
    if (flag == 0) {
        for (int i = lc-1; i >= 0; i--) {
            printf("%c", (char)leftadd[i]);
        }
        for (int i = 0; i < n; i++) {
            printf("%c", str[i]);
        }
        for (int i = 0; i < rc; i++) {
            printf("%c", (char)rightadd[i]);
        }
    } else {
        for (int i = rc-1; i >= 0; i--) {
            printf("%c", (char)rightadd[i]);
        }
        for (int i = n-1; i >= 0; i--) {
            printf("%c", str[i]);
        }
        for (int i = 0; i < lc; i++) {
            printf("%c", (char)leftadd[i]);
        }        
    }

    return 0;
}