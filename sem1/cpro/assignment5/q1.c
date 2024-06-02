#include <stdio.h>

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 1) {
        printf("1");
        return 0;
    }
    int flag = 0, count = 1, counter = 0;
    int nums[n];
    char subs[n];
    for (int i = 0; i < n; i++) {
        scanf("%c", &subs[i]);
        if ((int)subs[i] == 10) {
            scanf("%c", &subs[i]);
        }
        if (i == 0) {
            if (k == 1) {
                flag = 1;
                nums[counter] = (int)subs[i];
                counter++;
                count = 0;
            }
            continue;
        }
        if ((subs[i] == subs[i-1]) && count != 0) {
            count++;
        } else {
            count = 1;
        }
        if (count == k) {
            flag = 1;
            nums[counter] = (int)subs[i];
            counter++;
            count = 0;
        }
    }
    if (flag == 0) {
        printf("0");
        return 0;
    }
    int num[counter];
    for (int i = 0; i < counter; i++) {
        num[i] = nums[i];
    }
    int max = 0;
    for (int j = 97; j < 123; j++) {   
        int count2 = 0;
        for (int i = 0; i < counter; i++) {
            if (num[i] == j) {
                count2++;
            }
        }
        if (count2 > max) {
            max = count2;
        }
    }
    printf("%d", max);
    

    return 0;
}