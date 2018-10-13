using namespace std;
#include<bits/stdc++.h>
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll a=ILL,b=ILL;
        ll res=b;
        res-=((b-1)/3)+1;
        if(a>1)
            res+=((a-2)/3)+1;
        res-=(a-1);
        pf("Case %lld: %lld\n",cs,res);
    }
    return 0;
}
