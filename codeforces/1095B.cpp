#include <bits/stdc++.h>
using namespace std;

#define inf 1e9 + 7

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max1 = max(arr[0], arr[1]);
    int max2 = min(arr[0], arr[1]);

    int min1 = max2;
    int min2 = max1;

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max2 = arr[i];
        }

        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2)
        {
            min2 = arr[i];
        }
    }

    int best = abs(max1 - min1);

    best = min(abs(max2 - min1), best);
    best = min(abs(max1 - min2), best);

    cout << best << endl;

    return 0;
}