#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli coins[22];
lli dp[22][10000];
lli make;

lli coin_change(lli pos, lli amount)
{
    if(pos >= 21)
    {
        if(amount == 0) return 1;
        else return 0;
    }

    if(dp[pos][amount] != -1) return dp[pos][amount];

    lli r1 = 0, r2 = 0;

    if(amount-coins[pos] >= 0) r1 = coin_change(pos, amount-coins[pos]);

    r2 = coin_change(pos+1, amount);

    return dp[pos][amount] = r1+r2;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    for(lli i = 0; i < 22; i++)
        coins[i] = (i+1)*(i+1)*(i+1);

    while(scanf("%ld", &make) == 1)
    {
        printf("%ld\n", coin_change(0, make));
    }

    return 0;
}
