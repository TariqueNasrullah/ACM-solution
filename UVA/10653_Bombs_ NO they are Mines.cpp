#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int row, col;
int cell[1001][1001];
int vis[1001][1001];
int d[1001][1001];

void bfs(int sx, int sy)
{
    vis[sx][sy] = 1;
    queue<pii>q;

    q.push(pii(sx, sy));

    while(!q.empty())
    {
        pii top = q.front(); q.pop();

        for(int k = 0; k < 4; k++)
        {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if(tx >= 0 && tx < row && ty >= 0 && ty < col && cell[tx][ty] != -1 && vis[tx][ty] == 0)
            {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }
}
int main()
{
    while(scanf("%d %d", &row, &col))
    {
        if(row == 0 && col == 0)
            break;

        int b;
        scanf("%d", &b);

        for(int i = 0; i < b; i++)
        {
            int c, totc;
            scanf("%d %d", &c, &totc);

            for(int j = 0; j < totc; j++)
            {
                int r;
                scanf("%d", &r);
                cell[c][r] = -1;
            }
        }
        int s1, s2, dest1, dest2;
        scanf("%d %d", &s1, &s2);
        scanf("%d %d", &dest1, &dest2);

        bfs(s1, s2);

        printf("%d\n", d[dest1][dest2]);

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cell[i][j] = 0;
                d[i][j] = 0;
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}
