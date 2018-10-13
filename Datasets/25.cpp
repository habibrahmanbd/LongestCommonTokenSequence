using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL,m=ILL;
        vector<ll>v;
        for(ll i=0; i<n; i++)
        {
            ll temp=ILL;
            v.pb(temp);
        }
        for(ll i=0; i<m; i++)
        {
            char q;
            cin>>q;
            if(q=='S')
            {
                ll d=ILL;
                for(ll j=0; j<n; j++)
                    v[j]+=d;
            }
            else if(q=='M')
            {
                ll d=ILL;
                for(ll j=0; j<n; j++)
                    v[j]*=d;
            }
            else if(q=='D')
            {
                ll d=ILL;
                for(ll j=0; j<n; j++)
                    v[j]/=d;
            }
            else if(q=='R')
            {
                reverse(all(v));
            }
            else if(q=='P')
            {
                ll y=ILL,z=ILL;
                swap(v[y],v[z]);
            }
        }
        pf("Case %lld:\n",cs);
        for(ll j=0; j<n-1; j++)
            pf("%lld ",v[j]);
        pf("%lld\n",v[n-1]);
    }
    return 0;
}
