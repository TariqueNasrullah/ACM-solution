#include <bits/stdc++.h>
using namespace std;

int main()
{
    int column;
    scanf("%d", &column);

    int left[column+1];
    int right[column+1];
    long long l = 0, r = 0;
    long long maximumPossible = 0;
    int maximumDistance = 0;
    int minimumPossible = 0;
    int swapIndex = 0;
    for(int i = 0; i < column; i++)
    {
        scanf("%d", &left[i]);
        scanf("%d", &right[i]);
        l += left[i];
        r +=  right[i];
    }
    minimumPossible = abs(l-r);
    maximumPossible = minimumPossible;

        for(int i = 0; i < column; i++)
        {
            long long a , b;
            a = l-left[i]+right[i];
            b = r-right[i]+left[i];
            if(abs(a-b) > maximumPossible)
            {
                maximumPossible = abs(a-b);
                swapIndex = i+1;
            }
        }

        if(maximumPossible > minimumPossible)
            cout << swapIndex << endl;
        else
            cout << "0" << endl;


    return 0;
}
