#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 7;
int vis[M],dtim[M],ftim[M];
vector < int > g[M];
int treeEdge,backEdge,forEdge,crossEdge, tim;

void dfs(int s)
{
    vis[s] = 1;
    tim++;
    dtim[s] = tim;

    for(int i = 0; i < g[s].size(); i++){
        int v = g[s][i];
        if(vis[v] == 0){
            treeEdge++;
            dfs(v);
        }
        else if(vis[v] == 1)
            backEdge++;
        else if(vis[v] == 2 && dtim[s] < dtim[v])
            forEdge++;
        else if(vis[v] == 2 && dtim[s] > dtim[v])
            crossEdge++;
    }
    vis[s] = 2;
    tim++;
    ftim[s] = tim;
}

int main()
{
    cout << "Enter node and Edge Number: ";
    int n,e;
    cin >> n >> e;

    cout << "Enter Edges: \n";

    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        //g[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
    cout << "starting time and finishing time\n";
    for(int i = 0; i < n; i++){
        cout << dtim[i] << " " << ftim[i] << endl;
    }

    printf("tree edge : %d\n",treeEdge);
    printf("back edge : %d\n",backEdge);
    printf("forward edge : %d\n",forEdge);
    printf("cross edge : %d\n",crossEdge);

    return 0;
}
