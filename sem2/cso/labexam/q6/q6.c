#include <stdio.h>
#include <stdlib.h>

long long int prob6(long long int n, long long int m);

int main() {

    long long int n, m;
    scanf("%lld %lld", &m, &n);
    printf("%lld", prob6(n, m));
    return 0;
}