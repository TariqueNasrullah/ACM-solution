#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    for (int i = 1;; i++)
    {
        int d = (i * (i + 1)) / 2;
        if (d > str.length())
            break;
        cout << str[d - 1];
    }
    cout << endl;

    return 0;
}