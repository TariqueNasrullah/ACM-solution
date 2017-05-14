#include <bits/stdc++.h>
using namespace std;

int arr[8], row, column;
int x[9], a, b, lineCounter, TC;
bool place(int queen, int row)
{
    for(int prev = 1; prev <= queen-1; prev++)
    {
        if(x[prev] == row || (abs(x[prev]-row)) == abs(prev-queen))
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

            if(queen == 8 && x[b] == a)
            {
                printf("%2d      %d", ++lineCounter, x[1]);
                for(int j = 2; j <= 8; j++)
                    printf(" %d", x[j]);
                printf("\n");
            }
            else
                recur(queen+1);
        }
    }
}
int main()
{
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &a, &b);
        memset(x, 0, sizeof x);
        lineCounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        recur(1);
        if(TC) printf("\n");
    }
    return 0;
}
