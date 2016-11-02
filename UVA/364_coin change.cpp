#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 5, 10, 25, 50};
int dp[6][8000];
int make;

int coin_change(int pos, int amount)
{
    if(pos >= 5)
    {
        if(amount == 0) return 1;
        else return 0;
    }

    if(dp[pos][amount] != -1)
        return dp[pos][amount];

    int r1  = 0, r2 = 0;

    if(amount-coins[pos] >= 0)
        r1 = coin_change(pos, amount-coins[pos]);
    r2 = coin_change(pos+1, amount);

    return dp[pos][amount] = r1+r2;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    while(cin >> make)
    {
        cout << coin_change(0, make) << "\n";

    }

    return 0;
}
