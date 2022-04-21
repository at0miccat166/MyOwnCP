/*    
 *     @Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

ll a, b;

void sieve(ll L, ll R){
    bool prime[R - L + 1];
    memset(prime, true, sizeof(prime));
    for (ll i = 2; i <= (ll) sqrt(R); i++)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            prime[j - L] = false;

    if (L == 1) prime[0] = false;
    
    int cnt = 0;
    for (ll i = L; i <= R; i++)
        if (prime[i]) cnt++;
    cout << cnt << "\n";
}

int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    sieve(a, b);
       
    return 0;
}
