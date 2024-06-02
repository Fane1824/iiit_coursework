#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if ((int)s[i] == 34) {
            counter++;
            if (counter == 2) {
                counter = 0;
            } 
        }
        if (counter == 0 && (int)s[i] == 44) {
            s[i] = (char)42;
        }
    }
    for (int j = 0; j < n; j++) {
        printf("%c", s[j]);
    }

    return 0;
}