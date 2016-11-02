#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    ifstream in("in.txt");
    ofstream out("out.txt");

    while(cin >> n)
    {
        int totalBottle = n;
        int emptyBottle = n;
        int loan = 0;
        while(emptyBottle != 1)
        {
            if(emptyBottle%3 == 2 && loan == 0)
            {
                emptyBottle++;
                loan = 1;
            }

            totalBottle += (int)emptyBottle/3;

            emptyBottle = (emptyBottle/3) + (emptyBottle%3);
            if(emptyBottle == 2 && loan == 1)
                break;
        }

        cout << totalBottle << endl;
    }
}
