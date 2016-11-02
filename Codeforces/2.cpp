#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;

    cin >> n >> d;

    int days[n+1];

    for(int i = 0; i < n; i++)
        cin >> days[i];

    int addi = 0;

    for(int i = 1; i < n; i++)
    {
        if(abs(days[i]+days[i-1] < d))
        {
            int t = d - (days[i]+days[i-1]);
            days[i] += t;
            addi += t;
        }
    }

    cout << addi << endl;

    for(int i = 0; i < n; i++)
        cout << days[i] << " ";
}
