#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int brk, supp, din;

    cin >> brk >> din >> supp;

    unsigned long long int tot = brk + din + supp;

    unsigned long long int maxi = 0;

    if(brk >= maxi)
        maxi = brk;
    if(supp >= maxi)
        maxi = supp;
    if(din >= maxi)
        maxi = din;

    unsigned long long int mini = maxi;

    if(brk <= mini)
        mini = brk;
    if(supp <= mini)
        mini = supp;
    if(din <= mini)
        mini = din;

    mini++;

    if(mini >= maxi)
    {
        cout << "0" << endl;
        return 0;
    }

    unsigned long long int maintot = maxi + maxi-1 + maxi-1;

    cout << maxi - mini;

    return 0;
}
