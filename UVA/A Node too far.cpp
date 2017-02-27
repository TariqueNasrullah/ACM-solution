#include <bits/stdc++.h>
using namespace std;

#define MAX 100
vector<int> edges[MAX];
//vector<int> cost[MAX];
int visited[MAX];
int level[MAX];

void bfs(int s);

int main()
{
	int v, e, source, dest;
	int tc = 1;
	while(1)
    {
        cin >> e;
        if(e == 0)
            return 0;

        map<int, int>mymap;
        int c = 1;
        for(int i = 0; i < e; i++)
        {
            int u, v, a, b;
            cin >> a >> b;
            if(mymap.find(a) == mymap.end())
                mymap[a] = c++;
            if(mymap.find(b) == mymap.end())
                mymap[b] = c++;
            u = mymap[a];
            v = mymap[b];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        while(1)
        {
            int source, cost;
            cin >> source >> cost;
            if(source == 0 && cost == 0)
                break;
            int mainSource = source;
            //source = mymap[source];

            if(mymap.find(source) != mymap.end())
                source = mymap[source];
            else
            {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", tc++, mymap.size(), mainSource, cost);
                continue;
            }
            memset(visited, 0, sizeof(visited));
            memset(level, 0, sizeof(level));

            bfs(source);
            int ans = 0;
            int p = 0;
            for(int i = 1; i <= mymap.size(); i++)
            {
                if(level[i] > cost)
                    ans++;
                if(visited[i] == 0)
                    p++;
            }
            ans += p;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", tc++, ans, mainSource, cost);
        }
        mymap.clear();

        for(int i = 0; i < MAX; i++)
            edges[i].clear();
    }
    return 0;
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	level[s] = 0;
	visited[s] = 1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(unsigned int i = 0; i < edges[u].size(); i++)
		{
			int v = edges[u][i];

			if(visited[v] == 0)
			{
				visited[v] = 1;
				q.push(v);
				level[v] = level[u] + 1;
			}
		}
	}
}
