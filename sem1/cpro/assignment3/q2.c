#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int fact(int y) {
    if (y == 0 || y == 1) {
        return 1;
    }
    return (y * fact(y-1)); 
}
void swap(char *x, char *y) {
    char temp;
    temp = *x; 
    *x = *y;
    *y = temp;
}

void permute(long long s[], char a[], int l, int r, int c) {
    static int count = 0;
    if (l ==r ) {
        long long varcode = 0;
        for (int i = c-1; i >= 0; i--) {
            varcode += ((long long)a[c-i-1] - 96) * (long long)pow(10, (2*i));
        }
        s[count] = varcode;
        int flag = 0;
        for (int x = 0; x < count; x++) {
            if (s[x] == varcode) {
                flag = 1;
            }
        }
        if (flag == 0) {
            
            count++;
        }
        
    }
     else {
        for (int i = l; i <= r; i++) {
            swap((a+i), (a+l));
            permute(s, a, l+1, r, c);
            swap((a+i), (a+l));
        }
    }
}

int main() {

    char used[9]; 
    scanf("%s", &used);
    int n = strlen(used);
    
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (used[j] > used[j + 1]) {
                char temp = used[j];
                used[j] = used[j + 1];
                used[j + 1] = temp;
                swapped = 1; 
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    int f=fact(n);
    if (n == 1) {
        printf("1\n");
        printf("%c", used[0]);
        return 0;
    } 
    if (n == 2) {
        if (used[0] == used[1]) {
            printf("1\n");
            printf("%c%c", used[0], used[0]);
            return 0;
        }
        else {
            printf("2\n");
            printf("%c%c\n", used[0], used[1]);
            printf("%c%c\n", used[1], used[0]);
            return 0;
        }
    } else {
        int c = 0;
        while (c < n) {
            int count = 0;
            for (int j = c; j < n; j++) {
                if (used[c] == used[j]) {
                    count += 1;
                } 
            }
            f/=fact(count);
            c += count;
        }
    }
    
    printf("%d\n", f);
    long long *s = (long long *)malloc(f * sizeof(long long));
    permute(s, used, 0, n-1, n);
    for (int i = 0; i < f - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < f - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                long long temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                swapped = 1; 
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    long long a;
    for (int i = 0; i < f; i++) {
        long long te = s[i];
        for (int j = n-1; j >= 0; j--) {
            a = pow(10, (2*j));
            printf("%c", (char)((te/a) + 96));
            te -= ((te/a) * a);
        }  
        printf("\n");
    }
    free(s);
    return 0;
}

/*for (int i = 0; i < c; i++) {
                printf("%c", a[i]);
            }
            printf("\n");*/

//char used[n];
    /*for (int i = 0; i < n; i++) {
        used[i] = inp[i];
    }*/