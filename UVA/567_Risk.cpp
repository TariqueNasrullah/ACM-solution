#include <bits/stdc++.h>
using namespace std;

#define MAX 25

vector<int> edges[MAX];
int visited[MAX];
int level[MAX];

void bfs(int s);

int main()
{
    int c = 1;
    int u = 1;
    int eNum;

    while(scanf("%d", &eNum) != EOF)
    {
        for(int j = 0; j < eNum; j++)
        {
            int v;
            scanf("%d", &v);

            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        if(u == 19)
        {
            int q;
            scanf("%d", &q);

            printf("Test Set #%d\n", c++);
            for(int i = 0; i < q; i++)
            {
                int source, dest;
                scanf("%d %d", &source, &dest);
                memset(visited, 0, sizeof(visited));
                memset(level, 0, sizeof(level));

                bfs(source);

                printf("%2d to %2d: %d\n", source, dest, level[dest]);
            }
            printf("\n");
            u = 0;
            for(int i = 0; i < MAX; i++)
                edges[i].clear();
        }

        u++;
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    level[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < edges[u].size(); i++)
        {
            int v = edges[u][i];

            if(visited[v] == 0)
            {
                visited[v] = 1;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
}
