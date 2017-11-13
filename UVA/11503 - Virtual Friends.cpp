#include <bits/stdc++.h>
using namespace std;
#define MAX 200055

int par[MAX];
int counter[MAX];

void setParent(int n){
    par[n] = n;
    counter[n] = 1;
}

int find(int n){
    if(par[n] == n) return n;
    par[n] = find(par[n]);

    return par[n];
}

int Union(int a, int b)
{
    int u = find(a);
    int v = find(b);

    if(u != v){
        par[v] = u;
        counter[u] = counter[u] + counter[v];
    }

    return counter[par[a]];
}

int main()
{
    int tc;
    string s1, s2;
    scanf("%d", &tc);

    while(tc--){
        int q;
        scanf("%d", &q);
        map<string, int> mp;
        int element = 0;

        while(q--){
            cin >> s1 >> s2;

            if(mp.find(s1) == mp.end()){
                mp.insert(make_pair(s1, ++element));
                setParent(mp[s1]);
            }
            if(mp.find(s2) == mp.end()){
                mp.insert(make_pair(s2, ++element));
                setParent(mp[s2]);
            }

            int a = mp[s1];
            int b = mp[s2];
            int ans = Union(a, b);

            printf("%d\n", ans);
        }
    }
}
