using namespace std;
#include<bits/stdc++.h>

ll r1,c1,r2,c2;
ll solve()
{
    ll a = (r1+c1)&1, b=(r2+c2)&1;
    if(a!=b)
        return -1;
    if(abs(r1-r2)==abs(c1-c2))
        return 1;
    return 2;
}
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        r1=ILL, c1=ILL, r2=ILL,c2=ILL;
        pf("Case %lld: ",cs);
        ll res=solve();
        if(res<0)
            pf("impossible\n");
        else pf("%lld\n",res);
    }
    return 0;
}
