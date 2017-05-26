#include <bits/stdc++.h>
using namespace std;

void binary(int n)
{
    stack<int> i;
    while(n != 0)
    {
        i.push(n%2);
        n/=2;
    }

    while(!i.empty())
    {
        int j = i.top();
        i.pop();
        cout << j << " ";
    }
    cout << endl;
}
int main()
{
    binary(14232);
    binary(14241);
}
