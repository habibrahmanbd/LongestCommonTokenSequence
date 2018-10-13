using namespace std;
#include<bits/stdc++.h>
int main()
{
    ll t=ILL;
    for(ll i=1; i<=t; i++)
    {
        ll q=ILL;
        ll low=0;
        ll high=LONG_LONG_MAX,res=LONG_LONG_MAX;
        while(low<=high)
        {
            ll mid = (low+high)/2;
            ll cnt_z=get(mid);
            if(cnt_z>=q)
            {
                high=mid-1;
                if(cnt_z==q)
                    res=min(res,mid);
            }
            else
                low=mid+1;
        }
        if(res!=LONG_LONG_MAX)
            pf("Case %lld: %lld\n",i,res);
        else
            pf("Case %lld: impossible\n",i);
    }
    return 0;
}
