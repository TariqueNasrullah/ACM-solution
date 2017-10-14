#include <bits/stdc++.h>
using namespace std;
#define M 1000005

int arr[M];
int qSum[M];

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    qSum[0] = 0;
    int t, n, q;
    int a, b, c;
    long long ans;
    //scanf("%d", &t);
    in >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        //scanf("%d %d", &n, &q);
        in >> n >> q;
        for(int i = 1; i <= n; i++){
            //scanf("%d", &arr[i]);
            in >> arr[i];
            qSum[i] = arr[i] + qSum[i-1];
        }
        ans = 0;

        for(int i = 1; i <= n; i++)
            ans += (arr[i]*(n-i)) - (qSum[n] - qSum[i]);

        //printf("Case %d:\n", tc);
        out << "Case " << tc << ":" << endl;

        while(q--)
        {
            //scanf("%d", &a);
            in >> a;
            if(a == 1) out << ans << endl;

            else
            {
                //scanf("%d %d", &b, &c);
                in >> b >> c;
                b = b+1;
                    ans -= arr[b]* (n-b);
                    ans += c*(n-b);
                    ans += (b-1)*arr[b];
                    ans -= (b-1)*c;
                arr[b] = c;
            }
        }
    }
    return 0;
}
