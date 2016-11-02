#include <bits/stdc++.h>
using namespace std;

int bargars[] = {3, 6};
int totTime;
int solve(int i, int time)
{
    if(time == 0)
        return 1;
    if(time < 0)
        return 0;
    int r1 = 0; int r2 = 0;
    r1 =  solve(i, time-bargars[i]) + solve((i==0)? 1:0, time-bargars[i]);
    r2 = solve((i==0)? 1:0, time);

    return max(r1, r2);
}

int main()
{
    totTime = 9;
    cout << solve(0, totTime) << endl;
}
