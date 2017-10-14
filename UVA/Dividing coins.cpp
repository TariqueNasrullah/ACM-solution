#include <bits/stdc++.h>
using namespace std;
int n;
int coin[101];
int sum;
/*
int recur(int i, int s)
{
    if(s == 0)
        return 0;
    if(i >= n) return 0;

    if(coin[i] > s)
      return recur(i+1, s);
    return max(recur(i+1, s), coin[i] + recur(i+1, s - coin[i]));
}
*/
int table[25000+5];

int knapSack(int n, int s)
{
    for(int i = 0; i <= s; i++) table[i] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = s; j > 0; j--)
        {
            if(coin[i] <= j) table[j] = max(table[j], coin[i] + table[j - coin[i]]);
        }
    }
    return table[s];
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int tc;
    cin >>tc;

    while(tc--)
    {
        cin >>n;
        sum = 0;

        for(int i = 1; i <= n; i++)
        {
            cin >>coin[i];
            sum += coin[i];
        }
        cout << sum - (2*knapSack(n, sum/2)) << endl;
    }
    return 0;
}
