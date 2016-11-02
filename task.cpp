#include <bits/stdc++.h>
using namespace std;

class calc
{
    int r1, r2;
    int ans = 0;
public:
    void sum(){
        for(int i = r1; i <= r2; i++){
            if(i%2 != 0){
                ans += i;
            }
        }
    }

    void setvalue(int a, int b){
        r1 = a;
        r2 = b;
    }

    void printAns()
    {
        cout << "Answer is : " << ans << endl;
    }
};

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        int a, b;
        calc obj1;
        cout << "Enter 2 Values: ";
        cin >> a >> b;

        obj1.setvalue(a, b);
        obj1.sum();
        obj1.printAns();
    }


    return 0;
}
