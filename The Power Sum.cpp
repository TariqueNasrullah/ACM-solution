#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

int ans;
int make;
int sz;
int k;

int recur(int i, int amount)
{

    if(i >= sz)
    {
        if(amount == make)
        {
            ans++;
            return 1;
        }
        else
            return 0;
    }

    int ret1 = 0, ret2 = 0;
    if(pow(arr[i], k) + amount <= make) ret1 = recur(i+1, amount + pow(arr[i], k));
    ret2 = recur(i+1, amount);

    return ret1 | ret2;
}

int main()
{
    int n;
    cin >> n >> k;

    make = n;
    
    for(int i = 1; i <= sqrt(n); i++)
        arr.push_back(i);

    sz = arr.size();

    if(recur(0, 0))
        cout << ans << endl;
    else
        cout << "0" << endl;

    return 0;
}
