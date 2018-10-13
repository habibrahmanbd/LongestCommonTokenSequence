using namespace std;
#include<bits/stdc++.h>

int main()
{
//    cout<<modinverse(21,5);
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        vector<ll> primes(n),rnd(n);
        for(ll i=0; i<n; i++)
            primes[i]=ILL, rnd[i]=ILL;
        pf("Case %lld: %lld\n",cs,chinese_remainder_theorem(primes,rnd));
    }
//    ios_base::sync_with_stdio(false);cin.tie(0);
    return 0;
}
