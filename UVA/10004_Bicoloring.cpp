#include <bits/stdc++.h>
using namespace std;

#define MAX 205
vector<int> edges[MAX];
int level[MAX];
int visited[MAX];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    level[s] = 1;

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
                q.push(v);
                level[v] = level[u]+1;
            }
        }
    }
}

bool color(int n)
{
    for(int i = 0; i < n; i++)
    {
        int l = level[i];

        if(l%2 == 0)
        {
            for(int j = 0; j < edges[i].size(); j++)
            {
                if(level[edges[i][j]]%2 == 0)
                    return false;
            }
        }
        else if(l%2 != 0)
        {
            for(int j = 0; j < edges[i].size(); j++)
            {
                if(level[edges[i][j]]%2 != 0)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    while(1)
    {
        for(int i = 0; i < MAX; i++)
            edges[i].clear();

        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));

        int n, e;
        scanf("%d %d", &n, &e);
        if(n == 0)
            break;

        for(int i = 0; i < e; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);

            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        bfs(0);
        if(color(n))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }

    return 0;
}
