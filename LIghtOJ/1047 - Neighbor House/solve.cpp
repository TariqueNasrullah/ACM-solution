#include <bits/stdc++.h>
using namespace std;
int N;
int dp[21][3];
int rgb[100][4];
int returnCost(int n, int c)
{
    if(n < 0 ) return 0;

    if(dp[n][c] != -1) return dp[n][c];

    int mini = 10000000;
    for(int i = 0; i < 3; i++)
    {
        if(i != c ) mini = min(mini, returnCost(n-1, i));
    }

    return dp[n][c] = mini+rgb[n][c];
}
int main()
{
    int test;
    cin >> test;

    for(int j = 1; j <= test; j++)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
        memset(dp, -1, sizeof(dp));
        int r = returnCost(N-1, 0);
        int g = returnCost(N-1, 1);
        int b = returnCost(N-1, 2);

        int res = min(r, g);
        res = min(res, b);

        printf("Case %d: %d\n", j, res);
    }

    return 0;
}
