using namespace std;
#include<bits/stdc++.h>

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll p=ILL, l=ILL;
        p-=l;
        ll temp = (ll)ceil(sqrt(p));
        vector<ll>res;
        for(ll i=1; i<temp; i++)
        {
            if(p%i==0)
            {
                ll q=(p/i);
                if(l<q)
                    res.pb(q);
                if(l<i)
                    res.pb(i);
            }
        }
        if(temp*temp==p)
        {
            ll q= temp;
            if(l<q)
                res.pb(q);
        }
        sort(all(res));
        if(res.size())
        {
            pf("Case %d: %lld",cs,res[0]);
//            pf("here");
            for(ll i=1; i<res.size(); i++)
                pf(" %lld",res[i]);
            pf("\n");
        }
        else
        {
            pf("Case %d: impossible\n",cs);
        }
    }
    return 0;
}
