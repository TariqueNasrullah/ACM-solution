#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, tc = 0;
    scanf("%d", &t);

    while(t--)
    {
        int mypos, liftpos;

        scanf("%d %d", &mypos, &liftpos);

        int time = 0;

        int floorTofloor = 4;
        int openorclose = 3;
        int enterout = 5;

        time += (abs(mypos - liftpos) * floorTofloor);
        time += (openorclose + enterout + openorclose);
        time += (mypos * floorTofloor);
        time += (openorclose + enterout);

        printf("Case %d: %d\n", ++tc, time);
    }
    return 0;
}
