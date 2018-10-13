using namespace std;
#include<bits/stdc++.h>

set<ll>S;
db dp[100010];
int main()
{
    dp[0]=0;
    dp[1]=0;
    for(ll i=1; i<=100009; i++)
    {
        S.clear();
        for(ll j=1; j<=((int)sqrt(i)+1); j++)
        {
            if(i%j==0)
            {
                S.insert(j);
                S.insert((i/j));
            }
        }
        if(i>1)
        {
            ll n = S.size();
            db sum= 0.0;
            std::set<ll>::iterator it = S.begin();
            for(ll j=0; j<n-1; j++)
            {
                sum+=dp[*it];
                it++;
            }
            sum+=(db)n;
            dp[i] = (sum/(db)(n-1));
        }
    }
    int t=II;
    int i=1;
    while(t--)
    {
        ll temp=ILL;
        pf("Case %d: %lf\n",i++,dp[temp]);
    }
    return 0;
}
