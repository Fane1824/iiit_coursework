#include <stdio.h>
#include <stdlib.h>

long long int scores(char input[], long long int n, long long int* stack);

int main() {
    long long int n;
    scanf("%lld", &n);
    char array[n];

    char buffer1;   
    scanf("%c", &buffer1);

    for (int i =0; i<n;i++){
        scanf("%c", &array[i]);
        char buffer;
        scanf("%c", &buffer);
    }

    long long int stack[n];

    long long int ans = scores(array, n, stack);

    
    printf("%lld", ans);

    return 0;
}