#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    long long int min;
    long long int change;
} Pair;

int compareneg(const void* a, const void* b) {
    Pair ax = *(Pair*)a;
    Pair bx = *(Pair*)b;
    return bx.min - ax.min;
}

int comparepos(const void* a, const void* b) {
    Pair ax = *(Pair*)a;
    Pair bx = *(Pair*)b;
    return ax.min - bx.min;
}

int main() {

    long long int n, k;
    scanf("%lld %lld", &n, &k);
    Pair arr[n];
    Pair pos[n], neg[n];
    int posi = 0, negi = 0;
    long long int numn = 0;
    for (long long int i =0; i < n; i++) {
        scanf("%lld", &arr[i].min);
    }
    for (long long int i =0; i < n; i++) {
        scanf("%lld", &arr[i].change);
        if (arr[i].change < 0) {
            neg[negi++] = arr[i];
        } else {
            pos[posi++] = arr[i];
        }
    }
    qsort(pos, posi, sizeof(Pair), comparepos);
    qsort(neg, negi, sizeof(Pair), compareneg);
    for (long long int i = 0; i < posi; i++) {
        if (pos[i].min > k) {
            printf("NO");
            return 0;
        }
        k += pos[i].change;
    }
    for (long long int i = 0; i < negi; i++) {
        if (neg[i].min > k) {
            printf("NO");
            return 0;
        }
        k += neg[i].change;
    }
    if (k < 0) {
        printf("NO");
    } else {
        printf("YES");
    }

    return 0;
}