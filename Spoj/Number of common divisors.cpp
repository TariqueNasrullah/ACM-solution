#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;

    return gcd(b, a%b);
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);

        int g = gcd(a, b);

        int cnt = 0;

        int i = 0;
        for(i = 1; i*i <= g; i++)
            if(g%i == 0) cnt += 2;

        i -= 1;
        if(i*i == g)
            cnt--;

        printf("%d\n", cnt);
    }
    return 0;
}
