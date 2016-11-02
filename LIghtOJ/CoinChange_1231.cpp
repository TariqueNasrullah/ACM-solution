#include <bits/stdc++.h>
using namespace std;

int k, n;
int dp[51][1001];
int a[51];
int c[51];

long long  coin_change(int i, int sum)
{
    long long ans;
    int mod;
    ans = 0;

    mod = 1e8 + 7;

    if(sum == k) {
        return 1;
    }

    if(i == n) {
        return 0;
    }

    if(dp[i][sum] != -1) {
        return dp[i][sum];
    }

    for (int j = 0; j <= c[i] and (j * a[i]) + sum <= k; j++) {
        ans += coin_change(i+1, sum + j * a[i]);
        ans = ans % mod;
    }


    return dp[i][sum] = ans;

}
int main()
{
    int t;
    scanf("%d", &t);

    for(int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        scanf("%d", &k);


        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", c + i);
        }

        memset(dp, -1, sizeof dp);

        printf("Case %d: %lld\n", cs,coin_change(0, 0));

}

    return 0;
}
