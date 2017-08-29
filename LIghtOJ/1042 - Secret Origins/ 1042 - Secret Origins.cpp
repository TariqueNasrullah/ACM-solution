#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {0, 1, 0};

    if(next_permutation(arr, arr+3))
        for(int i = 0; i < 3; i++)
            cout << arr[i] << " ";
}
