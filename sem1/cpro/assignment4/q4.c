#include <stdio.h>
#include <string.h>

void rotate_c(char s[], int n) {
    char temp = s[0];
    s[0] = s[n-1];
    for (int j = n-1; j >=2 ; j--) {
        s[j] = s[j-1];
    }
    s[1] = temp;
}

int max_check(char s_og[], char s_new[], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (s_og[i] < s_new[i]) {
            flag = 1;
            break;
        } else if (s_og[i] == s_new[i]) {
            continue;
        } else {
            break;
        }
    }
    return flag;
}

int min_check(char s_og[], char s_new[], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (s_og[i] > s_new[i]) {
            flag = 1;
            break;
        } else if (s_og[i] == s_new[i]) {
            continue;
        } else {
            break;
        }
    }
    return flag;
}

int main() {

    char s_in[1000];
    scanf("%s", s_in);
    int n = strlen(s_in);
    if (n == 1) {
        printf("%c\n%c", s_in[0], s_in[0]);
        return 0;
    }
    char s[n], max[n], min[n], store[n];
    for (int i = 0; i < n; i++) {
        s[i] = s_in[i];
        max[n] = s[i];
        min[i] = s[i];
    }
    for (int j = 0; j < n; j++) {
        rotate_c(s, n);
        if (max_check(max, s, n) == 1) {
            for (int f = 0; f < n; f++) {
                max[f] = s[f];
            }
        }
        if (min_check(min, s, n) == 1) {
            for (int f = 0; f < n; f++) {
                min[f] = s[f];
            }
        }
    }
    for (int z = 0; z < n; z++) {
        printf("%c", min[z]);
    }
    printf("\n");
    for (int z = 0; z < n; z++) {
        printf("%c", max[z]);
    }

    return 0;
}