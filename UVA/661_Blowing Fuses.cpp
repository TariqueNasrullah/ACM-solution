#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, c;
    //ifstream in("in.txt");
    //ofstream out("out.txt");
    int seq = 1;
    while(cin >>  n >> m >> c, n||m||c)
    {
        int device[n+1];

        for(int i = 1; i <= n; i++)
        {
            int amp;
            cin >>  amp;
            device[i] = amp;
        }

        int absoved = 0;
        bool state[n+1];
        for(int i = 0; i < n+1; i++)
            state[i] = false;
        int maxi = 0;
        while(m--)
        {
            int whichDevice;
            cin >>  whichDevice;

            state[whichDevice] = !state[whichDevice];

            if(state[whichDevice])
            {
                absoved += device[whichDevice];
            }
            else
            {
                absoved -= device[whichDevice];
            }

            if(absoved > maxi)
                maxi = absoved;
        }
        cout <<  "Sequence " << seq << endl;

        seq++;

        if(maxi > c)
            cout <<  "Fuse was blown." << endl;
        else
        {
            cout <<  "Fuse was not blown." << endl;
            printf("Maximal power consumption was %d amperes.\n", maxi);
        }
        cout <<  endl;
    }

    return 0;
}
