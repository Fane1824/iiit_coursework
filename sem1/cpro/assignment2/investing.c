#include <stdio.h>

int eight(int amount, int counter) {

    switch(amount) {

        case 0:
            printf("0");
            break;

        case 1:
        case 2:
        case 4:
        case 8:
            printf("%d", counter);
            break;
        
        case 3:
        case 5:
        case 6:
            printf("%d", counter+1);
            break;
        case 7:
            printf("%d", counter+2);
            break;
    }

    return 0;
}

int main() {

    int amount, digits = 0, count = 1;
    scanf("%d", &amount);
    float x = amount;
    for (; x >= 1; x/= 2) {
        if (x == 1) {
            printf("1");
            return 0;
        }
    }
    while (amount > 8) {
        if (amount % 2 != 0) {
            amount -= 1;
            count += 1;
        } else {
            amount /= 2;
        }
    }
    if (x<=8) {
        eight(amount, count);
    }
    
    return 0; 
}

/*int main() {

    int amount, powers = 1, digits = 0, count = 0, flag = 1;
    scanf("%d", &amount);
    float x = amount;
    for (; x >= 1; x/= 2) {
        if (x == 1) {
            printf("1");
            return 0;
        }
    }
    for (x = amount+1; x>=1; x/=2) {
        digits += 1;
        if (x == 1) {
            printf("%d", digits-1);
            return 0;
        }
    }
    for (int y = amount; y >= 1; y /= 2) {
        count += 1;
    }
    count -= 2;
    for (; count >= 0 ; count--) {
        powers *= 2;
    }
    int counter = 1;
    while (flag == 1) {
        amount -= powers;
        powers /= 2;
        if (amount <= powers-1) {
            counter++;
            printf("%d", counter);
            flag = 0;
        } 
        counter += 1;
    }
    
    return 0; 
}*/