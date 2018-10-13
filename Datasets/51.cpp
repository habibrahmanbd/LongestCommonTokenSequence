using namespace std;
#include<bits/stdc++.h>



int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II, k=II;
        ll w[10005]={0};
        w[0]=1;
        int val[102];
        for(int i=1; i<=n; i++)
            val[i]=II;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=k; j++)
            {
                if(val[i]<=j)
                    w[j]=w[j]+w[j-val[i]];
                if(w[j]>mod)
                    w[j]=w[j]%mod;
            }
        }
        pf("Case %d: %lld\n",cs,w[k]);
    }
    return 0;
}
