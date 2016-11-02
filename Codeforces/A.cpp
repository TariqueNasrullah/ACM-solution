#include <bits/stdc++.h>
using namespace std;
bool vowel(char a)
{
    if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'||a == 'Y')
        return true;
    else
        return false;
}
int main()
{
    string s;

    cin >> s;
    int length = s.size();
    char a;
    int max = 0;
    int jump = 0;
    int nonVowel = 0;
    for(int i = 0; i < length; i++)
    {
        if(vowel(s[i]))
        {
            jump = 0;
            for(int j = i+1; j <= length; j++)
            {
                jump++;
                if(j == length+1)
                    break;
                if(vowel(s[j]))
                {
                    i = j-1;
                    break;
                }
            }
            if(jump > max)
                max = jump;
        }
        if(max == 0)
        {
            nonVowel++;
        }
    }

    if(max == 0)
        cout << nonVowel+1 << endl;

    else if(nonVowel+1 > max)
        cout << nonVowel+1 << endl;
    else
        cout << max << endl;
    return 0;
}
