#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long long

int main()
{
    int t, n, m;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &m);
        ll ans = n/2;
        ans *= m;

        printf("Case %d: %lld\n", tc, ans);
    }
    return 0;
}
