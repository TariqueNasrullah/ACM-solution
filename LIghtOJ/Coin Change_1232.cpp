#include <bits/stdc++.h>
using namespace std;

long long coin_change(int coin[], int make, int n)
{
    long long table[make+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    long long ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = coin[i]; j <= make; j++)
        {
            table[j] = table[j]%100000007 + table[j-coin[i]]%100000007;
        }
    return table[make];
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        int n, make;
        cin >> n >> make;
        int coin[n+1];

        for(int j = 0; j < n; j++)
            cin >> coin[j];
        cout << "Case " << i << ": " << coin_change(coin, make, n)%100000007 << endl;
    }

    return 0;
}
