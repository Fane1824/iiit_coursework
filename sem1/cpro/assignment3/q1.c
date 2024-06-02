#include <stdio.h>
#include <string.h>

int main() {

    char s[100];
    scanf("%s", &s);
    int n = strlen(s);
    int str[n], flag1 = 0, flag2 = 0;
    if (n > 52) {
        printf("No");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        str[i] = (int)s[i];
    }
    for (int j = 0; j < n; j++) {
        for (int k = j+1; k < n; k++) {
            if (str[j] == str[k]) {
                printf("No");
                return 0;
            }
        }
        if (flag1 == 0 && str[j] <= 90) {
            flag1 = 1;
        }
        if (flag2 == 0 && str[j] >= 97) {
            flag2 = 1;
        }
    }
    if (flag1 == 1 && flag2 == 1) {
        printf("Yes");
    } else {
        printf("No");
    }
    
    return 0;

}

