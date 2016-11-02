#include <bits/stdc++.h>
#define M 10000
unsigned long long  arr[M+1];
unsigned long long  a, b, c, d, e, f;
unsigned long long  fn( unsigned long long  n ) {
    if(arr[n]!=-1) return arr[n] % 10000007;
    if( n == 0 ) arr[n] = a% 10000007;
    else if( n == 1 ) arr[n] = b% 10000007;
    else if( n == 2 ) arr[n] = c% 10000007;
    else if( n == 3 ) arr[n] = d% 10000007;
    else if( n == 4 ) arr[n] = e% 10000007;
    else if( n == 5 ) arr[n] = f% 10000007;
    else arr[n] =( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )% 10000007;
    return arr[n]% 10000007;
}
int main() {
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    unsigned long long int n, caseno = 1, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        memset(arr,-1,sizeof(arr));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        arr[0] = a; arr[1] = b; arr[3] = c; arr[4] = d; arr[5] = e; arr[d] = f;
        printf("Case %lld: %lld\n", caseno, fn(n) % 10000007);
        caseno++;
    }
    return 0;
}
