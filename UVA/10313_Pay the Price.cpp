#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)x.size())

vector<int> parse(string &s)
{
    s += ' ';
    int n = 0;
    vector<int> ret;
    for(char c : s)
        if(c == ' ') ret.push_back(n), n = 0;
        else n = 10*n + c - '0';
    return ret;
}

long long coin_change(int coin[], int make, int n)
{
    long long table[make+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    long long ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = coin[i]; j <= make; j++)
        {
            table[j] = table[j] + table[j-coin[i]];
        }
    return table[make];
}

int main()
{
    int arr[301];
    for(int i = 0; i < 301; i++)
        arr[i] = i+1;
    while(true)
    {
        string line;
        getline(cin, line);
        if(SZ(line) < 1)
            return 0;

        vector<int> v = parse(line);

        if(SZ(v) == 1)
            cout << coin_change(arr, v[0], 300) << "\n";
        if(SZ(v) == 2)
        {
            int coins[v[1]+1];
            for(int i = 0; i < v[1]; i++)
                coins[i] = arr[i];

            cout << coin_change(coins, v[0], v[1]) << "\n";
        }
        if(SZ(v) == 3)
        {
            int a = v[2]-v[1]+1;
            int coins[a+1];
            int x = v[1];
            for(int i = 0; i < a; i++)
            {
                coins[i] = x;
                x++;
            }

            cout << coin_change(coins, v[0], a) << "\n";
        }
    }

    return 0;
}
