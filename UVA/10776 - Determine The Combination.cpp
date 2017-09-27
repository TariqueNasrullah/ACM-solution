#include <bits/stdc++.h>
using namespace std;

#define MAX 100

char str[100];
int sz, n;
bool isTaken[MAX];
vector<char> v;

void gen();

int main()
{
    while(scanf("%s %d", str, &sz) == 2)
    {
        memset(isTaken, false, sizeof(isTaken));
        n = strlen(str);
        v.clear();
        sort(str, str+n);

        gen();
    }
}

void gen()
{
    if(v.size() == sz)
    {
        for(int i = 0; i < sz; i++)
            printf("%c", v[i]);
        printf("\n");

        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(v.size() > 0 && v[v.size()-1] > str[i]) continue;

        if(isTaken[i] == false)
        {
            isTaken[i] = true;
            v.push_back(str[i]);

            gen();

            isTaken[i] = false;
            v.pop_back();

            while(i+1 < n && str[i] == str[i+1]) i++;
        }
    }
}
