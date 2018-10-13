using namespace std;
#include<bits/stdc++.h>

int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL, q=ILL;
        vll arr;
        for(ll i=0; i<n; i++)
        {
            ll temp=ILL;
            arr.pb(temp);
        }
        pf("Case %lld:\n",cs);
        for(ll i=1; i<=q; i++)
        {
            ll start=ILL, stop=ILL;
            ll res1= (ll) (lower_bound(all(arr),start)-arr.begin());
            ll res2= (ll) (upper_bound(all(arr),stop)-arr.begin());
            pf("%lld\n",res2-res1);
        }
    }
    return 0;
}
