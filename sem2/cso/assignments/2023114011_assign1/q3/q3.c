#include <stdio.h>
#include <string.h>

long long int palindrome(char *str, long long int length) ;
    
    // for (int i = 0; i < length / 2; i++) {
    //     if (str[i] != str[length - i - 1]) {
    //         return 0; 
    //     }
    // }
    // return 1; 


int main() {
    char str[10000];
    scanf("%s", str);

    long long length = strlen(str);
    long long int x = palindrome(str, length);

    printf("%lld", x);

    return 0;
}