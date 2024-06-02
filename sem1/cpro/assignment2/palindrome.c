#include <stdio.h>

int main() {

    int x, even_potential_count = 0, odd_potential_count = 0; 
    scanf("%d", &x);
    int arr[x];
    int even_potentials[100], odd_potentials[100];
    int palindromes = x;
    for (int count = 0; count <x; count++) {
        scanf("%d", &arr[count]);
    }
    for (int c1 = 0; c1 < x-1; c1++) {
        if (arr[c1] == arr[c1+1]) {
            palindromes += 1;
            even_potentials[even_potential_count] = c1;
            even_potential_count += 1;
        }
        if (arr[c1] == arr[c1+2]) {
            palindromes += 1;
            odd_potentials[odd_potential_count] = c1;
            odd_potential_count += 1;
        }

    }

    for (int c2 = 0; c2 < even_potential_count; c2++) {
        for (int c3 = 0; (c3 < even_potentials[c2]) && (c3 < x-even_potentials[c2]); c3++) {
            if (arr[even_potentials[c2]-1-c3] == arr[even_potentials[c2]+2+c3]) {
                palindromes += 1;
                continue;
            } else {
                break;
            }
        }
    }
    for (int c4 = 0; c4 < odd_potential_count; c4++) {
        for (int c5 = 0; (c5 < odd_potentials[c4]) && (c5 < x-odd_potentials[c4]); c5++) {
            if (arr[odd_potentials[c4]-1-c5] == arr[odd_potentials[c4]+3+c5]) {
                palindromes += 1;
                continue;
            } else {
                break;
            }
        }
    }

    printf("%d", palindromes);

    /*for (int c1 = 0; c1 < x-1; c1++) {
        for (int c2 = c1+1; c2 < x-1; c2++) {
            if (arr[c2] == arr[c1]) {
                palindromes += 1;
                potentials[count] = c1;
                count+=1;
            } else {
                break;
            }
        }
    }
    for (int c3 = 0; c3 < count; c3++) {
        for (int c4 = 1; c4 < potentials[c3]; c4++) {
            printf("Hi");
        }
    }*/

    return 0;
}