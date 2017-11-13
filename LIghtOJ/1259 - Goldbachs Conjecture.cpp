#include <bits/stdc++.h>
using namespace std;

#define M 10000000

bool marked[M];
int bitPrime[M/64 + 2];

#define on(x) (bitPrime[x/64] & (1<<((x%64)/2)))
#define mark(x)  bitPrime[x/64] |= (1<<((x%64)/2))

/*
====== Normal Sieve ========= */
void sieve(int n){
    for(int i = 3; i*i < n; i += 2){
        if(marked[i] == false) { // i is a prime
            for(int j = i*i ; j <= n; j += i + i){
                marked[j] = true;
            }
        }
    }
}

bool isPrime(int n)
{
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(!(n&1)) return false;
    return marked[n] == false;
}

/* =========== Bit Wise Sieve =============== */

void bitSieve(int n){
    for(int i = 3; i*i <= n; i += 2){
        if(!on(i)){
            for(int j = i*i; j <= n; j+= i + i){
                mark(j);
            }
        }
    }
}

bool isBitPrime(int num)
{
    //if(num <= 0) return false;
    return num > 1 && (num == 2 || ( (num&1) && !on(num)));
}

int main()
{
    cin.tie(NULL);

    bitSieve(10000005);
//    for(int i = 5000000; i <= 6000000; i++)
//        if(isBitPrime(i)) cout << i << " ";
////    for(int i = 2; i <= 100 ; i++)
////        if(isBitPrime(i)) cout << i << " ";

    int tc, t, n, cnt;
    cin >> t;

    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        cnt = 0;
        int temp = n;
        int up = n/2 + 1;
        for(int i = 2; i <= up; i++){
            if(isBitPrime(i) && isBitPrime(n-i)) cnt++;
        }

        printf("Case %d: %d\n", tc, cnt);
    }
    return 0;
}
