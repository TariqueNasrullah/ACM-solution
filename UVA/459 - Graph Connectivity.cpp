#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int par[MAX];
set<int> st;

void initSet(int n){
    for(int i = 0; i <= n; i++)
        par[i] = i;
}

int find(int n){
    if(par[n] == n) return n;

    par[n] = find(par[n]);

    return par[n];
}

void Union(int a, int b){
    int u = find(a);
    int v = find(b);

    if(u != v) par[v] = u;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int tc;
    string s;
    scanf("%d\n\n", &tc);

    for(int t = 1; t <= tc; t++){
        getline(cin, s);
        //cout << s << endl;
        int lim = s[0] - 'A' + 1;
        initSet(lim);

        while(1){
            if(!getline(cin, s) || s.empty()) break;
            int a = s[0] - 'A' + 1;
            int b = s[1] - 'A' + 1;

            Union(a, b);
        }

        st.clear();

        for(int i = 1; i <= lim; i++){
            //cout << "Parent of " << i << " is " << find(par[i]) << endl;
            st.insert(find(par[i]));
        }

        if(t != 1) cout << endl;
        cout << st.size() << endl;
    }

    return 0;
}
