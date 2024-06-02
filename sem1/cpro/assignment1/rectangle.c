#include <stdio.h>

int main() {

    int width, height, tb, sides;
    scanf("%d %d", &width, &height);
    printf("o");
    for (tb=0; tb < width-2;tb++) {
        printf("-");
    }
    if (width != 1) {
        printf("o");
    }
    printf("\n");
    for (sides = 0; sides < height-2; sides++) {
        printf("|");
        for (tb=0; tb < width-2; tb++) {
            printf(" ");
        }
        if (width > 1) {
            printf("|");
        } 
        printf("\n");
    } 
    if (height != 1) {
        printf("o");
        for (tb=0; tb < width-2;tb++) {
            printf("-");
        }
        if (width != 1) {
            printf("o");
        }
    }

    return 0;

}