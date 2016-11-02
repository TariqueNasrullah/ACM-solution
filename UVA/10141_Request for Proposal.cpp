#include <bits/stdc++.h>
using namespace std;

int main()
{
    string requireString, proposalString, metrequiremtString;
    int proposal , requirements, metrequirement;
    double price;

    multimap<int, string> multimp;
    pair <multimap<int,string>::iterator, multimap<int, string>::iterator> ret;
    map<string, double> priceofProposal;
    set<int> r;
    set<int>::iterator setit;

    while(1)
    {
        cin >> requirements >> proposal;
        if(requirements == 0 && proposal == 0)
            return 0;
        getchar();
        for(int i = 0; i < requirements; i++)
        {
            getline(cin, requireString);
        }

        //cout << "stopped" << endl;

        for(int i = 0; i < proposal; i++)
        {
            getline(cin, proposalString);
            //cout << proposalString << endl;
            cin >> price;
            //cout << price << endl;

            cin >> metrequirement;
            //cout << metrequirement << endl;
            r.insert(metrequirement);

            //multimp[metrequirement] = proposalString;
            multimp.insert(pair<int, string>(metrequirement, proposalString));
            priceofProposal[proposalString] = price;

            getchar();

            for(int j = 0; j < metrequirement; j++)
            {
                getline(cin, metrequiremtString);
                //cout << metrequiremtString << endl;
            }
        }

        int maxi = 0;
        for(setit = r.begin(); setit != r.end(); ++setit)
        {
            if(*setit > maxi)
                maxi = *setit;
        }

        ret = multimp.equal_range(maxi);

        multimap<int, string>::iterator it;
        it = ret.first;
        string ans = it->second;
        double mini = priceofProposal[it->second];
        for(it = ret.first; it != ret.second; ++it)
        {
            if(priceofProposal[it->second] < mini)
            {
                mini = priceofProposal[it->second];
                ans = it->second;
            }
        }

        cout << ans << endl;

        multimp.clear();
        r.clear();
        priceofProposal.clear();
    }

    return 0;
}
