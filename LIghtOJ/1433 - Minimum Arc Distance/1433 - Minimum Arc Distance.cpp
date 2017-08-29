#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)

int main()
{
    int t, tc=0;
    double ox, oy, ax, ay, bx, by;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &ox, &oy, &ax, &ay, &bx, &by);

        double squareR, R, squareAB;
        squareAB = (ax - bx)*(ax - bx) + (ay - by)*(ay - by);

        squareR = (ox - ax)*(ox - ax) + (oy - ay)*(oy - ay);
        R = sqrt(squareR);

        double angle;
        angle = acos(1 - 0.5* (squareAB/squareR));
        double arc = angle * R;

        printf("Case %d: %0.8lf\n", ++tc, arc);
    }

    return 0;
}
