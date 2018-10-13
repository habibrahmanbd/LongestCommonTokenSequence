using namespace std;
#include<bits/stdc++.h>

ll dp[16][1<<16];
ll val[16][16];
ll n;
ll solve(int pos, int mask)
{
    if(pos>=n)
        return 0;
    if(dp[pos][mask]==(ll)-1)
    {
        for(int i=0; i<n; i++)
        {
            if(!(mask&(1<<i)))
                dp[pos][mask]=max(dp[pos][mask],val[pos][i]+solve(pos+1, mask|(1<<i)));
        }
    }
    return dp[pos][mask];
}
int main()
{
    ll t=ILL;
    for(ll i=1; i<=t; i++)
    {
        memset(dp, -1, sizeof(dp));
//        memset(val, 0, sizeof val);
        n=ILL;
        for(ll j=0; j<n; j++)
            for(ll k=0; k<n; k++)
                val[j][k]=II;

        ll res=solve(0,0);
        pf("Case %lld: %lld\n",i,res);
    }
    return 0;
}
