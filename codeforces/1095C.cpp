#include <bits/stdc++.h>
using namespace std;

vector<int> toBin(int n)
{
    int cnt = 0;
    vector<int> retVector;

    while (n != 0)
    {
        int rem = n % 2;
        if (rem)
            retVector.push_back(pow(2, cnt));

        cnt++;
        n /= 2;
    }

    return retVector;
}

void printRes()
{
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> vecRes = toBin(n);

    int minPossibleK = vecRes.size();
    int maxPossibleK = n;
    int currentK = minPossibleK;

    if (k < minPossibleK || k > maxPossibleK)
    {
        printf("NO\n");
        return 0;
    }
    else
        printf("YES\n");

    queue<int> divisionPossible, divisionImpossible;

    for (int i = 0; i < vecRes.size(); i++)
    {
        if (vecRes[i] == 1)
            divisionImpossible.push(vecRes[i]);
        else
            divisionPossible.push(vecRes[i]);
    }

    while (currentK != k)
    {
        int temp = divisionPossible.front();
        divisionPossible.pop();

        temp /= 2;

        if (temp == 1)
        {
            divisionImpossible.push(temp);
            divisionImpossible.push(temp);
        }
        else
        {
            divisionPossible.push(temp);
            divisionPossible.push(temp);
        }

        currentK++;
    }

    while (!divisionImpossible.empty())
    {
        printf("%d ", divisionImpossible.front());
        divisionImpossible.pop();
    }
    while (!divisionPossible.empty())
    {
        printf("%d ", divisionPossible.front());
        divisionPossible.pop();
    }

    cout << endl;
}