#include <bits/stdc++.h>
using namespace std;

#define lli long long int
int make, N;
int dp[101][1001];
int coin[101];
int ci[101];

lli coin_change(int i, int amount)
{
    lli ans = 0;
    int mod = 1e8+7;

    if(amount == make) return 1;
    if(i == N) return 0;

    if(dp[i][amount] != -1) return dp[i][amount];

    for(int j = 0; j <= ci[i] && j * coin[i] + amount  <= make; j++)
    {
        ans = ans + coin_change(i+1, amount + j * coin[i]);
        ans %= mod;
    }

    return dp[i][amount];
}
long long int coin_change1(int i, int sum)
{
    long long ans = 0;
    int mod = 1e8 + 7;

    if(sum == make) return 1;
    if(i == N) return 0;

    if(dp[i][sum] != -1) dp[i][sum];

    for(int j = 0; j <= ci[i] && j*coin[i]+sum <= make; j++){
        ans = ans + coin_change(i+1, sum+ j * coin[i]);
        ans %= mod;
    }

    return dp[i][sum] = ans;
}
int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> N >> make;

        for(int j = 0; j < N; j++)
            cin >> coin[j];

        for(int j = 0; j < N; j++)
            cin >> ci[j];

        memset(dp, -1, sizeof(dp));

        cout << "Case " << i <<  ": " << coin_change(0, 0) << endl;
    }

    return 0;
}
