#include <bits/stdc++.h>
using namespace std;
#define MAX 200005

int par[MAX];

void initSet(int n){
    for(int i = 0; i <= n; i++) par[i] = i;
}

int find(int a){
    if(par[a] == a) return a;
    par[a] = find(par[a]);

    return par[a];
}

void Union(int a, int b){
    int u = find(a);
    int v = find(b);

    if(u != v)
        par[v] = u;
}

int main()
{
    int tc, a, b, data;
    char ch;
    string s;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; t++){
        scanf("\n%d\n", &data);
        initSet(data+1);

        int success = 0, unsuccess = 0;

        while(1){
            if(!getline(cin, s) || s.empty()) break;
            sscanf(s.c_str(), "%c %d %d", &ch, &a, &b);

            if(ch == 'c')
                Union(a, b);
            else
                find(a) == find(b) ? success++ : unsuccess++;
        }

        if(t != 1)
            printf("\n");
        printf("%d,%d\n", success, unsuccess);
    }

    return 0;
}
