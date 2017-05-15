#include <bits/stdc++.h>
using namespace std;

int x[9], a, b, level, init[9], moves;
bool place(int queen, int row)
{
    for(int prev = 1; prev <= queen-1; prev++)
    {
        if(x[prev] == row || (abs(x[prev] - row)) == (abs(queen - prev)))
            return false;
    }
    return true;
}

void recur(int queen)
{
    for(int row = 1; row <= 8; row++)
    {
        if(place(queen, row))
        {
            x[queen] = row;

            if(queen == 8)
            {
                int mv = 0;

                for(int i = 1; i <= 8; i++)
                {
                    if(x[i] != init[i])
                        mv++;
                }
                moves = min(mv, moves);
            }
            else
                recur(queen+1);
        }
    }
}
int main()
{
    int st;
    int tc = 1;
    while(scanf("%d", &st) != EOF)
    {
        init[1] = st;

        for(int i = 2; i <= 8; i++)
            scanf("%d", &init[i]);

        moves = 10;
        memset(x, 0, sizeof x);

        recur(1);

        cout << "Case " << tc++ << ": " << moves << endl;
    }
}
 //1 2 3 4 5 6 7 8
