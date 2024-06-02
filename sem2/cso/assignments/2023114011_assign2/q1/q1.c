#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

long long int maxsum(long long int n, long long int l, long long int r, long long int a[]);// {
//     for(long long int i = 2; i <= n; i++){
//         a[i] = a[i-1] + a[i];
//     }

//     long long int deque[n+1];
//     long long int deque_l = 0;
//     long long int deque_r = 0;

//     long long int ans = -1e18;

//     for(long long int i = l; i <= n; i++){
//         while(deque_r != deque_l && a[i-l] < a[deque[deque_r-1]]) // while dq is not empty and other condirion. 
//             deque_r--;
//         deque[deque_r] = i-l;
//         deque_r++;
//         if(deque[deque_l] < i-r)
//             deque_l++;

//         ans = MAX(ans, a[i] - a[deque[deque_l]]);
//     }

//     return ans;
// }

int main(){
    long long int n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    long long int a[n+1];
    a[0] = 0;
    for(long long int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }

    long long int ans = maxsum(n, l, r, a);

    printf("%lld", ans);

    return 0;
}