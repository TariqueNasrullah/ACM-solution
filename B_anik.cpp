#include <bits/stdc++.h>
using namespace std;
#define rep(i,b,s) for(i=b; i<s; i++)

int main (){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int i=0, p=0, r=0, mx=0, flg = 0;
    i=0, p=0;
    while(s[i]){
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'  || s[i]=='Y'){t8r=i;
        if(mx<abs(p-r))mx=abs(p-r);
        p = r;
        i++;
    }

    cout << max(mx,abs(i-r)) << endl;

return 0;}
