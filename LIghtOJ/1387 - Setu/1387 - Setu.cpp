#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, tc = 0;
    scanf("%d", &t);

    while(t--)
    {
        int op;
        scanf("%d", &op);

        long long am = 0;
        printf("Case %d:\n", ++tc);

        for(int i = 0; i < op; i++)
        {
            string inp;
            long long a;

            cin >> inp;
            if(inp[0] == 'd')
            {
                cin >> a;
                am += a;
            }
            else
                cout << am << endl;
        }
    }
    return 0;
}
