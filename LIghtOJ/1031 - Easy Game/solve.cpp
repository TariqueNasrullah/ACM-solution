using namespace std;
#include <bits/stdc++.h>

int inf = 1 << 30;

int dp[110][110];
bool isVal[110][110];
int cost[110];

int godDamnit(int i, int j) {
    if (i > j)
        return 0;

    if (i == j)
        return cost[i];

    if (isVal[i][j])
        return dp[i][j];

    isVal[i][j] = true;

    int sum = 0;
    int maxi = -inf;
    for (int k = i; k <= j; ++k) {
        sum += cost[k];
        maxi = max(maxi, sum - godDamnit(k + 1, j));
    }

    sum = 0;
    for (int k = j; k >=  i; --k) {
        sum += cost[k];
        maxi = max(maxi, sum - godDamnit(i, k - 1));
    }
    return dp[i][j] = maxi;
}

int main() {
    int tc;
    cin >> tc;
    for (int j = 0; j < tc; ++j) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> cost[i];
        }
        memset(isVal, 0, sizeof isVal);
        printf("Case %d: %d\n", j + 1, godDamnit(0, n-1));
    }

    return 0;
}
