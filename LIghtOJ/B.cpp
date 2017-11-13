#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXI = 1e6 + 7;
long int a[MAXI],qm[MAXI], n, k, maxi;

int main()
{
    scanf("%ld%ld",&n,&k);

    for(int i = 0; i < n; i++){
        scanf("%ld",a + i);
        maxi = max(maxi,a[i]);
    }


    for(int i = 0; i < n; i++)
    {
        int cnt = 0,fg = 0;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
                cnt++;
            else
            {
                fg = 1;
                break;
            }
        }
        if(!fg)
        {
            for(int k = 0; k < i; k++){
                if(a[i] > a[k])
                    cnt++;
                else
                    break;
            }
        }
        qm[i] = cnt;
    }

    for(int i = 0; i < n; i++){
        if(qm[i] >= k){
            cout << a[i] << endl;
            return 0;
        }
    }


    cout << maxi << endl;

    return 0;
}
