#include <stdio.h>

int main() {

    int x, num, count, expo, multiplier;
    scanf("%d", &x);
    num = x;
    count = 0;
    while (num > 0) {
        num/=2;
        count += 1;
    }
    if (x == 0) {
        printf("0");
    }
    for (; count > 0; count--){
        expo = count;
        multiplier = 1;
        for (; expo-1 > 0; expo--) {
            multiplier*=2;
        }
        if (x >= multiplier) {
            printf("1");
            x-= multiplier;
        } else {
            printf("0");
        }
    }

    return 0;
}