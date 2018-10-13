using namespace std;
#include<bits/stdc++.h>
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll n=ILL, k=ILL, M=ILL;
        ll sum=0;
        for(int i=1; i<=n; i++)
            sum=(sum+ILL)%M;
        ll ans = bigmod(n,k-1,M);
        ans=(ans*sum*k)%M;
        pf("Case %d: %lld\n",cs, ans);
    }
    return 0;
}
