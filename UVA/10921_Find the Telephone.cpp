#include <bits/stdc++.h>
using namespace std;

map<char, int>charset;

int main()
{
    string s;
    char ch;
    int val = 2;
    for(int i = 1; i <=26; i++)
    {
        ch = i+64;
        charset[ch] = val;
        if(i%3 == 0)
            val++;
    }
    charset['S'] = 7;
    charset['V'] = 8;
    charset['Y'] = 9;
    charset['Z'] = 9;

    while(cin >> s )
    {
        for(int i = 0; i < s.size(); i++)
        {
            ch = s[i];
            if(s[i] == '1' || s[i] == '0' || s[i] == '-')
                cout << s[i];
            else
                cout << charset[s[i]];
        }
        cout << endl;
    }
    return 0;
}
