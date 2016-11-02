#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a;
    cin >> k >> a;

    if(k == a)
    {
        cout << "1" << endl;
        return 0;
    }
    for(int i = 1; ; i++)
    {
        long long int rem;
        rem = (k*i);
        rem = rem % 10;
        if(rem == 0)
        {
            cout << i << endl;
            break;
        }
        if(rem == a)
        {
            cout << i << endl;
            break;
        }

    }
    return 0;
}
