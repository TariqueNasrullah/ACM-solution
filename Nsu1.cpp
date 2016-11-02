#include <bits/stdc++.h>
using namespace std;

int recus(int node)
{
    if(edges[node].size() == 0)
        return 0;
    if(dp[node] != -1)
        return dp[node];
    int res = 0;

    for(int i = 0; i < edges[node].size(); i++)
    {
        int nxt_node = edges[node][i];
        int n_res = recus(nxt_node);
        if(n_res == 0) res = 1;

    }
    return dp[node] = res;
}
