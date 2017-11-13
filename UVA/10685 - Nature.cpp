#include <bits/stdc++.h>
using namespace std;
#define MAX 6000

int par[MAX];
int arr[MAX];
string str;


void initSet(int n){
    for(int i = 0; i <= n; i++){
        par[i] = i;
        arr[i] = 0;
    }
}

int find(int n){
    if(par[n] == n) return n;

    par[n] = find(par[n]);

    return par[n];
}

int findLen(int n){
    if(par[n] == n) return 1;

    else return 1 + find(par[n]);
}

void Union(int a, int b){
    int u = find(par[a]);
    int v = find(par[b]);

    if(u != v) par[u] = v;
}
int main()
{
    int n, r;

    while(true){
        cin >> n >> r;

        if(n == 0 && r == 0) break;

        map<string, int> mpStoI;
        initSet(n+1);
        int cnt = 1;
        for(int i = 1; i <= n; i++){
            cin >> str;
            mpStoI.insert(make_pair(str, i));
        }

        string s1, s2;
        for(int i = 0; i < r; i++){
            cin >> s1;
            cin >> s2;

            int a = mpStoI[s1];
            int b = mpStoI[s2];
            cout << a << " " << b << endl;

            Union(a, b);
        }

        int maXi = INT_MIN;
        for(int i = 1; i <= n; i++){
            int p = find(par[i]);
            arr[p]++;

            maXi = max(maXi, arr[p]);
        }

        cout << maXi << endl;
    }

    return 0;
}
