#include <bits/stdc++.h>
using namespace std;

#define inf (1<<30)

int main()
{
    int n, m, k;

    int t;

    cin >> t;

    for(int c = 1; c <= t; c++)
    {
        cin >> n >> m >> k;
        getchar();
        char arr[n][m];

        long long int cost = 0;
        int mini;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                mini = 1000000;
                bool r = false;
                for(int x = 0; x < n; x++)
                {
                    for(int y = 0; y < m; y++)
                    {
                        if(x == i && y == j)
                            break;

                        if(arr[x][y] == arr[i][j])
                        {
                            int p = abs(i - x) + abs(j-y);
                            if(p < mini)
                                mini = p;
                            r = true;
                        }
                    }
                }

                if(r)
                {
                    if(mini >= k)
                        cost += k;
                    else
                        cost += mini;
                }
                else
                    cost += k;
                cout << cost << " ";
            }
        }
        cout << cost << endl;
    }
    return 0;
}

