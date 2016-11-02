#include <bits/stdc++.h>
using namespace std;

int winOrLose(int node)
{
    if(adj[node] == 0)  //
        return state[node] = 0;

    //call next nodes where I can go
    state[node] = 0;
    for(int i = 1; j <= nodesIcanGO; i++)
    {
        //state[node] = winOrLose(adjacent nodes);
        int a = winOrLose(adjacent_nodes);
        if(a == 0)
            state[node] = 1;
    }
    return state[node];
}
