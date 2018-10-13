using namespace std;
#include<bits/stdc++.h>


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        vector<pair<ll ,string> >v;
        for(ll i=0; i<n; i++)
        {
            string a;
            cin>>a;
            ll x=ILL,y=ILL,z=ILL;
            v.pb(mp((x*y*z),a));
        }
        sort(all(v));
        if(v[0].first==v[n-1].first)
            pf("Case %lld: no thief\n",cs);
        else{
            pf("Case %lld: ",cs);
            cout<<v[n-1].second<<" took chocolate from "<<v[0].second<<"\n";
        }
    }
    return 0;
}
